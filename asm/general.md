Assembly - General Stuff
==

대괄호의 차이
--
 ebx = 12345678일 때를 예를 들자면,
* mov eax, ebx는 ebx의 값을 eax에 복사하는 것인 반면,
* mov eax, [ebx]는 ebx의 값을 메모리 주소로 써서 0x12345678에 위치한 값을 eax로 복사한다.

(src: https://m.blog.naver.com/s2kiess/30181228644)
