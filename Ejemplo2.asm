TITLE	Ejemplo2.c
.686
.XMM
.model 	flat
_DATA	SEGMENT
_DATA	ENDS
_CONST	SEGMENT
__real@cccccccd	DD	0cccccccdr
??@3@@	DB	'suma = %g', 0aH, 00H
_CONST	ENDS
_TEXT	SEGMENT
_i$ = -4
_suma$ = -8
_@2$ = -12
_@4$ = -16
_main	PROC
	push	ebp
	mov		ebp, esp
	sub		esp, 80
	push	ebx	
	push	esi	
	push	edi	
	movss	xmm0, DWORD PTR __real@cccccccd
	movss	DWORD PTR _suma$[ebp], xmm0
	cvttsd2si	eax, QWORD PTR _suma$[ebp]
	mov		DWORD PTR _@2$[ebp], eax
	mov		eax, 0
	cmp		eax, 10
	jg		SHORT $LN5@main
	jmp		SHORT $LN8@main
$LN5@main:
	push	DWORD PTR _suma$[ebp]
	sub		esp, 4
	fld		DWORD PTR _suma$[ebp]
	fstp	DWORD PTR [esp]
	push	OFFSET _??@3@@
	call	_printf
	add		esp, 8
	mov		_$[ebp], eax
$LN8@main:
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

