Assembly - General Stuff
==


Integer Literals
--
* 26, 26d -> decimal
* 11010011b -> binary
* 42q, 42o -> octal
* 1Ah, 0A3h -> hexadecimal


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


PTR Operator
--
* PTR operator is used to override the declared size of an operand.
```asm
.data
myDouble  DWORD 12345678h

.code
mov ax, myDouble            ; error
mov ax, WORD PTR myDouble
```
* WORD x 2 = 4 Bytes
```asm
mov ax, WORD PTR [myDouble+2] ; 1234h
```

TYPE, LENGTHOF, SIZEOF Operators
--
* TYPE operator returns the size, in bytes, of a single element of a variable.
* LENGTHOF operator counts the number of elements in an array.
* SIZEOF operator returns a value that is equivalent to multiplying LENGTHOF by TYPE.


Indirect Operands - 대괄호[]
--
* ebx = 12345678일 때를 예를 들자면,
  * mov eax, ebx는 ebx의 값을 eax에 복사하는 것인 반면,
  * mov eax, [ebx]는 ebx의 값을 메모리 주소로 써서 0x12345678에 위치한 값을 eax로 복사한다.  
  (src: https://m.blog.naver.com/s2kiess/30181228644)
* An indirect operand can be any 32-bit general-purpose register surrounded by brackets.
```asm
.data
byteVal BYTE 10h
.code
mov esi, OFFSET byteVal
mov al, [esi]            ; AL = 10h
```
* Use PTR with indirect operands - be careful with the size error.
```asm
inc [esi]            ; error: operand must have size
inc BYTE PTR [esi]   ; good
```
* Indirect operands are ideal tools for stepping through arrays.
```asm
.data
arrayB BYTE 10h, 20h, 30h

.code
mov esi, OFFSET arrayB

mov al, [esi]             ; AL = 10h

inc esi
mov al, [esi]             ; AL = 20h

inc esi
mov al, [esi]             ; AL = 30h
```
* Use **TYPE Operator** - Scale Factors in Indexed Operands
```asm
.data
arrayD DWORD 100h, 200h, 300h, 400h

.code
mov esi, 3 * TYPE arrayD             ; offset of arrayD[3]
mov eax, arrayD[esi]                 ; EAX = 400h
```
```asm
.data
arrayD DWORD 1, 2, 3, 4

.code
mov esi, 3                           ; subscript
mov eax, arrayD[esi * TYPE arrayD]   ; EAX = 4
```
