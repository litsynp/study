Instructions
==

mov & lea
--
> mov는 좌변에 우변(혹은 상수)의 값을 입력하는 것이다.
> lea는 좌변(레지스터만 가능)에 우변의 **주소값**을 입력하는 것이다.

예를 들어 ebp가 0x125e4504 값이고 0x125e4500 메모리 주소로부터 4바이트 공간에 77이란 값이 들어있다면
* lea eax, dword ptr ss:[ebp-4];
  * lea 명령어에 의해서는 eax에는 0x125e4500이 들어가게 되고
* mov eax, dword ptr ss:[ebp-4];
  * mov 명령어에 의해서는 eax에는 77이 들어가게 된다.

(src: https://debugjung.tistory.com/entry/%EC%96%B4%EC%85%88-%EB%AA%85%EB%A0%B9%EC%96%B4-mov%EC%99%80-lea-%EC%B0%A8%EC%9D%B4)  
(**also** ref: https://m.blog.naver.com/PostView.nhn?blogId=s2kiess&logNo=30181276888&proxyReferer=https%3A%2F%2Fwww.google.com%2F)
