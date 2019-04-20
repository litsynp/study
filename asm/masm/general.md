Assembly - General Stuff
==


Integer Literals
--
* 26, 26d -> decimal
* 11010011b -> binary
* 42q, 42o -> octal
* 1Ah, 0A3h -> hexadecimal


? Symbol in Data Definition Statement
--
* At least one *initializer* is required in a data definition, which is, for integer data types, an integer literal or expression matching the size of the variable's type (e.g. BYTE, WORD).
* **?** symbol can be used as the initializer if you prefer to leave the variable *uninitialized*.


$ - *Current Location Counter*
--
* The following declaration declares a variable named selfPTR and initializes it with the variable's **offset value**:
```asm
selfPtr DWORD $
```
* This can also be used to conveniently calculate an array's length.
```asm
list BYTE 10,20,30,40
listSize = ($ - list)
```
```asm
list WORD 1000h, 2000h, 3000h, 4000h
listSize = ($ - list) / 2
```


OFFSET Operator
--
* The OFFSET operator returns the offset of a data label, which represents the distance, in bytes, of the label from the beginning of the data segment.
```
               OFFSET
Data Segment: [      [//]          ]
                    myByte
```
* Examples
```asm
.data
bVal BYTE ? ; suppose be located at offset 00404000 (hex)
wVal BYTE ?
dVal DWORD ?
dVal2 DWORD ?
```
```asm
mov esi, OFFSET bVal  ; ESI = 00404000h
mov esi, OFFSET WVal  ; ESI = 00404001h
mov esi, OFFSET dVal  ; ESI = 00404003h
mov esi, OFFSET dVal2  ; ESI = 00404007h
```


Defining Strings
--
* Each character uses a byte of storage.
* Most common type - *null-terminated string*: string ends with a null byte (0)
```asm
greeting1 BYTE "Good afternoon",0
greeting2 BYTE 'Good night',0
```
* **CR/LF** (carriage-return line-feed or *end-of-line characters*)
  * They move the cursor to the left column of the line following the current line.
```asm
greeting1 BYTE "Welcome to the Encryption program ",0dh,0ah
          BYTE "If you wish to modify, send me a copy.",0dh,0ah,0
```


대괄호[]의 차이
--
 ebx = 12345678일 때를 예를 들자면,
* mov eax, ebx는 ebx의 값을 eax에 복사하는 것인 반면,
* mov eax, [ebx]는 ebx의 값을 메모리 주소로 써서 0x12345678에 위치한 값을 eax로 복사한다.

(src: https://m.blog.naver.com/s2kiess/30181228644)

