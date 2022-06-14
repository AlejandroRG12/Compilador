TITLE	Ejemplo.c
.686
.XMM
.model 	flat
_DATA	SEGMENT
COMM	?i@@:DWORD
COMM	?suma@@:DWORD
COMM	?@3@@:DWORD
_DATA	ENDS
_CONST	SEGMENT
_CONST	ENDS
_TEXT	SEGMENT
_@4$ = -4
_@6$ = -8
_main	PROC
	push	ebp
	mov		ebp, esp
	sub		esp, 72
	push	ebx	
	push	esi	
	push	edi	
	movss	xmm0, DWORD PTR __real@00000000
	movss	DWORD PTR ?suma@@, xmm0
	mov		DWORD PTR ?i@@, 0
$LN3@main:
	cmp		DWORD PTR _@2$[ebp], 20
	jl		SHORT $LN8@main
	jmp		SHORT $LN11@main
$LN5@main:
	mov		eax, DWORD PTR ?i@@
	mov		DWORD PTR ?@3@@, eax
	mov		eax, DWORD PTR ?i@@
	add		eax, 1
	mov		DWORD PTR ?i@@, eax
	jmp		SHORT $LN3@main
$LN8@main:
	cvtsi2ss	xmm0, DWORD PTR ?i@@
	movss		DWORD PTR _@4$[ebp], xmm0
	movss	xmm0, DWORD PTR _@4$[ebp]
	addss	xmm0, DWORD PTR _@4$[ebp]
	movss	DWORD PTR _@4$[ebp], xmm0
	jmp		SHORT $LN5@main
$LN11@main:
	push	DWORD PTR ?suma@@
	sub		esp, 4
	fld		DWORD PTR ?suma@@
	fstp	DWORD PTR [esp]
	push	OFFSET _@5
	call	_printf
	add		esp, 8
	mov		_$[ebp], eax
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

