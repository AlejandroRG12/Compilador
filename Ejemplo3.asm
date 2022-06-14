TITLE	Ejemplo3.c
.686
.XMM
.model 	flat
_DATA	SEGMENT
COMM	?i@@:DWORD
COMM	?suma@@:DWORD
_DATA	ENDS
_CONST	SEGMENT
_CONST	ENDS
_TEXT	SEGMENT
_@6$ = -4
_@8$ = -8
_main	PROC
	push	ebp
	mov		ebp, esp
	sub		esp, 72
	push	ebx	
	push	esi	
	push	edi	
	mov		DWORD PTR ?suma@@, 3
	jmp		SHORT $LN13@main
$LN3@main:
	jmp		SHORT $LN18@main
$LN4@main:
	jmp		SHORT $LN18@main
$LN5@main:
	jmp		SHORT $LN18@main
$LN6@main:
	push	DWORD PTR ?suma@@
	push	OFFSET _@5
	call	_printf
	add		esp, 8
	mov		_$[ebp], eax
	jmp		SHORT $LN18@main
$LN10@main:
	push	OFFSET _@7
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN18@main
$LN13@main:
	cmp		DWORD PTR ?suma@@, 0
	jne		SHORT $LN3@main
	cmp		DWORD PTR ?suma@@, 1
	jne		SHORT $LN4@main
	cmp		DWORD PTR ?suma@@, 2
	jne		SHORT $LN5@main
	cmp		DWORD PTR ?suma@@, 3
	jne		SHORT $LN6@main
	jmp		SHORT $LN10@main
$LN18@main:
	mov		eax, 0
	jmp		SHORT $exit@main
$exit@main:
	pop		edi
	pop		esi
	pop		ebx
	mov		esp, ebp
	pop		ebp
	ret		0
_main	ENDP
_TEXT	ENDS
END

