# 입출력 스트림과 파일 입출력

## 문자 스트림 (-Reader/Writer)

- Reader/Writer
- InputStreamReader / OutputStreamWriter
- FileReader/FileWriter
  - 텍스트 파일에서 문자 데이터 입출력

### FileReader을 이용한 파일 읽기

```Java
try {
  FileReader fin = new FileReader("C:\\test.txt");
  int c;
  while ((c = fin.read()) != -1) { // -1 when eof
    System.out.println((char) c);
  }
  fin.close();
} catch (IOException e) {
  System.out.println("입출력 오류");
}
```

### InputStreamReader을 이용한 텍스트 파일 읽기

- MS949: 한글 완성형 확장형 문자 집합

```Java
try {
  FileInputStream fin = new FileInputStream("C:\\Temp\\hangul.txt");
  InputStreamReader isr = new InputStreamReader(fin, "MS949");
  while ((c = in.read()) != -1) {
    System.out.println((char) c);
  }
  isr.close();
  fin.close();
} catch (IOException e) {
  System.out.println("파일 입출력 오류");
}
```

### FileWriter

- 문자 단위 쓰기

```Java
FileWriter fout = new FileWriter("C:\\Temp\\test.txt");
fout.write('A');
fout.close();
```

- 블록 단위 쓰기

```Java
char[] buf = new char[1024];
fout.write(buf, 0, buf.length);
```

- 예제 (키보드 입력을 파일로 저장)

```Java
Scanner sc = new Scanner(System.in);
FileWriter fout = null;
int c;
try {
  fout = new FileWriter("c:\\Temp\\test.txt");
  while(true) {
    String line = sc.nextLine();
    if(line.length() == 0)
      break;
    fout.write(line, 0, line.length());
    fout.write("\r\n", 0, 2);
  }
  fout.close();
} catch (IOException e) {
  System.out.println("입출력 오류");
}
sc.close();
```

## 바이트 스트림 (-Stream)

- InputStream/OutputStream
  - 추상 클래스 (바이트 스트림을 다루는 모든 클래스의 슈퍼 클래스)
- FileInputStream/FileOutputStream
  - 파일로부터 바이트 단위로 읽거나 저장
  - 바이너리 파일의 입출력
- DataInputStream/DataOutputStream
  - 자바의 기본 **데이터 타입의 값(변수)**을 바이너리 값 그대로 입출력
  - 문자열도 바이너리 형태로 출력
  - FileInputStream/FileOutputStream과 함께 사용

### FileOutputStream을 이용한 파일 쓰기

```Java
FileOutputStream fout = new FileOutputStream("C:\\Temp\\test.out");
byte[] b = {7, 51, 3, 4, -1, 24};
for (int i = 0; i < b.length; i++)
  fout.write(b[i]);

fout.close();
```

### FileInputStream을 이용한 파일 읽기

```Java
FileInputStream fin = new FileInputStream("C:\\Temp\\test.out");
int n = 0, c;
while ((c = fin.read()) != -1) {
  b[n] = (byte)c;
  n++;
}
System.out.println("C:\\Temp\\test.out에서 읽은 배열을 출력합니다.");
for (int i = 0; i < b.length; i++)
  System.out.print(b[i] + " ");
System.out.println();
fin.close();
```

## 버퍼 스트림

- 바이트 버퍼 스트림
  - 바이트 단위의 바이너리 데이터를 처리하는 버퍼 스트림
  - BufferedInputStream/BufferedOutputStream
- 문자 버퍼 스트림
  - 유니코드의 문자 데이터만 처리하는 버퍼 스트림
  - BufferedReader/BufferedWriter

```Java
// 20바이트 버퍼를 가진 BufferedOutputStream
BufferedOutputStream bout = new BufferedOutputStream(System.out, 20);
FileReader fin = new FileReader("c:\\windows\\system.ini");

int c;
while ((c = fin.read()) != -1) {
  bout.write((char)c);
}
fin.close();
bout.close();
```

```Java
// 버퍼스트림을 이용한 출력
try {
  fin = new FileReader("c:\\Temp\\test2.txt");
  BufferedOutputStream out = new BufferedOutputStream(System.out, 5);
  // 버퍼가 꽉찰 때 문자가 화면에 출력 (문자 8개면 나머지 3개는 out.flush()로 출력)
  while ((c = fin.read()) != -1) {
    out.write(c);
  }

  // 파일 데이터가 모두 출력된 상태 (Enter키 기다림)
  new Scanner(System.in).nextLine();
  out.flush(); // 버퍼에 남아 있던 문자 모두 출력
  fin.close();
  out.close();
} catch (IOException e) {
  e.printStackTrace();
}
```

### File

- f.getName(), f.getPath(), f.getParent

```Java
// 파일 객체 생성
File f = new File("c:\\windows\\system.ini");

// 파일의 경로명
String filename = f.getName();  // "system.ini"
String path = f.getPath();      // "c:\\windows\\system.ini"
String parent = f.getParent();  // "c:\\windows"

// 파일/디렉터리인지 구분
if(f.isFile()) // 파일인 경우
  System.out.println(f.getPath() + "는 파일입니다.");
else if(f.isDirectory()) // 디렉터리인 경우
  System.out.println(f.getPath() + "는 디렉터리입니다.");

// 서브 디렉터리 리스트 얻기
File f = new File("c:\\Temp");
File[] subfiles = f.listFiles(); // c:\Temp 파일 및 서브디렉터리 리스트 얻기

for(int i=0; i<subfiles.length; i++) {
  System.out.print(subfiles[i].getName()); // 파일명 출력
  System.out.println("\t파일 크기: " + subfiles[i].length()); // 크기 출력
}
```

## 주요 예제

- 텍스트 파일 복사

```Java
import java.io.*;

public class TextCopyEx {
  public static void main(String[] args) {
    File src = new File("c:\\windows\\system.ini"); // 원본 파일 경로명
    File dest = new File("c:\\Temp\\system.txt"); // 복사 파일 경로명
    int c;
    try {
      FileReader fr = new FileReader(src);
      FileWriter fw = new FileWriter(dest);
      while ((c = fr.read()) != -1) { // 문자 하나 읽고
        fw.write((char) c); // 문자 하나 쓰고
      }
      fr.close();
      fw.close();
      System.out.println(src.getPath() + "를 " + dest.getPath() + "로 복사하였습니다.");
    } catch (IOException e) {
      System.out.println("파일 복사 오류");
    }
  }
}
```

- 바이너리 파일 복사

```Java
import java.io.*;

public class BinaryCopyEx {
  public static void main(String[] args) {
    File src = new File("c:\\Windows\\Web\\Wallpaper\\Theme1\\img1.jpg");
    File dest = new File("c:\\Temp\\copyimg.jpg");
    int c;
    try {
      FileInputStream fi = new FileInputStream(src);
      FileOutputStream fo = new FileOutputStream(dest);
      while ((c = fi.read()) != -1) {
        fo.write((byte) c);
      }
      fi.close();
      fo.close();
      System.out.println(src.getPath() + "를 " + dest.getPath() + "로 복사하였습니다.");
    } catch (IOException e) {
      System.out.println("파일 복사 오류");
    }
  }
}
```

- 블록 단위로 바이너리 파일 고속 복사

```Java
import java.io.*;

public class BlockBinaryCopyEx {
  public static void main(String[] args) {
    File src = new File("c:\\Windows\\Web\\Wallpaper\\Theme1\\img1.jpg");
    File dest = new File("c:\\Temp\\desert.jpg");
    try {
      FileInputStream fi = new FileInputStream(src);
      FileOutputStream fo = new FileOutputStream(dest);
      byte[] buf = new byte[1024 * 10]; // 10KB 버퍼
      while (true) {
        int n = fi.read(buf); // 버퍼 크기만큼 읽기. n은 실제 읽은 바이트
        fo.write(buf, 0, n); // buf[0]부터 n 바이트 쓰기
        if (n < buf.length)
          break;
      }
      fi.close();
      fo.close();
      System.out.println(src.getPath() + "를 " + dest.getPath() + "로 복사하였습니다.");
    } catch (IOException e) {
      System.out.println("파일 복사 오류");
    }
  }
}

```
