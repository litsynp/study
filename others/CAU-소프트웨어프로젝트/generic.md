# 제네릭을 사용하는 컬렉션

### Vector<E>

- 벡터의 맨 뒤에 객체 삽입 (중간에도 삽입 가능)
- 임의의 위치에 있는 객체 삭제 가능
- add(), get(), remove(i), removeAllElements()

```Java
Vector<Integer> v = new Vector<Integer>(7);
// 벡터의 맨 뒤에 삽입
v.add(5);
v.add(4);
v.add(-1);

int n = v.size();     // n = 3 (요소의 개수)
int c = v.capacity(); // c = 7 (벡터의 용량)

// 요소 중간 삽입
v.add(2, 100);

// 요소 얻어내기
Integer obj = v.get(1);
int i = obj.intValue();

// 벡터 요소 정수 출력
for (int i = 0; i < v.size(); i++) {
  int n = v.get(i);
  System.out.println(n);
}

// 벡터 속 모든 정수 더하기
int sum = 0;
for (int i = 0; i < v.size(); i++) {
  int n = v.elementAt(i);
  sum += n;
}
System.out.println("벡터에 있는 정수 합: " + sum);

// 1번 인덱스의 요소 삭제
v.remove(1);

int last = v.lastElement(); // 마지막 요소
v.removeAllElements();      // 모든 요소 삭제
```

### ArrayList<E>

- 가변 크기 배열
- 객체의 맨 뒤 / 중간에 객체 삽입
- 임의의 위치에 있는 객체 삭제
- 벡터와 달리 capacity() 메소드 없음
- add(), get(), remove(i), clear()

```Java
ArrayList<String> a = new ArrayList<String>(7);
a.add("Hello");
a.add("Hi");
a.add("Java");

int n = a.size(); // n은 3
// int c = a.capacity(); // capacity() 메소드 없음

// 요소 중간 삽입
a.add(2, "Sahni");

// 요소 알아내기
String str = a.get(1);

// "Hello" 요소를 갖고 있는지 확인
System.out.println(a.contains("Hello"));

// 요소 삭제
a.remove(1);

// 모든 요소 삭제
a.clear();
```

### Iterator<E> 인터페이스

- Vector, ArrayList, LinkedList와 같은 컬렉션에서 사용
- hasNext(), next(), remove()
- iterator() 메소드: Iterator 객체 반환 (인덱스 없이 순차적 검색 가능);

```Java
Vector<Integer> v = new Vector<Integer>();
Iterator<Integer> it = v.iterator();

while(it.hasNext()) { // 모든 요소 방문
  int n  = it.next(); // 다음 요소 리턴
  // ...
}
```

### HashMap<K, V>

- key:value의 쌍으로 구성되는 요소를 다루는 컬렉션
- K는 키, V는 값으로 사용할 요소 타입 지정
- 값을 검색하기 위해 반드시 키 사용
- 삽입, 삭제, 검색이 빠름
- put(k, v), get(k), remove(k)
- keySet(), keys.iterator()

```Java
HashMap<String, String> h = new HashMap<String, String>();
h.put("apple", "사과"); // apple:사과 요소 삽입
h.put("love", "사랑");
h.put("baby", "아기");

String kor = h.get("apple"); // apple로 값 검색, kor로 사과
h.remove("baby"); // 키로 요소 삭제

int n = h.size(); // n = 2 (요소 개수)

Scanner sc = new Scanner(System.in);
while (true) {
  System.out.println("찾고 싶은 단어는?");
  Strintg eng = sc.next();
  if (eng.equals("exit")) {
    System.out.println("프로그램 종료");
    break;
  }
}

// 예시 1. 한영 사전
// 해시맵에서 키(eng)의 값(kor) 검색
String kor = h.get(eng);
if (kor == null)
  System.out.println(eng + "는 없는 단어입니다.");
else
  System.out.println(kor);

// 예시 2. 과목 점수 관리
// key 문자열 가진 집합 Set 컬렉션 리턴
Set<String> keys = scoreMap.keySet();
Iterator<String> it = keys.iterator();

// Keyset iterator을 이용한 key 접근
while (it.hasNext()) {
  String name = it.next();
  int score = scoreMap.get(name);
  System.out.println(name + ": " + score);
}

```

### LinkedList<E>
- Vector, ArrayList 클래스와 매우 유사하게 작동
- 요소 객체들은 **양방향으로** 연결되어 관리됨
- 요소 객체는 맨 앞, 맨 뒤, 또는 인덱스를 이용하여 중간에 삽입 가능
- 맨 앞이나 맨 뒤에 요소를 추가하거나 삭제할 수 있어 스택이나 ***큐로 사용 가능**
* put(), get()

## Collections 클래스
- 컬렉션에 대해 연산을 수행하고 결과로 컬렉션 리턴
- 모든 메소드는 **static 타입**
- sort(c), reverse(c), max(c), min(c), binarySearch(c, item)