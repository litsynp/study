레지스터
==
EAX
--
* EAX is automatically used by multiplication and division instructions
* a.k.a extended accumulator register


ECX
--
* ECX is automatically used as a **loop counter**
* decremented by 1 when encountering LOOP

ESI (Extended Source) / EDI (Destination Index)
--
* ESI는 데이터를 조작하거나, 복사할때 데이터의 주소가 저장된다.
* EDI는 복사할때 목적지의 주소가 저장된다.


ESP (Extended Stack) / EBP (Base Pointer)
--
* ESP는 Stack의 끝 지점 주소를 가르키고, EBP는 Stack의 첫 시작 주소를 가리킨다.
* ESP는 스택의 상태가 변할 때마다 값이 변하지만, EBP는 변하지 않는다.
* EBP is used by high-level languages to reference function parameters and local variables on the stack

(src: http://blog.naver.com/PostView.nhn?blogId=67sooon&logNo=10166021894&redirect=Dlog&widgetTypeCall=true)


EIP (Instruction Pointer)
--
* contains the **address of the next instruction** to be executed


Flags in MASM
--
* OV: Overflow
  * when the result of a *signed* arithmetic operation is too large or too small to fit into the destination
* UP: Direction
* EI: Interrupt
* PL: Sign
  * when the result of an arithmetic or logical operation generates a negative result
* ZR: Zero
  * when the result of an arithmetic or logical operation generates a result of zero
* AC: Auxiliary Carry
  * when an arithmetic operation causes a carry from bit 3 to bit 4 in an 8-bit operand
* PE: Parity
  * if the least significant byte in the result contains an even number of 1 bits. Otherwise, PF is clear. Used for error checking when there is probability that data might be altered or corrupted
* CY: Carry
  * when the result of an *usigned* arithmetic operation is too large to fit into the destination
