/* or_code.c - Off-Road (OFFROAD.EXE) 를 tools/asm2c.py 로 옮긴 것.  손대지 말 것. */
#include "cpu.h"

void or_run_code(void)
{
    uint32_t jkey;
    CS_ = SEG(0x89d);
    goto L089d0;

/* ---- f_089d_0000 */
L089d0:
    TR(0x089d0); CYC(109); PUSH(DS_); /* 089d:0000 push ds */
    TR(0x089d1); AX = 0; /* 089d:0001 sub ax, ax */
    TR(0x089d3); PUSH(AX); /* 089d:0003 push ax */
    TR(0x089d4); AX = SEG(0x20); /* 089d:0004 mov ax, 0x20 */
    TR(0x089d7); DS_ = AX; /* 089d:0007 mov ds, ax */
    TR(0x089d9); /* 089d:0009 nop  */
    TR(0x089da); AX = 0xb800; /* 089d:000a mov ax, 0xb800 */
    TR(0x089dd); ES_ = AX; /* 089d:000d mov es, ax */
    TR(0x089df); /* 089d:000f nop  */
    TR(0x089e0); PUSH(0x0013); goto L08a17; /* 089d:0010 call 0x8a17 */
L089e3:
    TR(0x089e3); CYC(23); PUSH(0x0016); goto L09090; /* 089d:0013 call 0x9090 */
L089e6:
    TR(0x089e6); CYC(131); WW(DS_, 0x4178, 0x5); /* 089d:0016 mov word ptr [0x4178], 5 */
    TR(0x089ec); WW(DS_, 0x5368, 0x1); /* 089d:001c mov word ptr [0x5368], 1 */
    TR(0x089f2); WW(DS_, 0x50e2, 0x0); /* 089d:0022 mov word ptr [0x50e2], 0 */
    TR(0x089f8); WW(DS_, 0x50e6, 0x0); /* 089d:0028 mov word ptr [0x50e6], 0 */
    TR(0x089fe); AX = 0x0; /* 089d:002e mov ax, 0 */
    TR(0x08a01); PUSH(0x0034); goto L0b829; /* 089d:0031 call 0xb829 */
L08a04:
    TR(0x08a04); CYC(23); PUSH(0x0037); goto L0bac0; /* 089d:0034 call 0xbac0 */
L08a07:
    TR(0x08a07); CYC(23); PUSH(0x003a); goto L0baea; /* 089d:0037 call 0xbaea */
L08a0a:
    TR(0x08a0a); CYC(23); PUSH(0x003d); goto L08aca; /* 089d:003a call 0x8aca */
L08a0d:
    TR(0x08a0d); CYC(23); PUSH(0x0040); goto L09003; /* 089d:003d call 0x9003 */
L08a10:
    TR(0x08a10); CYC(87); AH = 0x0; /* 089d:0040 mov ah, 0 */
    TR(0x08a12); AL = 0x3; /* 089d:0042 mov al, 3 */
    TR(0x08a14); do_int(0x10); /* 089d:0044 int 0x10 */
    TR(0x08a16); CYC(34); { uint16_t o_ = POP(); CS_ = POP(); jkey = KEY(CS_, o_); goto dispatch; } /* 089d:0046 retf  */

/* ---- f_089d_0047 */
L08a17:
    TR(0x08a17); CYC(23); PUSH(0x004a); goto L09172; /* 089d:0047 call 0x9172 */
L08a1a:
    TR(0x08a1a); CYC(87); AH = 0x0; /* 089d:004a mov ah, 0 */
    TR(0x08a1c); AL = 0x4; /* 089d:004c mov al, 4 */
    TR(0x08a1e); do_int(0x10); /* 089d:004e int 0x10 */
    TR(0x08a20); CYC(23); PUSH(0x0053); goto L0b2be; /* 089d:0050 call 0xb2be */
L08a23:
    TR(0x08a23); CYC(71); WW(DS_, 0x68, 0x10); /* 089d:0053 mov word ptr [0x68], 0x10 */
    TR(0x08a29); WW(DS_, 0x6a, 0x2); /* 089d:0059 mov word ptr [0x6a], 2 */
    TR(0x08a2f); PUSH(0x0062); goto L0b172; /* 089d:005f call 0xb172 */
L08a32:
    TR(0x08a32); CYC(47); WW(DS_, 0x4178, 0x5); /* 089d:0062 mov word ptr [0x4178], 5 */
    TR(0x08a38); PUSH(0x006b); goto L0b397; /* 089d:0068 call 0xb397 */
L08a3b:
    TR(0x08a3b); CYC(50); PUSH(BX); /* 089d:006b push bx */
    TR(0x08a3c); BX = 0x2; /* 089d:006c mov bx, 2 */
    TR(0x08a3f); PUSH(0x0072); goto L0aed5; /* 089d:006f call 0xaed5 */
L08a42:
    TR(0x08a42); CYC(116); BX = POP(); /* 089d:0072 pop bx */
    TR(0x08a43); PUSH(BX); /* 089d:0073 push bx */
    TR(0x08a44); PUSH(CX); /* 089d:0074 push cx */
    TR(0x08a45); PUSH(DX); /* 089d:0075 push dx */
    TR(0x08a46); DX = 0x84; /* 089d:0076 mov dx, 0x84 */
    TR(0x08a49); BX = 0x0; /* 089d:0079 mov bx, 0 */
    TR(0x08a4c); CX = 0x0; /* 089d:007c mov cx, 0 */
    TR(0x08a4f); PUSH(0x0082); goto L0b03c; /* 089d:007f call 0xb03c */
L08a52:
    TR(0x08a52); CYC(15); goto L08a67; /* 089d:0082 jmp 0x8a67 */
L08a67:
    TR(0x08a67); CYC(140); DX = POP(); /* 089d:0097 pop dx */
    TR(0x08a68); CX = POP(); /* 089d:0098 pop cx */
    TR(0x08a69); BX = POP(); /* 089d:0099 pop bx */
    TR(0x08a6a); PUSH(BX); /* 089d:009a push bx */
    TR(0x08a6b); PUSH(CX); /* 089d:009b push cx */
    TR(0x08a6c); PUSH(DX); /* 089d:009c push dx */
    TR(0x08a6d); DX = 0xab; /* 089d:009d mov dx, 0xab */
    TR(0x08a70); BX = 0x0; /* 089d:00a0 mov bx, 0 */
    TR(0x08a73); CX = 0xa; /* 089d:00a3 mov cx, 0xa */
    TR(0x08a76); PUSH(0x00a9); goto L0b03c; /* 089d:00a6 call 0xb03c */
L08a79:
    TR(0x08a79); CYC(15); goto L08a82; /* 089d:00a9 jmp 0x8a82 */
L08a82:
    TR(0x08a82); CYC(140); DX = POP(); /* 089d:00b2 pop dx */
    TR(0x08a83); CX = POP(); /* 089d:00b3 pop cx */
    TR(0x08a84); BX = POP(); /* 089d:00b4 pop bx */
    TR(0x08a85); PUSH(BX); /* 089d:00b5 push bx */
    TR(0x08a86); PUSH(CX); /* 089d:00b6 push cx */
    TR(0x08a87); PUSH(DX); /* 089d:00b7 push dx */
    TR(0x08a88); DX = 0xc6; /* 089d:00b8 mov dx, 0xc6 */
    TR(0x08a8b); BX = 0x1b; /* 089d:00bb mov bx, 0x1b */
    TR(0x08a8e); CX = 0xa; /* 089d:00be mov cx, 0xa */
    TR(0x08a91); PUSH(0x00c4); goto L0b03c; /* 089d:00c1 call 0xb03c */
L08a94:
    TR(0x08a94); CYC(15); goto L08a9c; /* 089d:00c4 jmp 0x8a9c */
L08a9c:
    TR(0x08a9c); CYC(86); DX = POP(); /* 089d:00cc pop dx */
    TR(0x08a9d); CX = POP(); /* 089d:00cd pop cx */
    TR(0x08a9e); BX = POP(); /* 089d:00ce pop bx */
    TR(0x08a9f); PUSH(BX); /* 089d:00cf push bx */
    TR(0x08aa0); BX = 0x3; /* 089d:00d0 mov bx, 3 */
    TR(0x08aa3); PUSH(0x00d6); goto L0aed5; /* 089d:00d3 call 0xaed5 */
L08aa6:
    TR(0x08aa6); CYC(158); BX = POP(); /* 089d:00d6 pop bx */
    TR(0x08aa7); PUSH(BX); /* 089d:00d7 push bx */
    TR(0x08aa8); PUSH(CX); /* 089d:00d8 push cx */
    TR(0x08aa9); PUSH(DX); /* 089d:00d9 push dx */
    TR(0x08aaa); WW(DS_, 0x50de, 0x13); /* 089d:00da mov word ptr [0x50de], 0x13 */
    TR(0x08ab0); WW(DS_, 0x50e0, 0xa); /* 089d:00e0 mov word ptr [0x50e0], 0xa */
    TR(0x08ab6); BX = RW(DS_, 0x4178); /* 089d:00e6 mov bx, word ptr [0x4178] */
    TR(0x08aba); DX = 0xa; /* 089d:00ea mov dx, 0xa */
    TR(0x08abd); PUSH(0x00f0); goto L0b083; /* 089d:00ed call 0xb083 */
L08ac0:
    TR(0x08ac0); CYC(71); DX = POP(); /* 089d:00f0 pop dx */
    TR(0x08ac1); CX = POP(); /* 089d:00f1 pop cx */
    TR(0x08ac2); BX = POP(); /* 089d:00f2 pop bx */
    TR(0x08ac3); AX = 0x0; /* 089d:00f3 mov ax, 0 */
    TR(0x08ac6); PUSH(0x00f9); goto L0b829; /* 089d:00f6 call 0xb829 */
L08ac9:
    TR(0x08ac9); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:00f9 ret  */

/* ---- f_089d_00fa */
L08aca:
    TR(0x08aca); CYC(50); PUSH(BX); /* 089d:00fa push bx */
    TR(0x08acb); BX = 0x1; /* 089d:00fb mov bx, 1 */
    TR(0x08ace); PUSH(0x0101); goto L0aed5; /* 089d:00fe call 0xaed5 */
L08ad1:
    TR(0x08ad1); CYC(158); BX = POP(); /* 089d:0101 pop bx */
    TR(0x08ad2); PUSH(BX); /* 089d:0102 push bx */
    TR(0x08ad3); PUSH(CX); /* 089d:0103 push cx */
    TR(0x08ad4); PUSH(DX); /* 089d:0104 push dx */
    TR(0x08ad5); WW(DS_, 0x50de, 0x2b); /* 089d:0105 mov word ptr [0x50de], 0x2b */
    TR(0x08adb); WW(DS_, 0x50e0, 0xa); /* 089d:010b mov word ptr [0x50e0], 0xa */
    TR(0x08ae1); BX = RW(DS_, 0x5368); /* 089d:0111 mov bx, word ptr [0x5368] */
    TR(0x08ae5); DX = 0xa; /* 089d:0115 mov dx, 0xa */
    TR(0x08ae8); PUSH(0x011b); goto L0b083; /* 089d:0118 call 0xb083 */
L08aeb:
    TR(0x08aeb); CYC(107); DX = POP(); /* 089d:011b pop dx */
    TR(0x08aec); CX = POP(); /* 089d:011c pop cx */
    TR(0x08aed); BX = POP(); /* 089d:011d pop bx */
    TR(0x08aee); WW(DS_, 0x4a, 0x0); /* 089d:011e mov word ptr [0x4a], 0 */
    TR(0x08af4); WW(DS_, 0x417a, 0x0); /* 089d:0124 mov word ptr [0x417a], 0 */
    TR(0x08afa); PUSH(0x012d); goto L0b357; /* 089d:012a call 0xb357 */
L08afd:
    TR(0x08afd); CYC(23); PUSH(0x0130); goto L08b8a; /* 089d:012d call 0x8b8a */
L08b00:
    TR(0x08b00); CYC(23); PUSH(0x0133); goto L08bcc; /* 089d:0130 call 0x8bcc */
L08b03:
    TR(0x08b03); CYC(50); PUSH(BX); /* 089d:0133 push bx */
    TR(0x08b04); BX = 0x3; /* 089d:0134 mov bx, 3 */
    TR(0x08b07); PUSH(0x013a); goto L0aed5; /* 089d:0137 call 0xaed5 */
L08b0a:
    TR(0x08b0a); CYC(158); BX = POP(); /* 089d:013a pop bx */
    TR(0x08b0b); PUSH(BX); /* 089d:013b push bx */
    TR(0x08b0c); PUSH(CX); /* 089d:013c push cx */
    TR(0x08b0d); PUSH(DX); /* 089d:013d push dx */
    TR(0x08b0e); WW(DS_, 0x50de, 0x13); /* 089d:013e mov word ptr [0x50de], 0x13 */
    TR(0x08b14); WW(DS_, 0x50e0, 0xa); /* 089d:0144 mov word ptr [0x50e0], 0xa */
    TR(0x08b1a); BX = RW(DS_, 0x4178); /* 089d:014a mov bx, word ptr [0x4178] */
    TR(0x08b1e); DX = 0xa; /* 089d:014e mov dx, 0xa */
    TR(0x08b21); PUSH(0x0154); goto L0b083; /* 089d:0151 call 0xb083 */
L08b24:
    TR(0x08b24); CYC(59); DX = POP(); /* 089d:0154 pop dx */
    TR(0x08b25); CX = POP(); /* 089d:0155 pop cx */
    TR(0x08b26); BX = POP(); /* 089d:0156 pop bx */
    TR(0x08b27); PUSH(0x015a); goto L08b64; /* 089d:0157 call 0x8b64 */
L08b2a:
    TR(0x08b2a); CYC(23); PUSH(0x015d); goto L08d15; /* 089d:015a call 0x8d15 */
L08b2d:
    TR(0x08b2d); CYC(23); PUSH(0x0160); goto L08be8; /* 089d:015d call 0x8be8 */
L08b30:
    TR(0x08b30); CYC(23); PUSH(0x0163); goto L08c2e; /* 089d:0160 call 0x8c2e */
L08b33:
    TR(0x08b33); CYC(23); PUSH(0x0166); goto L08c41; /* 089d:0163 call 0x8c41 */
L08b36:
    TR(0x08b36); CYC(23); PUSH(0x0169); goto L08c54; /* 089d:0166 call 0x8c54 */
L08b39:
    TR(0x08b39); CYC(23); PUSH(0x016c); goto L08c9a; /* 089d:0169 call 0x8c9a */
L08b3c:
    TR(0x08b3c); CYC(23); PUSH(0x016f); goto L08cb9; /* 089d:016c call 0x8cb9 */
L08b3f:
    TR(0x08b3f); CYC(23); PUSH(0x0172); goto L08d0e; /* 089d:016f call 0x8d0e */
L08b42:
    TR(0x08b42); CYC(23); PUSH(0x0175); goto L08d77; /* 089d:0172 call 0x8d77 */
L08b45:
    TR(0x08b45); CYC(23); PUSH(0x0178); goto L08d90; /* 089d:0175 call 0x8d90 */
L08b48:
    TR(0x08b48); CYC(23); PUSH(0x017b); goto L08da3; /* 089d:0178 call 0x8da3 */
L08b4b:
    TR(0x08b4b); CYC(23); PUSH(0x017e); goto L08de5; /* 089d:017b call 0x8de5 */
L08b4e:
    TR(0x08b4e); CYC(23); PUSH(0x0181); goto L08e3d; /* 089d:017e call 0x8e3d */
L08b51:
    TR(0x08b51); CYC(23); PUSH(0x0184); goto L08ea0; /* 089d:0181 call 0x8ea0 */
L08b54:
    TR(0x08b54); CYC(23); PUSH(0x0187); goto L08eb9; /* 089d:0184 call 0x8eb9 */
L08b57:
    TR(0x08b57); CYC(23); PUSH(0x018a); goto L08f1c; /* 089d:0187 call 0x8f1c */
L08b5a:
    TR(0x08b5a); CYC(23); PUSH(0x018d); goto L08f35; /* 089d:018a call 0x8f35 */
L08b5d:
    TR(0x08b5d); CYC(23); PUSH(0x0190); goto L08f7f; /* 089d:018d call 0x8f7f */
L08b60:
    TR(0x08b60); CYC(23); PUSH(0x0193); goto L08ff6; /* 089d:0190 call 0x8ff6 */
L08b63:
    TR(0x08b63); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:0193 ret  */

/* ---- f_089d_0194 */
L08b64:
    TR(0x08b64); CYC(30); CX = RW(DS_, 0x4e60); /* 089d:0194 mov cx, word ptr [0x4e60] */
    TR(0x08b68); BX = 0x0; /* 089d:0198 mov bx, 0 */
L08b6b:
    TR(0x08b6b); CYC(23); PUSH(0x019e); goto L0b412; /* 089d:019b call 0xb412 */
L08b6e:
    TR(0x08b6e); CYC(32); AH = 0x0; /* 089d:019e mov ah, 0 */
    TR(0x08b70); /* 089d:01a0 cmp ax, 0x18 */
    TR(0x08b73); if ((int16_t)AX > (int16_t)0x18) goto L08b6b; /* 089d:01a3 jg 0x8b6b */
    TR(0x08b75); CYC(8); AH = AL; /* 089d:01a5 mov ah, al */
L08b77:
    TR(0x08b77); CYC(23); PUSH(0x01aa); goto L0b412; /* 089d:01a7 call 0xb412 */
L08b7a:
    TR(0x08b7a); CYC(20); /* 089d:01aa cmp al, 0xec */
    TR(0x08b7c); if (AL >= 0xec) goto L08b77; /* 089d:01ac jae 0x8b77 */
    TR(0x08b7e); CYC(41); WW(DS_, (uint16_t)(BX + 0x4dfc), AX); /* 089d:01ae mov word ptr [bx + 0x4dfc], ax */
    TR(0x08b82); PUSH(0x01b5); goto L0b432; /* 089d:01b2 call 0xb432 */
L08b85:
    TR(0x08b85); CYC(25); BX++; /* 089d:01b5 inc bx */
    TR(0x08b86); BX++; /* 089d:01b6 inc bx */
    TR(0x08b87); if (--CX) goto L08b6b; /* 089d:01b7 loop 0x8b6b */
    TR(0x08b89); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:01b9 ret  */

/* ---- f_089d_01ba */
L08b8a:
    TR(0x08b8a); CYC(30); CX = RW(DS_, 0x4ff2); /* 089d:01ba mov cx, word ptr [0x4ff2] */
    TR(0x08b8e); BX = 0x0; /* 089d:01be mov bx, 0 */
L08b91:
    TR(0x08b91); CYC(23); PUSH(0x01c4); goto L0b412; /* 089d:01c1 call 0xb412 */
L08b94:
    TR(0x08b94); CYC(32); AH = 0x0; /* 089d:01c4 mov ah, 0 */
    TR(0x08b96); /* 089d:01c6 cmp ax, 0x17 */
    TR(0x08b99); if ((int16_t)AX > (int16_t)0x17) goto L08b91; /* 089d:01c9 jg 0x8b91 */
    TR(0x08b9b); CYC(8); AH = AL; /* 089d:01cb mov ah, al */
L08b9d:
    TR(0x08b9d); CYC(23); PUSH(0x01d0); goto L0b412; /* 089d:01cd call 0xb412 */
L08ba0:
    TR(0x08ba0); CYC(20); /* 089d:01d0 cmp al, 0xbd */
    TR(0x08ba2); if (AL >= 0xbd) goto L08b9d; /* 089d:01d2 jae 0x8b9d */
    TR(0x08ba4); CYC(30); AX += 0x13f; /* 089d:01d4 add ax, 0x13f */
    TR(0x08ba7); WW(DS_, (uint16_t)(BX + 0x4e62), AX); /* 089d:01d7 mov word ptr [bx + 0x4e62], ax */
L08bab:
    TR(0x08bab); CYC(23); PUSH(0x01de); goto L0b412; /* 089d:01db call 0xb412 */
L08bae:
    TR(0x08bae); CYC(20); /* 089d:01de cmp al, 3 */
    TR(0x08bb0); if (AL >= 0x3) goto L08bab; /* 089d:01e0 jae 0x8bab */
    TR(0x08bb2); CYC(97); AH = 0x0; /* 089d:01e2 mov ah, 0 */
    TR(0x08bb4); WW(DS_, (uint16_t)(BX + 0x4ec6), AX); /* 089d:01e4 mov word ptr [bx + 0x4ec6], ax */
    TR(0x08bb8); WW(DS_, (uint16_t)(BX + 0x4f2a), 0x1); /* 089d:01e8 mov word ptr [bx + 0x4f2a], 1 */
    TR(0x08bbe); WW(DS_, (uint16_t)(BX + 0x4f8e), 0x0); /* 089d:01ee mov word ptr [bx + 0x4f8e], 0 */
    TR(0x08bc4); PUSH(0x01f7); goto L0b4f2; /* 089d:01f4 call 0xb4f2 */
L08bc7:
    TR(0x08bc7); CYC(25); BX++; /* 089d:01f7 inc bx */
    TR(0x08bc8); BX++; /* 089d:01f8 inc bx */
    TR(0x08bc9); if (--CX) goto L08b91; /* 089d:01f9 loop 0x8b91 */
    TR(0x08bcb); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:01fb ret  */

/* ---- f_089d_01fc */
L08bcc:
    TR(0x08bcc); CYC(119); WW(DS_, 0x4176, 0x1); /* 089d:01fc mov word ptr [0x4176], 1 */
    TR(0x08bd2); WW(DS_, 0x4174, 0x0); /* 089d:0202 mov word ptr [0x4174], 0 */
    TR(0x08bd8); WW(DS_, 0x4172, 0xa6); /* 089d:0208 mov word ptr [0x4172], 0xa6 */
    TR(0x08bde); WW(DS_, 0x4170, 0x78); /* 089d:020e mov word ptr [0x4170], 0x78 */
    TR(0x08be4); PUSH(0x0217); goto L0b27f; /* 089d:0214 call 0xb27f */
L08be7:
    TR(0x08be7); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:0217 ret  */

/* ---- f_089d_0218 */
L08be8:
    TR(0x08be8); CYC(30); CX = RW(DS_, 0x53e2); /* 089d:0218 mov cx, word ptr [0x53e2] */
    TR(0x08bec); BX = 0x0; /* 089d:021c mov bx, 0 */
L08bef:
    TR(0x08bef); CYC(23); PUSH(0x0222); goto L0b412; /* 089d:021f call 0xb412 */
L08bf2:
    TR(0x08bf2); CYC(32); AH = 0x0; /* 089d:0222 mov ah, 0 */
    TR(0x08bf4); /* 089d:0224 cmp ax, 0x17 */
    TR(0x08bf7); if ((int16_t)AX > (int16_t)0x17) goto L08bef; /* 089d:0227 jg 0x8bef */
    TR(0x08bf9); CYC(8); AH = AL; /* 089d:0229 mov ah, al */
L08bfb:
    TR(0x08bfb); CYC(23); PUSH(0x022e); goto L0b412; /* 089d:022b call 0xb412 */
L08bfe:
    TR(0x08bfe); CYC(20); /* 089d:022e cmp al, 0xbd */
    TR(0x08c00); if (AL >= 0xbd) goto L08bfb; /* 089d:0230 jae 0x8bfb */
    TR(0x08c02); CYC(30); AX += 0x13f; /* 089d:0232 add ax, 0x13f */
    TR(0x08c05); WW(DS_, (uint16_t)(BX + 0x536a), AX); /* 089d:0235 mov word ptr [bx + 0x536a], ax */
L08c09:
    TR(0x08c09); CYC(23); PUSH(0x023c); goto L0b412; /* 089d:0239 call 0xb412 */
L08c0c:
    TR(0x08c0c); CYC(20); /* 089d:023c cmp al, 0xa */
    TR(0x08c0e); if (AL >= 0xa) goto L08c09; /* 089d:023e jae 0x8c09 */
    TR(0x08c10); CYC(20); /* 089d:0240 cmp al, 5 */
    TR(0x08c12); if (AL < 0x5) goto L08c09; /* 089d:0242 jb 0x8c09 */
    TR(0x08c14); CYC(97); AH = 0x0; /* 089d:0244 mov ah, 0 */
    TR(0x08c16); WW(DS_, (uint16_t)(BX + 0x53c4), AX); /* 089d:0246 mov word ptr [bx + 0x53c4], ax */
    TR(0x08c1a); WW(DS_, (uint16_t)(BX + 0x5388), 0x1); /* 089d:024a mov word ptr [bx + 0x5388], 1 */
    TR(0x08c20); WW(DS_, (uint16_t)(BX + 0x53a6), 0x0); /* 089d:0250 mov word ptr [bx + 0x53a6], 0 */
    TR(0x08c26); PUSH(0x0259); goto L0bea4; /* 089d:0256 call 0xbea4 */
L08c29:
    TR(0x08c29); CYC(25); BX++; /* 089d:0259 inc bx */
    TR(0x08c2a); BX++; /* 089d:025a inc bx */
    TR(0x08c2b); if (--CX) goto L08bef; /* 089d:025b loop 0x8bef */
    TR(0x08c2d); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:025d ret  */

/* ---- f_089d_025e */
L08c2e:
    TR(0x08c2e); CYC(30); CX = RW(DS_, 0x50dc); /* 089d:025e mov cx, word ptr [0x50dc] */
    TR(0x08c32); BX = 0x0; /* 089d:0262 mov bx, 0 */
L08c35:
    TR(0x08c35); CYC(53); WW(DS_, (uint16_t)(BX + 0x5094), 0x0); /* 089d:0265 mov word ptr [bx + 0x5094], 0 */
    TR(0x08c3b); BX += 0x2; /* 089d:026b add bx, 2 */
    TR(0x08c3e); if (--CX) goto L08c35; /* 089d:026e loop 0x8c35 */
    TR(0x08c40); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:0270 ret  */

/* ---- f_089d_0271 */
L08c41:
    TR(0x08c41); CYC(30); CX = RW(DS_, 0x5168); /* 089d:0271 mov cx, word ptr [0x5168] */
    TR(0x08c45); BX = 0x0; /* 089d:0275 mov bx, 0 */
L08c48:
    TR(0x08c48); CYC(53); WW(DS_, (uint16_t)(BX + 0x5138), 0x0); /* 089d:0278 mov word ptr [bx + 0x5138], 0 */
    TR(0x08c4e); BX += 0x2; /* 089d:027e add bx, 2 */
    TR(0x08c51); if (--CX) goto L08c48; /* 089d:0281 loop 0x8c48 */
    TR(0x08c53); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:0283 ret  */

/* ---- f_089d_0284 */
L08c54:
    TR(0x08c54); CYC(30); CX = RW(DS_, 0x5454); /* 089d:0284 mov cx, word ptr [0x5454] */
    TR(0x08c58); BX = 0x0; /* 089d:0288 mov bx, 0 */
L08c5b:
    TR(0x08c5b); CYC(23); PUSH(0x028e); goto L0b412; /* 089d:028b call 0xb412 */
L08c5e:
    TR(0x08c5e); CYC(32); AH = 0x0; /* 089d:028e mov ah, 0 */
    TR(0x08c60); /* 089d:0290 cmp ax, 0x17 */
    TR(0x08c63); if ((int16_t)AX > (int16_t)0x17) goto L08c5b; /* 089d:0293 jg 0x8c5b */
    TR(0x08c65); CYC(8); AH = AL; /* 089d:0295 mov ah, al */
L08c67:
    TR(0x08c67); CYC(23); PUSH(0x029a); goto L0b412; /* 089d:0297 call 0xb412 */
L08c6a:
    TR(0x08c6a); CYC(20); /* 089d:029a cmp al, 0xbd */
    TR(0x08c6c); if (AL >= 0xbd) goto L08c67; /* 089d:029c jae 0x8c67 */
    TR(0x08c6e); CYC(30); AX += 0x13f; /* 089d:029e add ax, 0x13f */
    TR(0x08c71); WW(DS_, (uint16_t)(BX + 0x53e6), AX); /* 089d:02a1 mov word ptr [bx + 0x53e6], ax */
L08c75:
    TR(0x08c75); CYC(23); PUSH(0x02a8); goto L0b412; /* 089d:02a5 call 0xb412 */
L08c78:
    TR(0x08c78); CYC(20); /* 089d:02a8 cmp al, 0xf */
    TR(0x08c7a); if (AL >= 0xf) goto L08c75; /* 089d:02aa jae 0x8c75 */
    TR(0x08c7c); CYC(20); /* 089d:02ac cmp al, 0xa */
    TR(0x08c7e); if (AL < 0xa) goto L08c75; /* 089d:02ae jb 0x8c75 */
    TR(0x08c80); CYC(97); AH = 0x0; /* 089d:02b0 mov ah, 0 */
    TR(0x08c82); WW(DS_, (uint16_t)(BX + 0x5422), AX); /* 089d:02b2 mov word ptr [bx + 0x5422], ax */
    TR(0x08c86); WW(DS_, (uint16_t)(BX + 0x5404), 0x1); /* 089d:02b6 mov word ptr [bx + 0x5404], 1 */
    TR(0x08c8c); WW(DS_, (uint16_t)(BX + 0x5440), 0x0); /* 089d:02bc mov word ptr [bx + 0x5440], 0 */
    TR(0x08c92); PUSH(0x02c5); goto L0c047; /* 089d:02c2 call 0xc047 */
L08c95:
    TR(0x08c95); CYC(25); BX++; /* 089d:02c5 inc bx */
    TR(0x08c96); BX++; /* 089d:02c6 inc bx */
    TR(0x08c97); if (--CX) goto L08c5b; /* 089d:02c7 loop 0x8c5b */
    TR(0x08c99); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:02c9 ret  */

/* ---- f_089d_02ca */
L08c9a:
    TR(0x08c9a); CYC(78); CX = RW(DS_, 0x5062); /* 089d:02ca mov cx, word ptr [0x5062] */
    TR(0x08c9e); BX = 0x0; /* 089d:02ce mov bx, 0 */
    TR(0x08ca1); WW(DS_, 0x505c, 0x0); /* 089d:02d1 mov word ptr [0x505c], 0 */
    TR(0x08ca7); WW(DS_, 0x5066, 0x0); /* 089d:02d7 mov word ptr [0x5066], 0 */
L08cad:
    TR(0x08cad); CYC(53); WW(DS_, (uint16_t)(BX + 0x501e), 0x0); /* 089d:02dd mov word ptr [bx + 0x501e], 0 */
    TR(0x08cb3); BX += 0x2; /* 089d:02e3 add bx, 2 */
    TR(0x08cb6); if (--CX) goto L08cad; /* 089d:02e6 loop 0x8cad */
    TR(0x08cb8); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:02e8 ret  */

/* ---- f_089d_02e9 */
L08cb9:
    TR(0x08cb9); CYC(30); CX = RW(DS_, 0x56b0); /* 089d:02e9 mov cx, word ptr [0x56b0] */
    TR(0x08cbd); BX = 0x0; /* 089d:02ed mov bx, 0 */
L08cc0:
    TR(0x08cc0); CYC(23); PUSH(0x02f3); goto L0b412; /* 089d:02f0 call 0xb412 */
L08cc3:
    TR(0x08cc3); CYC(32); AH = 0x0; /* 089d:02f3 mov ah, 0 */
    TR(0x08cc5); /* 089d:02f5 cmp ax, 0x17 */
    TR(0x08cc8); if ((int16_t)AX > (int16_t)0x17) goto L08cc0; /* 089d:02f8 jg 0x8cc0 */
    TR(0x08cca); CYC(8); AH = AL; /* 089d:02fa mov ah, al */
L08ccc:
    TR(0x08ccc); CYC(23); PUSH(0x02ff); goto L0b412; /* 089d:02fc call 0xb412 */
L08ccf:
    TR(0x08ccf); CYC(20); /* 089d:02ff cmp al, 0xbd */
    TR(0x08cd1); if (AL >= 0xbd) goto L08ccc; /* 089d:0301 jae 0x8ccc */
    TR(0x08cd3); CYC(78); AX += 0x13f; /* 089d:0303 add ax, 0x13f */
    TR(0x08cd6); WW(DS_, (uint16_t)(BX + 0x5458), AX); /* 089d:0306 mov word ptr [bx + 0x5458], ax */
    TR(0x08cda); WW(DS_, (uint16_t)(BX + 0x5520), 0x1); /* 089d:030a mov word ptr [bx + 0x5520], 1 */
    TR(0x08ce0); WW(DS_, (uint16_t)(BX + 0x564c), 0xa2); /* 089d:0310 mov word ptr [bx + 0x564c], 0xa2 */
L08ce6:
    TR(0x08ce6); CYC(23); PUSH(0x0319); goto L0b412; /* 089d:0316 call 0xb412 */
L08ce9:
    TR(0x08ce9); CYC(20); /* 089d:0319 cmp al, 0x12 */
    TR(0x08ceb); if (AL >= 0x12) goto L08ce6; /* 089d:031b jae 0x8ce6 */
    TR(0x08ced); CYC(26); AH = 0x0; /* 089d:031d mov ah, 0 */
    TR(0x08cef); WW(DS_, (uint16_t)(BX + 0x54bc), AX); /* 089d:031f mov word ptr [bx + 0x54bc], ax */
L08cf3:
    TR(0x08cf3); CYC(23); PUSH(0x0326); goto L0b412; /* 089d:0323 call 0xb412 */
L08cf6:
    TR(0x08cf6); CYC(20); /* 089d:0326 cmp al, 0 */
    TR(0x08cf8); if (AL == 0x0) goto L08cf3; /* 089d:0328 je 0x8cf3 */
    TR(0x08cfa); CYC(20); /* 089d:032a cmp al, 5 */
    TR(0x08cfc); if (AL >= 0x5) goto L08cf3; /* 089d:032c jae 0x8cf3 */
    TR(0x08cfe); CYC(57); AH = 0x0; /* 089d:032e mov ah, 0 */
    TR(0x08d00); AX = (uint16_t)(0u - AX); /* 089d:0330 neg ax */
    TR(0x08d02); WW(DS_, (uint16_t)(BX + 0x55e8), AX); /* 089d:0332 mov word ptr [bx + 0x55e8], ax */
    TR(0x08d06); PUSH(0x0339); goto L0c0ae; /* 089d:0336 call 0xc0ae */
L08d09:
    TR(0x08d09); CYC(25); BX++; /* 089d:0339 inc bx */
    TR(0x08d0a); BX++; /* 089d:033a inc bx */
    TR(0x08d0b); if (--CX) goto L08cc0; /* 089d:033b loop 0x8cc0 */
    TR(0x08d0d); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:033d ret  */

/* ---- f_089d_033e */
L08d0e:
    TR(0x08d0e); CYC(44); WW(DS_, 0x56b4, 0x18d8); /* 089d:033e mov word ptr [0x56b4], 0x18d8 */
    TR(0x08d14); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:0344 ret  */

/* ---- f_089d_0345 */
L08d15:
    TR(0x08d15); CYC(30); CX = RW(DS_, 0x59d6); /* 089d:0345 mov cx, word ptr [0x59d6] */
    TR(0x08d19); BX = 0x0; /* 089d:0349 mov bx, 0 */
L08d1c:
    TR(0x08d1c); CYC(23); PUSH(0x034f); goto L0b412; /* 089d:034c call 0xb412 */
L08d1f:
    TR(0x08d1f); CYC(32); AH = 0x0; /* 089d:034f mov ah, 0 */
    TR(0x08d21); /* 089d:0351 cmp ax, 0x17 */
    TR(0x08d24); if ((int16_t)AX > (int16_t)0x17) goto L08d1c; /* 089d:0354 jg 0x8d1c */
    TR(0x08d26); CYC(8); AH = AL; /* 089d:0356 mov ah, al */
L08d28:
    TR(0x08d28); CYC(23); PUSH(0x035b); goto L0b412; /* 089d:0358 call 0xb412 */
L08d2b:
    TR(0x08d2b); CYC(20); /* 089d:035b cmp al, 0xbd */
    TR(0x08d2d); if (AL >= 0xbd) goto L08d28; /* 089d:035d jae 0x8d28 */
    TR(0x08d2f); CYC(54); AX += 0x13f; /* 089d:035f add ax, 0x13f */
    TR(0x08d32); WW(DS_, (uint16_t)(BX + 0x56b6), AX); /* 089d:0362 mov word ptr [bx + 0x56b6], ax */
    TR(0x08d36); WW(DS_, (uint16_t)(BX + 0x577e), 0x1); /* 089d:0366 mov word ptr [bx + 0x577e], 1 */
L08d3c:
    TR(0x08d3c); CYC(23); PUSH(0x036f); goto L0b412; /* 089d:036c call 0xb412 */
L08d3f:
    TR(0x08d3f); CYC(20); /* 089d:036f cmp al, 0x6e */
    TR(0x08d41); if (AL >= 0x6e) goto L08d3c; /* 089d:0371 jae 0x8d3c */
    TR(0x08d43); CYC(38); AH = 0x0; /* 089d:0373 mov ah, 0 */
    TR(0x08d45); AX += 0x19; /* 089d:0375 add ax, 0x19 */
    TR(0x08d48); WW(DS_, (uint16_t)(BX + 0x58aa), AX); /* 089d:0378 mov word ptr [bx + 0x58aa], ax */
L08d4c:
    TR(0x08d4c); CYC(23); PUSH(0x037f); goto L0b412; /* 089d:037c call 0xb412 */
L08d4f:
    TR(0x08d4f); CYC(20); /* 089d:037f cmp al, 0xf */
    TR(0x08d51); if (AL < 0xf) goto L08d4c; /* 089d:0381 jb 0x8d4c */
    TR(0x08d53); CYC(20); /* 089d:0383 cmp al, 0x14 */
    TR(0x08d55); if (AL >= 0x14) goto L08d4c; /* 089d:0385 jae 0x8d4c */
    TR(0x08d57); CYC(49); AH = 0x0; /* 089d:0387 mov ah, 0 */
    TR(0x08d59); WW(DS_, (uint16_t)(BX + 0x5846), AX); /* 089d:0389 mov word ptr [bx + 0x5846], ax */
    TR(0x08d5d); PUSH(0x0390); goto L0c2cf; /* 089d:038d call 0xc2cf */
L08d60:
    TR(0x08d60); CYC(97); WW(DS_, (uint16_t)(BX + 0x571a), 0x0); /* 089d:0390 mov word ptr [bx + 0x571a], 0 */
    TR(0x08d66); WW(DS_, (uint16_t)(BX + 0x590e), 0x1); /* 089d:0396 mov word ptr [bx + 0x590e], 1 */
    TR(0x08d6c); WW(DS_, (uint16_t)(BX + 0x5972), 0x4); /* 089d:039c mov word ptr [bx + 0x5972], 4 */
    TR(0x08d72); BX++; /* 089d:03a2 inc bx */
    TR(0x08d73); BX++; /* 089d:03a3 inc bx */
    TR(0x08d74); if (--CX) goto L08d1c; /* 089d:03a4 loop 0x8d1c */
    TR(0x08d76); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:03a6 ret  */

/* ---- f_089d_03a7 */
L08d77:
    TR(0x08d77); CYC(54); CX = RW(DS_, 0x5a7e); /* 089d:03a7 mov cx, word ptr [0x5a7e] */
    TR(0x08d7b); BX = 0x0; /* 089d:03ab mov bx, 0 */
    TR(0x08d7e); WW(DS_, 0x5a74, 0x0); /* 089d:03ae mov word ptr [0x5a74], 0 */
L08d84:
    TR(0x08d84); CYC(53); WW(DS_, (uint16_t)(BX + 0x5a06), 0x0); /* 089d:03b4 mov word ptr [bx + 0x5a06], 0 */
    TR(0x08d8a); BX += 0x2; /* 089d:03ba add bx, 2 */
    TR(0x08d8d); if (--CX) goto L08d84; /* 089d:03bd loop 0x8d84 */
    TR(0x08d8f); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:03bf ret  */

/* ---- f_089d_03c0 */
L08d90:
    TR(0x08d90); CYC(30); CX = RW(DS_, 0x5af2); /* 089d:03c0 mov cx, word ptr [0x5af2] */
    TR(0x08d94); BX = 0x0; /* 089d:03c4 mov bx, 0 */
L08d97:
    TR(0x08d97); CYC(53); WW(DS_, (uint16_t)(BX + 0x5aac), 0x0); /* 089d:03c7 mov word ptr [bx + 0x5aac], 0 */
    TR(0x08d9d); BX += 0x2; /* 089d:03cd add bx, 2 */
    TR(0x08da0); if (--CX) goto L08d97; /* 089d:03d0 loop 0x8d97 */
    TR(0x08da2); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:03d2 ret  */

/* ---- f_089d_03d3 */
L08da3:
    TR(0x08da3); CYC(30); CX = RW(DS_, 0x5c84); /* 089d:03d3 mov cx, word ptr [0x5c84] */
    TR(0x08da7); BX = 0x0; /* 089d:03d7 mov bx, 0 */
L08daa:
    TR(0x08daa); CYC(23); PUSH(0x03dd); goto L0b412; /* 089d:03da call 0xb412 */
L08dad:
    TR(0x08dad); CYC(32); AH = 0x0; /* 089d:03dd mov ah, 0 */
    TR(0x08daf); /* 089d:03df cmp ax, 0x17 */
    TR(0x08db2); if ((int16_t)AX > (int16_t)0x17) goto L08daa; /* 089d:03e2 jg 0x8daa */
    TR(0x08db4); CYC(8); AH = AL; /* 089d:03e4 mov ah, al */
L08db6:
    TR(0x08db6); CYC(23); PUSH(0x03e9); goto L0b412; /* 089d:03e6 call 0xb412 */
L08db9:
    TR(0x08db9); CYC(20); /* 089d:03e9 cmp al, 0xbd */
    TR(0x08dbb); if (AL >= 0xbd) goto L08db6; /* 089d:03eb jae 0x8db6 */
    TR(0x08dbd); CYC(30); AX += 0x13f; /* 089d:03ed add ax, 0x13f */
    TR(0x08dc0); WW(DS_, (uint16_t)(BX + 0x5af4), AX); /* 089d:03f0 mov word ptr [bx + 0x5af4], ax */
L08dc4:
    TR(0x08dc4); CYC(23); PUSH(0x03f7); goto L0b412; /* 089d:03f4 call 0xb412 */
L08dc7:
    TR(0x08dc7); CYC(20); /* 089d:03f7 cmp al, 3 */
    TR(0x08dc9); if (AL >= 0x3) goto L08dc4; /* 089d:03f9 jae 0x8dc4 */
    TR(0x08dcb); CYC(97); AH = 0x0; /* 089d:03fb mov ah, 0 */
    TR(0x08dcd); WW(DS_, (uint16_t)(BX + 0x5b58), AX); /* 089d:03fd mov word ptr [bx + 0x5b58], ax */
    TR(0x08dd1); WW(DS_, (uint16_t)(BX + 0x5bbc), 0x1); /* 089d:0401 mov word ptr [bx + 0x5bbc], 1 */
    TR(0x08dd7); WW(DS_, (uint16_t)(BX + 0x5c20), 0x0); /* 089d:0407 mov word ptr [bx + 0x5c20], 0 */
    TR(0x08ddd); PUSH(0x0410); goto L0c7bb; /* 089d:040d call 0xc7bb */
L08de0:
    TR(0x08de0); CYC(25); BX++; /* 089d:0410 inc bx */
    TR(0x08de1); BX++; /* 089d:0411 inc bx */
    TR(0x08de2); if (--CX) goto L08daa; /* 089d:0412 loop 0x8daa */
    TR(0x08de4); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:0414 ret  */

/* ---- f_089d_0415 */
L08de5:
    TR(0x08de5); CYC(30); CX = RW(DS_, 0x5f44); /* 089d:0415 mov cx, word ptr [0x5f44] */
    TR(0x08de9); BX = 0x0; /* 089d:0419 mov bx, 0 */
L08dec:
    TR(0x08dec); CYC(23); PUSH(0x041f); goto L0b412; /* 089d:041c call 0xb412 */
L08def:
    TR(0x08def); CYC(32); AH = 0x0; /* 089d:041f mov ah, 0 */
    TR(0x08df1); /* 089d:0421 cmp ax, 0x17 */
    TR(0x08df4); if ((int16_t)AX > (int16_t)0x17) goto L08dec; /* 089d:0424 jg 0x8dec */
    TR(0x08df6); CYC(8); AH = AL; /* 089d:0426 mov ah, al */
L08df8:
    TR(0x08df8); CYC(23); PUSH(0x042b); goto L0b412; /* 089d:0428 call 0xb412 */
L08dfb:
    TR(0x08dfb); CYC(20); /* 089d:042b cmp al, 0xbd */
    TR(0x08dfd); if (AL >= 0xbd) goto L08df8; /* 089d:042d jae 0x8df8 */
    TR(0x08dff); CYC(54); AX += 0x13f; /* 089d:042f add ax, 0x13f */
    TR(0x08e02); WW(DS_, (uint16_t)(BX + 0x5c88), AX); /* 089d:0432 mov word ptr [bx + 0x5c88], ax */
    TR(0x08e06); WW(DS_, (uint16_t)(BX + 0x5d50), 0x1); /* 089d:0436 mov word ptr [bx + 0x5d50], 1 */
L08e0c:
    TR(0x08e0c); CYC(23); PUSH(0x043f); goto L0b412; /* 089d:043c call 0xb412 */
L08e0f:
    TR(0x08e0f); CYC(20); /* 089d:043f cmp al, 0x64 */
    TR(0x08e11); if (AL >= 0x64) goto L08e0c; /* 089d:0441 jae 0x8e0c */
    TR(0x08e13); CYC(38); AH = 0x0; /* 089d:0443 mov ah, 0 */
    TR(0x08e15); AX += 0x28; /* 089d:0445 add ax, 0x28 */
    TR(0x08e18); WW(DS_, (uint16_t)(BX + 0x5e7c), AX); /* 089d:0448 mov word ptr [bx + 0x5e7c], ax */
L08e1c:
    TR(0x08e1c); CYC(23); PUSH(0x044f); goto L0b412; /* 089d:044c call 0xb412 */
L08e1f:
    TR(0x08e1f); CYC(20); /* 089d:044f cmp al, 5 */
    TR(0x08e21); if (AL < 0x5) goto L08e1c; /* 089d:0451 jb 0x8e1c */
    TR(0x08e23); CYC(20); /* 089d:0453 cmp al, 0xa */
    TR(0x08e25); if (AL >= 0xa) goto L08e1c; /* 089d:0455 jae 0x8e1c */
    TR(0x08e27); CYC(81); AH = 0x0; /* 089d:0457 mov ah, 0 */
    TR(0x08e29); AX = (uint16_t)(0u - AX); /* 089d:0459 neg ax */
    TR(0x08e2b); WW(DS_, (uint16_t)(BX + 0x5e18), AX); /* 089d:045b mov word ptr [bx + 0x5e18], ax */
    TR(0x08e2f); WW(DS_, (uint16_t)(BX + 0x5ee0), 0x4); /* 089d:045f mov word ptr [bx + 0x5ee0], 4 */
    TR(0x08e35); PUSH(0x0468); goto L0c930; /* 089d:0465 call 0xc930 */
L08e38:
    TR(0x08e38); CYC(25); BX++; /* 089d:0468 inc bx */
    TR(0x08e39); BX++; /* 089d:0469 inc bx */
    TR(0x08e3a); if (--CX) goto L08dec; /* 089d:046a loop 0x8dec */
    TR(0x08e3c); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:046c ret  */

/* ---- f_089d_046d */
L08e3d:
    TR(0x08e3d); CYC(30); CX = RW(DS_, 0x5fe8); /* 089d:046d mov cx, word ptr [0x5fe8] */
    TR(0x08e41); BX = 0x0; /* 089d:0471 mov bx, 0 */
L08e44:
    TR(0x08e44); CYC(23); PUSH(0x0477); goto L0b412; /* 089d:0474 call 0xb412 */
L08e47:
    TR(0x08e47); CYC(32); AH = 0x0; /* 089d:0477 mov ah, 0 */
    TR(0x08e49); /* 089d:0479 cmp ax, 0x17 */
    TR(0x08e4c); if ((int16_t)AX > (int16_t)0x17) goto L08e44; /* 089d:047c jg 0x8e44 */
    TR(0x08e4e); CYC(8); AH = AL; /* 089d:047e mov ah, al */
L08e50:
    TR(0x08e50); CYC(23); PUSH(0x0483); goto L0b412; /* 089d:0480 call 0xb412 */
L08e53:
    TR(0x08e53); CYC(20); /* 089d:0483 cmp al, 0xbd */
    TR(0x08e55); if (AL >= 0xbd) goto L08e50; /* 089d:0485 jae 0x8e50 */
    TR(0x08e57); CYC(54); AX += 0x13f; /* 089d:0487 add ax, 0x13f */
    TR(0x08e5a); WW(DS_, (uint16_t)(BX + 0x5f48), AX); /* 089d:048a mov word ptr [bx + 0x5f48], ax */
    TR(0x08e5e); WW(DS_, (uint16_t)(BX + 0x5f70), 0x1); /* 089d:048e mov word ptr [bx + 0x5f70], 1 */
L08e64:
    TR(0x08e64); CYC(23); PUSH(0x0497); goto L0b412; /* 089d:0494 call 0xb412 */
L08e67:
    TR(0x08e67); CYC(20); /* 089d:0497 cmp al, 0x32 */
    TR(0x08e69); if (AL >= 0x32) goto L08e64; /* 089d:0499 jae 0x8e64 */
    TR(0x08e6b); CYC(38); AH = 0x0; /* 089d:049b mov ah, 0 */
    TR(0x08e6d); AX += 0x32; /* 089d:049d add ax, 0x32 */
    TR(0x08e70); WW(DS_, (uint16_t)(BX + 0x5fac), AX); /* 089d:04a0 mov word ptr [bx + 0x5fac], ax */
L08e74:
    TR(0x08e74); CYC(23); PUSH(0x04a7); goto L0b412; /* 089d:04a4 call 0xb412 */
L08e77:
    TR(0x08e77); CYC(20); /* 089d:04a7 cmp al, 0xa */
    TR(0x08e79); if (AL < 0xa) goto L08e74; /* 089d:04a9 jb 0x8e74 */
    TR(0x08e7b); CYC(20); /* 089d:04ab cmp al, 0xf */
    TR(0x08e7d); if (AL >= 0xf) goto L08e74; /* 089d:04ad jae 0x8e74 */
    TR(0x08e7f); CYC(50); AH = 0x0; /* 089d:04af mov ah, 0 */
    TR(0x08e81); WW(DS_, (uint16_t)(BX + 0x5f98), AX); /* 089d:04b1 mov word ptr [bx + 0x5f98], ax */
    TR(0x08e85); WW(DS_, (uint16_t)(BX + 0x5fc0), 0x4); /* 089d:04b5 mov word ptr [bx + 0x5fc0], 4 */
L08e8b:
    TR(0x08e8b); CYC(23); PUSH(0x04be); goto L0b412; /* 089d:04bb call 0xb412 */
L08e8e:
    TR(0x08e8e); CYC(20); /* 089d:04be cmp al, 0 */
    TR(0x08e90); if (AL == 0x0) goto L08e8b; /* 089d:04c0 je 0x8e8b */
    TR(0x08e92); CYC(49); AH = 0x0; /* 089d:04c2 mov ah, 0 */
    TR(0x08e94); WW(DS_, (uint16_t)(BX + 0x5fd4), AX); /* 089d:04c4 mov word ptr [bx + 0x5fd4], ax */
    TR(0x08e98); PUSH(0x04cb); goto L0cae8; /* 089d:04c8 call 0xcae8 */
L08e9b:
    TR(0x08e9b); CYC(25); BX++; /* 089d:04cb inc bx */
    TR(0x08e9c); BX++; /* 089d:04cc inc bx */
    TR(0x08e9d); if (--CX) goto L08e44; /* 089d:04cd loop 0x8e44 */
    TR(0x08e9f); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:04cf ret  */

/* ---- f_089d_04d0 */
L08ea0:
    TR(0x08ea0); CYC(54); CX = RW(DS_, 0x619c); /* 089d:04d0 mov cx, word ptr [0x619c] */
    TR(0x08ea4); BX = 0x0; /* 089d:04d4 mov bx, 0 */
    TR(0x08ea7); WW(DS_, 0x6192, 0x0); /* 089d:04d7 mov word ptr [0x6192], 0 */
L08ead:
    TR(0x08ead); CYC(53); WW(DS_, (uint16_t)(BX + 0x6064), 0x0); /* 089d:04dd mov word ptr [bx + 0x6064], 0 */
    TR(0x08eb3); BX += 0x2; /* 089d:04e3 add bx, 2 */
    TR(0x08eb6); if (--CX) goto L08ead; /* 089d:04e6 loop 0x8ead */
    TR(0x08eb8); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:04e8 ret  */

/* ---- f_089d_04e9 */
L08eb9:
    TR(0x08eb9); CYC(30); CX = RW(DS_, 0x6270); /* 089d:04e9 mov cx, word ptr [0x6270] */
    TR(0x08ebd); BX = 0x0; /* 089d:04ed mov bx, 0 */
L08ec0:
    TR(0x08ec0); CYC(23); PUSH(0x04f3); goto L0b412; /* 089d:04f0 call 0xb412 */
L08ec3:
    TR(0x08ec3); CYC(32); AH = 0x0; /* 089d:04f3 mov ah, 0 */
    TR(0x08ec5); /* 089d:04f5 cmp ax, 0x17 */
    TR(0x08ec8); if ((int16_t)AX > (int16_t)0x17) goto L08ec0; /* 089d:04f8 jg 0x8ec0 */
    TR(0x08eca); CYC(8); AH = AL; /* 089d:04fa mov ah, al */
L08ecc:
    TR(0x08ecc); CYC(23); PUSH(0x04ff); goto L0b412; /* 089d:04fc call 0xb412 */
L08ecf:
    TR(0x08ecf); CYC(20); /* 089d:04ff cmp al, 0xbd */
    TR(0x08ed1); if (AL >= 0xbd) goto L08ecc; /* 089d:0501 jae 0x8ecc */
    TR(0x08ed3); CYC(30); AX += 0x13f; /* 089d:0503 add ax, 0x13f */
    TR(0x08ed6); WW(DS_, (uint16_t)(BX + 0x619e), AX); /* 089d:0506 mov word ptr [bx + 0x619e], ax */
L08eda:
    TR(0x08eda); CYC(23); PUSH(0x050d); goto L0b412; /* 089d:050a call 0xb412 */
L08edd:
    TR(0x08edd); CYC(20); /* 089d:050d cmp al, 0x32 */
    TR(0x08edf); if (AL >= 0x32) goto L08eda; /* 089d:050f jae 0x8eda */
    TR(0x08ee1); CYC(62); AH = 0x0; /* 089d:0511 mov ah, 0 */
    TR(0x08ee3); AX += 0x32; /* 089d:0513 add ax, 0x32 */
    TR(0x08ee6); WW(DS_, (uint16_t)(BX + 0x6252), AX); /* 089d:0516 mov word ptr [bx + 0x6252], ax */
    TR(0x08eea); WW(DS_, (uint16_t)(BX + 0x61da), 0x1); /* 089d:051a mov word ptr [bx + 0x61da], 1 */
L08ef0:
    TR(0x08ef0); CYC(23); PUSH(0x0523); goto L0b412; /* 089d:0520 call 0xb412 */
L08ef3:
    TR(0x08ef3); CYC(20); /* 089d:0523 cmp al, 8 */
    TR(0x08ef5); if (AL >= 0x8) goto L08ef0; /* 089d:0525 jae 0x8ef0 */
    TR(0x08ef7); CYC(26); AH = 0x0; /* 089d:0527 mov ah, 0 */
    TR(0x08ef9); WW(DS_, (uint16_t)(BX + 0x61bc), AX); /* 089d:0529 mov word ptr [bx + 0x61bc], ax */
L08efd:
    TR(0x08efd); CYC(23); PUSH(0x0530); goto L0b412; /* 089d:052d call 0xb412 */
L08f00:
    TR(0x08f00); CYC(20); /* 089d:0530 cmp al, 0 */
    TR(0x08f02); if (AL == 0x0) goto L08efd; /* 089d:0532 je 0x8efd */
    TR(0x08f04); CYC(20); /* 089d:0534 cmp al, 9 */
    TR(0x08f06); if (AL >= 0x9) goto L08efd; /* 089d:0536 jae 0x8efd */
    TR(0x08f08); CYC(73); AH = 0x0; /* 089d:0538 mov ah, 0 */
    TR(0x08f0a); WW(DS_, (uint16_t)(BX + 0x6234), AX); /* 089d:053a mov word ptr [bx + 0x6234], ax */
    TR(0x08f0e); WW(DS_, (uint16_t)(BX + 0x61f8), 0x1); /* 089d:053e mov word ptr [bx + 0x61f8], 1 */
    TR(0x08f14); PUSH(0x0547); goto L0cf06; /* 089d:0544 call 0xcf06 */
L08f17:
    TR(0x08f17); CYC(25); BX++; /* 089d:0547 inc bx */
    TR(0x08f18); BX++; /* 089d:0548 inc bx */
    TR(0x08f19); if (--CX) goto L08ec0; /* 089d:0549 loop 0x8ec0 */
    TR(0x08f1b); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:054b ret  */

/* ---- f_089d_054c */
L08f1c:
    TR(0x08f1c); CYC(54); CX = RW(DS_, 0x6300); /* 089d:054c mov cx, word ptr [0x6300] */
    TR(0x08f20); BX = 0x0; /* 089d:0550 mov bx, 0 */
    TR(0x08f23); WW(DS_, 0x62fa, 0x0); /* 089d:0553 mov word ptr [0x62fa], 0 */
L08f29:
    TR(0x08f29); CYC(53); WW(DS_, (uint16_t)(BX + 0x62a0), 0x0); /* 089d:0559 mov word ptr [bx + 0x62a0], 0 */
    TR(0x08f2f); BX += 0x2; /* 089d:055f add bx, 2 */
    TR(0x08f32); if (--CX) goto L08f29; /* 089d:0562 loop 0x8f29 */
    TR(0x08f34); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:0564 ret  */

/* ---- f_089d_0565 */
L08f35:
    TR(0x08f35); CYC(23); PUSH(0x0568); goto L0b412; /* 089d:0565 call 0xb412 */
L08f38:
    TR(0x08f38); CYC(32); AH = 0x0; /* 089d:0568 mov ah, 0 */
    TR(0x08f3a); /* 089d:056a cmp ax, 0x17 */
    TR(0x08f3d); if ((int16_t)AX > (int16_t)0x17) goto L08f35; /* 089d:056d jg 0x8f35 */
    TR(0x08f3f); CYC(8); AH = AL; /* 089d:056f mov ah, al */
L08f41:
    TR(0x08f41); CYC(23); PUSH(0x0574); goto L0b412; /* 089d:0571 call 0xb412 */
L08f44:
    TR(0x08f44); CYC(20); /* 089d:0574 cmp al, 0xbd */
    TR(0x08f46); if (AL >= 0xbd) goto L08f41; /* 089d:0576 jae 0x8f41 */
    TR(0x08f48); CYC(30); AX += 0x13f; /* 089d:0578 add ax, 0x13f */
    TR(0x08f4b); WW(DS_, 0x6302, AX); /* 089d:057b mov word ptr [0x6302], ax */
L08f4e:
    TR(0x08f4e); CYC(23); PUSH(0x0581); goto L0b412; /* 089d:057e call 0xb412 */
L08f51:
    TR(0x08f51); CYC(20); /* 089d:0581 cmp al, 0x32 */
    TR(0x08f53); if (AL >= 0x32) goto L08f4e; /* 089d:0583 jae 0x8f4e */
    TR(0x08f55); CYC(85); AH = 0x0; /* 089d:0585 mov ah, 0 */
    TR(0x08f57); AX += 0x1e; /* 089d:0587 add ax, 0x1e */
    TR(0x08f5a); WW(DS_, 0x6304, AX); /* 089d:058a mov word ptr [0x6304], ax */
    TR(0x08f5d); WW(DS_, 0x6306, 0x1); /* 089d:058d mov word ptr [0x6306], 1 */
    TR(0x08f63); PUSH(0x0596); goto L0d4a6; /* 089d:0593 call 0xd4a6 */
L08f66:
    TR(0x08f66); CYC(48); WW(DS_, 0x630a, 0xfff8); /* 089d:0596 mov word ptr [0x630a], 0xfff8 */
    TR(0x08f6c); WW(DS_, 0x630e, 0x8); /* 089d:059c mov word ptr [0x630e], 8 */
L08f72:
    TR(0x08f72); CYC(23); PUSH(0x05a5); goto L0b412; /* 089d:05a2 call 0xb412 */
L08f75:
    TR(0x08f75); CYC(20); /* 089d:05a5 cmp al, 0 */
    TR(0x08f77); if (AL == 0x0) goto L08f72; /* 089d:05a7 je 0x8f72 */
    TR(0x08f79); CYC(46); AH = 0x0; /* 089d:05a9 mov ah, 0 */
    TR(0x08f7b); WW(DS_, 0x6310, AX); /* 089d:05ab mov word ptr [0x6310], ax */
    TR(0x08f7e); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:05ae ret  */

/* ---- f_089d_05af */
L08f7f:
    TR(0x08f7f); CYC(57); AX = 0x1; /* 089d:05af mov ax, 1 */
    TR(0x08f82); PUSH(AX); /* 089d:05b2 push ax */
    TR(0x08f83); CX = RW(DS_, 0x667a); /* 089d:05b3 mov cx, word ptr [0x667a] */
    TR(0x08f87); BX = 0x0; /* 089d:05b7 mov bx, 0 */
L08f8a:
    TR(0x08f8a); CYC(23); PUSH(0x05bd); goto L0b412; /* 089d:05ba call 0xb412 */
L08f8d:
    TR(0x08f8d); CYC(32); AH = 0x0; /* 089d:05bd mov ah, 0 */
    TR(0x08f8f); /* 089d:05bf cmp ax, 0x17 */
    TR(0x08f92); if ((int16_t)AX > (int16_t)0x17) goto L08f8a; /* 089d:05c2 jg 0x8f8a */
    TR(0x08f94); CYC(8); AH = AL; /* 089d:05c4 mov ah, al */
L08f96:
    TR(0x08f96); CYC(23); PUSH(0x05c9); goto L0b412; /* 089d:05c6 call 0xb412 */
L08f99:
    TR(0x08f99); CYC(20); /* 089d:05c9 cmp al, 0xbd */
    TR(0x08f9b); if (AL >= 0xbd) goto L08f96; /* 089d:05cb jae 0x8f96 */
    TR(0x08f9d); CYC(54); AX += 0x13f; /* 089d:05cd add ax, 0x13f */
    TR(0x08fa0); WW(DS_, (uint16_t)(BX + 0x63be), AX); /* 089d:05d0 mov word ptr [bx + 0x63be], ax */
    TR(0x08fa4); WW(DS_, (uint16_t)(BX + 0x6486), 0x1); /* 089d:05d4 mov word ptr [bx + 0x6486], 1 */
L08faa:
    TR(0x08faa); CYC(23); PUSH(0x05dd); goto L0b412; /* 089d:05da call 0xb412 */
L08fad:
    TR(0x08fad); CYC(20); /* 089d:05dd cmp al, 0x9c */
    TR(0x08faf); if (AL >= 0x9c) goto L08faa; /* 089d:05df jae 0x8faa */
    TR(0x08fb1); CYC(109); AH = 0x0; /* 089d:05e1 mov ah, 0 */
    TR(0x08fb3); AX += 0x14; /* 089d:05e3 add ax, 0x14 */
    TR(0x08fb6); WW(DS_, (uint16_t)(BX + 0x65b2), AX); /* 089d:05e6 mov word ptr [bx + 0x65b2], ax */
    TR(0x08fba); WW(DS_, (uint16_t)(BX + 0x6616), AX); /* 089d:05ea mov word ptr [bx + 0x6616], ax */
    TR(0x08fbe); AX = POP(); /* 089d:05ee pop ax */
    TR(0x08fbf); AX = (uint16_t)(0u - AX); /* 089d:05ef neg ax */
    TR(0x08fc1); WW(DS_, (uint16_t)(BX + 0x64ea), AX); /* 089d:05f1 mov word ptr [bx + 0x64ea], ax */
    TR(0x08fc5); PUSH(AX); /* 089d:05f5 push ax */
L08fc6:
    TR(0x08fc6); CYC(23); PUSH(0x05f9); goto L0b412; /* 089d:05f6 call 0xb412 */
L08fc9:
    TR(0x08fc9); CYC(20); /* 089d:05f9 cmp al, 0xa */
    TR(0x08fcb); if (AL == 0xa) goto L08fc6; /* 089d:05fb je 0x8fc6 */
    TR(0x08fcd); CYC(20); /* 089d:05fd cmp al, 0x14 */
    TR(0x08fcf); if (AL >= 0x14) goto L08fc6; /* 089d:05ff jae 0x8fc6 */
    TR(0x08fd1); CYC(102); AH = 0x0; /* 089d:0601 mov ah, 0 */
    TR(0x08fd3); AX -= 0xa; /* 089d:0603 sub ax, 0xa */
    TR(0x08fd6); WW(DS_, (uint16_t)(BX + 0x654e), AX); /* 089d:0606 mov word ptr [bx + 0x654e], ax */
    TR(0x08fda); WW(DS_, (uint16_t)(BX + 0x6422), 0x0); /* 089d:060a mov word ptr [bx + 0x6422], 0 */
    TR(0x08fe0); /* 089d:0610 cmp word ptr [bx + 0x654e], 0 */
    TR(0x08fe5); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x654e)) >= (int16_t)0x0) goto L08fed; /* 089d:0615 jge 0x8fed */
    TR(0x08fe7); CYC(24); WW(DS_, (uint16_t)(BX + 0x6422), 0x1); /* 089d:0617 mov word ptr [bx + 0x6422], 1 */
L08fed:
    TR(0x08fed); CYC(23); PUSH(0x0620); goto L0d4f4; /* 089d:061d call 0xd4f4 */
L08ff0:
    TR(0x08ff0); CYC(25); BX++; /* 089d:0620 inc bx */
    TR(0x08ff1); BX++; /* 089d:0621 inc bx */
    TR(0x08ff2); if (--CX) goto L08f8a; /* 089d:0622 loop 0x8f8a */
    TR(0x08ff4); CYC(32); AX = POP(); /* 089d:0624 pop ax */
    TR(0x08ff5); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:0625 ret  */

/* ---- f_089d_0626 */
L08ff6:
    TR(0x08ff6); CYC(68); WW(DS_, 0x5364, 0x0); /* 089d:0626 mov word ptr [0x5364], 0 */
    TR(0x08ffc); WW(DS_, 0x5360, 0x0); /* 089d:062c mov word ptr [0x5360], 0 */
    TR(0x09002); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:0632 ret  */

/* ---- f_089d_0633 */
L09003:
    TR(0x09003); CYC(23); VH(0x09003); PUSH(0x0636); goto L0b054; /* 089d:0633 call 0xb054 */
L09006:
    TR(0x09006); CYC(36); /* 089d:0636 cmp byte ptr [0x40], 0x10 */
    TR(0x0900b); if (RB(DS_, 0x40) == 0x10) goto L0901e; /* 089d:063b je 0x901e */
    TR(0x0900d); CYC(36); /* 089d:063d cmp byte ptr [0x40], 0x70 */
    TR(0x09012); if (RB(DS_, 0x40) == 0x70) goto L0901e; /* 089d:0642 je 0x901e */
    TR(0x09014); CYC(36); /* 089d:0644 cmp byte ptr [0x40], 0x50 */
    TR(0x09019); if (RB(DS_, 0x40) == 0x50) goto L0901e; /* 089d:0649 je 0x901e */
    TR(0x0901b); CYC(15); goto L09024; /* 089d:064b jmp 0x9024 */
L0901e:
    TR(0x0901e); CYC(23); PUSH(0x0651); goto L0b27a; /* 089d:064e call 0xb27a */
L09021:
    TR(0x09021); CYC(23); PUSH(0x0654); goto L0b054; /* 089d:0651 call 0xb054 */
L09024:
    TR(0x09024); CYC(36); /* 089d:0654 cmp byte ptr [0x40], 0x12 */
    TR(0x09029); if (RB(DS_, 0x40) != 0x12) goto L09031; /* 089d:0659 jne 0x9031 */
    TR(0x0902b); CYC(27); SP = 0x1fc; /* 089d:065b mov sp, 0x1fc */
    TR(0x0902e); goto L089e3; /* 089d:065e jmp 0x89e3 */
L09031:
    TR(0x09031); CYC(23); PUSH(0x0664); goto L0b339; /* 089d:0661 call 0xb339 */
L09034:
    TR(0x09034); CYC(23); PUSH(0x0667); goto L0b4a8; /* 089d:0664 call 0xb4a8 */
L09037:
    TR(0x09037); CYC(23); PUSH(0x066a); goto L0b2e0; /* 089d:0667 call 0xb2e0 */
L0903a:
    TR(0x0903a); CYC(23); PUSH(0x066d); goto L0b6bd; /* 089d:066a call 0xb6bd */
L0903d:
    TR(0x0903d); CYC(23); PUSH(0x0670); goto L0c712; /* 089d:066d call 0xc712 */
L09040:
    TR(0x09040); CYC(23); PUSH(0x0673); goto L0b480; /* 089d:0670 call 0xb480 */
L09043:
    TR(0x09043); CYC(23); PUSH(0x0676); goto L0b541; /* 089d:0673 call 0xb541 */
L09046:
    TR(0x09046); CYC(23); PUSH(0x0679); goto L0b7ac; /* 089d:0676 call 0xb7ac */
L09049:
    TR(0x09049); CYC(23); PUSH(0x067c); goto L0c64d; /* 089d:0679 call 0xc64d */
L0904c:
    TR(0x0904c); CYC(23); PUSH(0x067f); goto L0b8af; /* 089d:067c call 0xb8af */
L0904f:
    TR(0x0904f); CYC(23); PUSH(0x0682); goto L0b978; /* 089d:067f call 0xb978 */
L09052:
    TR(0x09052); CYC(23); PUSH(0x0685); goto L0c323; /* 089d:0682 call 0xc323 */
L09055:
    TR(0x09055); CYC(23); PUSH(0x0688); goto L0bd4f; /* 089d:0685 call 0xbd4f */
L09058:
    TR(0x09058); CYC(23); PUSH(0x068b); goto L0bef2; /* 089d:0688 call 0xbef2 */
L0905b:
    TR(0x0905b); CYC(23); PUSH(0x068e); goto L0c095; /* 089d:068b call 0xc095 */
L0905e:
    TR(0x0905e); CYC(23); PUSH(0x0691); goto L0c102; /* 089d:068e call 0xc102 */
L09061:
    TR(0x09061); CYC(23); PUSH(0x0694); goto L0c264; /* 089d:0691 call 0xc264 */
L09064:
    TR(0x09064); CYC(23); PUSH(0x0697); goto L0c481; /* 089d:0694 call 0xc481 */
L09067:
    TR(0x09067); CYC(23); PUSH(0x069a); goto L0c809; /* 089d:0697 call 0xc809 */
L0906a:
    TR(0x0906a); CYC(23); PUSH(0x069d); goto L0c982; /* 089d:069a call 0xc982 */
L0906d:
    TR(0x0906d); CYC(23); PUSH(0x06a0); goto L0cb37; /* 089d:069d call 0xcb37 */
L09070:
    TR(0x09070); CYC(23); PUSH(0x06a3); goto L0ccd0; /* 089d:06a0 call 0xccd0 */
L09073:
    TR(0x09073); CYC(23); PUSH(0x06a6); goto L0cf5a; /* 089d:06a3 call 0xcf5a */
L09076:
    TR(0x09076); CYC(23); PUSH(0x06a9); goto L0d0ed; /* 089d:06a6 call 0xd0ed */
L09079:
    TR(0x09079); CYC(23); PUSH(0x06ac); goto L0d30b; /* 089d:06a9 call 0xd30b */
L0907c:
    TR(0x0907c); CYC(23); PUSH(0x06af); goto L0d546; /* 089d:06ac call 0xd546 */
L0907f:
    TR(0x0907f); CYC(18); or_poll(); CX = RW(DS_, 0x4c); /* 089d:06af mov cx, word ptr [0x4c] */
L09083:
    TR(0x09083); CYC(17); SPIN(); /* 089d:06b3 loop 0x9083 */
    TR(0x09085); CYC(36); /* 089d:06b5 cmp byte ptr [0x40], 0x1b */
    TR(0x0908a); if (RB(DS_, 0x40) == 0x1b) goto L0908f; /* 089d:06ba je 0x908f */
    TR(0x0908c); CYC(15); goto L09003; /* 089d:06bc jmp 0x9003 */
L0908f:
    TR(0x0908f); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:06bf ret  */

/* ---- f_089d_06c0 */
L09090:
    TR(0x09090); CYC(23); PUSH(0x06c3); goto L0bac0; /* 089d:06c0 call 0xbac0 */
L09093:
    TR(0x09093); CYC(50); PUSH(BX); /* 089d:06c3 push bx */
    TR(0x09094); BX = 0x3; /* 089d:06c4 mov bx, 3 */
    TR(0x09097); PUSH(0x06ca); goto L0aed5; /* 089d:06c7 call 0xaed5 */
L0909a:
    TR(0x0909a); CYC(116); BX = POP(); /* 089d:06ca pop bx */
    TR(0x0909b); PUSH(BX); /* 089d:06cb push bx */
    TR(0x0909c); PUSH(CX); /* 089d:06cc push cx */
    TR(0x0909d); PUSH(DX); /* 089d:06cd push dx */
    TR(0x0909e); DX = 0x6dc; /* 089d:06ce mov dx, 0x6dc */
    TR(0x090a1); BX = 0x1c; /* 089d:06d1 mov bx, 0x1c */
    TR(0x090a4); CX = 0x28; /* 089d:06d4 mov cx, 0x28 */
    TR(0x090a7); PUSH(0x06da); goto L0b03c; /* 089d:06d7 call 0xb03c */
L090aa:
    TR(0x090aa); CYC(15); goto L090b5; /* 089d:06da jmp 0x90b5 */
L090b5:
    TR(0x090b5); CYC(140); DX = POP(); /* 089d:06e5 pop dx */
    TR(0x090b6); CX = POP(); /* 089d:06e6 pop cx */
    TR(0x090b7); BX = POP(); /* 089d:06e7 pop bx */
    TR(0x090b8); PUSH(BX); /* 089d:06e8 push bx */
    TR(0x090b9); PUSH(CX); /* 089d:06e9 push cx */
    TR(0x090ba); PUSH(DX); /* 089d:06ea push dx */
    TR(0x090bb); DX = 0x6f9; /* 089d:06eb mov dx, 0x6f9 */
    TR(0x090be); BX = 0x25; /* 089d:06ee mov bx, 0x25 */
    TR(0x090c1); CX = 0x37; /* 089d:06f1 mov cx, 0x37 */
    TR(0x090c4); PUSH(0x06f7); goto L0b03c; /* 089d:06f4 call 0xb03c */
L090c7:
    TR(0x090c7); CYC(15); goto L090cc; /* 089d:06f7 jmp 0x90cc */
L090cc:
    TR(0x090cc); CYC(140); DX = POP(); /* 089d:06fc pop dx */
    TR(0x090cd); CX = POP(); /* 089d:06fd pop cx */
    TR(0x090ce); BX = POP(); /* 089d:06fe pop bx */
    TR(0x090cf); PUSH(BX); /* 089d:06ff push bx */
    TR(0x090d0); PUSH(CX); /* 089d:0700 push cx */
    TR(0x090d1); PUSH(DX); /* 089d:0701 push dx */
    TR(0x090d2); DX = 0x710; /* 089d:0702 mov dx, 0x710 */
    TR(0x090d5); BX = 0x10; /* 089d:0705 mov bx, 0x10 */
    TR(0x090d8); CX = 0x46; /* 089d:0708 mov cx, 0x46 */
    TR(0x090db); PUSH(0x070e); goto L0b03c; /* 089d:070b call 0xb03c */
L090de:
    TR(0x090de); CYC(15); goto L090f1; /* 089d:070e jmp 0x90f1 */
L090f1:
    TR(0x090f1); CYC(86); DX = POP(); /* 089d:0721 pop dx */
    TR(0x090f2); CX = POP(); /* 089d:0722 pop cx */
    TR(0x090f3); BX = POP(); /* 089d:0723 pop bx */
    TR(0x090f4); PUSH(BX); /* 089d:0724 push bx */
    TR(0x090f5); BX = 0x2; /* 089d:0725 mov bx, 2 */
    TR(0x090f8); PUSH(0x072b); goto L0aed5; /* 089d:0728 call 0xaed5 */
L090fb:
    TR(0x090fb); CYC(116); BX = POP(); /* 089d:072b pop bx */
    TR(0x090fc); PUSH(BX); /* 089d:072c push bx */
    TR(0x090fd); PUSH(CX); /* 089d:072d push cx */
    TR(0x090fe); PUSH(DX); /* 089d:072e push dx */
    TR(0x090ff); DX = 0x73d; /* 089d:072f mov dx, 0x73d */
    TR(0x09102); BX = 0x13; /* 089d:0732 mov bx, 0x13 */
    TR(0x09105); CX = 0x55; /* 089d:0735 mov cx, 0x55 */
    TR(0x09108); PUSH(0x073b); goto L0b03c; /* 089d:0738 call 0xb03c */
L0910b:
    TR(0x0910b); CYC(15); goto L09117; /* 089d:073b jmp 0x9117 */
L09117:
    TR(0x09117); CYC(176); DX = POP(); /* 089d:0747 pop dx */
    TR(0x09118); CX = POP(); /* 089d:0748 pop cx */
    TR(0x09119); BX = POP(); /* 089d:0749 pop bx */
    TR(0x0911a); PUSH(BX); /* 089d:074a push bx */
    TR(0x0911b); PUSH(CX); /* 089d:074b push cx */
    TR(0x0911c); PUSH(DX); /* 089d:074c push dx */
    TR(0x0911d); WW(DS_, 0x50de, 0x31); /* 089d:074d mov word ptr [0x50de], 0x31 */
    TR(0x09123); WW(DS_, 0x50e0, 0x55); /* 089d:0753 mov word ptr [0x50e0], 0x55 */
    TR(0x09129); BX = 0x7c4; /* 089d:0759 mov bx, 0x7c4 */
    TR(0x0912c); DX = 0x3e8; /* 089d:075c mov dx, 0x3e8 */
    TR(0x0912f); PUSH(0x0762); goto L0b083; /* 089d:075f call 0xb083 */
L09132:
    TR(0x09132); CYC(140); DX = POP(); /* 089d:0762 pop dx */
    TR(0x09133); CX = POP(); /* 089d:0763 pop cx */
    TR(0x09134); BX = POP(); /* 089d:0764 pop bx */
    TR(0x09135); PUSH(BX); /* 089d:0765 push bx */
    TR(0x09136); PUSH(CX); /* 089d:0766 push cx */
    TR(0x09137); PUSH(DX); /* 089d:0767 push dx */
    TR(0x09138); DX = 0x776; /* 089d:0768 mov dx, 0x776 */
    TR(0x0913b); BX = 0x1c; /* 089d:076b mov bx, 0x1c */
    TR(0x0913e); CX = 0x64; /* 089d:076e mov cx, 0x64 */
    TR(0x09141); PUSH(0x0774); goto L0b03c; /* 089d:0771 call 0xb03c */
L09144:
    TR(0x09144); CYC(15); goto L0914f; /* 089d:0774 jmp 0x914f */
L0914f:
    TR(0x0914f); CYC(59); DX = POP(); /* 089d:077f pop dx */
    TR(0x09150); CX = POP(); /* 089d:0780 pop cx */
    TR(0x09151); BX = POP(); /* 089d:0781 pop bx */
    TR(0x09152); PUSH(0x0785); goto L08aca; /* 089d:0782 call 0x8aca */
L09155:
    TR(0x09155); CYC(24); WW(DS_, 0x4a, 0x6); /* 089d:0785 mov word ptr [0x4a], 6 */
L0915b:
    TR(0x0915b); CYC(23); VH(0x0915b); PUSH(0x078e); goto L0b054; /* 089d:078b call 0xb054 */
L0915e:
    TR(0x0915e); CYC(23); PUSH(0x0791); goto L0b339; /* 089d:078e call 0xb339 */
L09161:
    TR(0x09161); CYC(23); PUSH(0x0794); goto L0b480; /* 089d:0791 call 0xb480 */
L09164:
    TR(0x09164); CYC(18); or_poll(); CX = RW(DS_, 0x4c); /* 089d:0794 mov cx, word ptr [0x4c] */
L09168:
    TR(0x09168); CYC(17); SPIN(); /* 089d:0798 loop 0x9168 */
    TR(0x0916a); CYC(40); /* 089d:079a cmp word ptr [0x40], 0 */
    TR(0x0916f); if (RW(DS_, 0x40) == 0x0) goto L0915b; /* 089d:079f je 0x915b */
    TR(0x09171); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:07a1 ret  */

/* ---- f_089d_07a2 */
L09172:
    TR(0x09172); CYC(87); AH = 0x5; /* 089d:07a2 mov ah, 5 */
    TR(0x09174); AL = 0x0; /* 089d:07a4 mov al, 0 */
    TR(0x09176); do_int(0x10); /* 089d:07a6 int 0x10 */
    TR(0x09178); CYC(99); AH = 0x2; /* 089d:07a8 mov ah, 2 */
    TR(0x0917a); DX = 0x0; /* 089d:07aa mov dx, 0 */
    TR(0x0917d); BH = 0x0; /* 089d:07ad mov bh, 0 */
    TR(0x0917f); do_int(0x10); /* 089d:07af int 0x10 */
    TR(0x09181); CYC(107); AH = 0xa; /* 089d:07b1 mov ah, 0xa */
    TR(0x09183); BH = 0x0; /* 089d:07b3 mov bh, 0 */
    TR(0x09185); CX = 0x780; /* 089d:07b5 mov cx, 0x780 */
    TR(0x09188); AL = 0x20; /* 089d:07b8 mov al, 0x20 */
    TR(0x0918a); do_int(0x10); /* 089d:07ba int 0x10 */
    TR(0x0918c); CYC(99); AH = 0x2; /* 089d:07bc mov ah, 2 */
    TR(0x0918e); DX = 0x0; /* 089d:07be mov dx, 0 */
    TR(0x09191); BH = 0x0; /* 089d:07c1 mov bh, 0 */
    TR(0x09193); do_int(0x10); /* 089d:07c3 int 0x10 */
    TR(0x09195); CYC(122); PUSH(DS_); /* 089d:07c5 push ds */
    TR(0x09196); AX = CS_; /* 089d:07c6 mov ax, cs */
    TR(0x09198); DS_ = AX; /* 089d:07c8 mov ds, ax */
    TR(0x0919a); AH = 0x9; /* 089d:07ca mov ah, 9 */
    TR(0x0919c); DX = 0x884; /* 089d:07cc mov dx, 0x884 */
    TR(0x0919f); do_int(0x21); /* 089d:07cf int 0x21 */
    TR(0x091a1); CYC(12); DS_ = POP(); /* 089d:07d1 pop ds */
L091a2:
    TR(0x091a2); CYC(99); AH = 0x2; /* 089d:07d2 mov ah, 2 */
    TR(0x091a4); DX = 0xf2f; /* 089d:07d4 mov dx, 0xf2f */
    TR(0x091a7); BH = 0x0; /* 089d:07d7 mov bh, 0 */
    TR(0x091a9); do_int(0x10); /* 089d:07d9 int 0x10 */
    TR(0x091ab); CYC(79); AH = 0x0; /* 089d:07db mov ah, 0 */
    TR(0x091ad); while (or_int16_wait()) or_poll(); do_int(0x16); /* 089d:07dd int 0x16 */
    TR(0x091af); CYC(20); /* 089d:07df cmp al, 0x31 */
    TR(0x091b1); if (AL != 0x31) goto L091bc; /* 089d:07e1 jne 0x91bc */
    TR(0x091b3); CYC(39); WW(DS_, 0x4c, 0x1); /* 089d:07e3 mov word ptr [0x4c], 1 */
    TR(0x091b9); goto L091ed; /* 089d:07e9 jmp 0x91ed */
L091bc:
    TR(0x091bc); CYC(20); /* 089d:07ec cmp al, 0x32 */
    TR(0x091be); if (AL != 0x32) goto L091c9; /* 089d:07ee jne 0x91c9 */
    TR(0x091c0); CYC(39); WW(DS_, 0x4c, 0x1388); /* 089d:07f0 mov word ptr [0x4c], 0x1388 */
    TR(0x091c6); goto L091ed; /* 089d:07f6 jmp 0x91ed */
L091c9:
    TR(0x091c9); CYC(20); /* 089d:07f9 cmp al, 0x33 */
    TR(0x091cb); if (AL != 0x33) goto L091d6; /* 089d:07fb jne 0x91d6 */
    TR(0x091cd); CYC(39); WW(DS_, 0x4c, 0x2710); /* 089d:07fd mov word ptr [0x4c], 0x2710 */
    TR(0x091d3); goto L091ed; /* 089d:0803 jmp 0x91ed */
L091d6:
    TR(0x091d6); CYC(20); /* 089d:0806 cmp al, 0x34 */
    TR(0x091d8); if (AL != 0x34) goto L091e3; /* 089d:0808 jne 0x91e3 */
    TR(0x091da); CYC(39); WW(DS_, 0x4c, 0x4e20); /* 089d:080a mov word ptr [0x4c], 0x4e20 */
    TR(0x091e0); goto L091ed; /* 089d:0810 jmp 0x91ed */
L091e3:
    TR(0x091e3); CYC(20); /* 089d:0813 cmp al, 0x35 */
    TR(0x091e5); if (AL != 0x35) goto L091a2; /* 089d:0815 jne 0x91a2 */
    TR(0x091e7); CYC(24); WW(DS_, 0x4c, 0xc350); /* 089d:0817 mov word ptr [0x4c], 0xc350 */
L091ed:
    TR(0x091ed); CYC(99); AH = 0x2; /* 089d:081d mov ah, 2 */
    TR(0x091ef); DX = 0x0; /* 089d:081f mov dx, 0 */
    TR(0x091f2); BH = 0x0; /* 089d:0822 mov bh, 0 */
    TR(0x091f4); do_int(0x10); /* 089d:0824 int 0x10 */
    TR(0x091f6); CYC(122); PUSH(DS_); /* 089d:0826 push ds */
    TR(0x091f7); AX = CS_; /* 089d:0827 mov ax, cs */
    TR(0x091f9); DS_ = AX; /* 089d:0829 mov ds, ax */
    TR(0x091fb); AH = 0x9; /* 089d:082b mov ah, 9 */
    TR(0x091fd); DX = 0xfca; /* 089d:082d mov dx, 0xfca */
    TR(0x09200); do_int(0x21); /* 089d:0830 int 0x21 */
    TR(0x09202); CYC(91); DS_ = POP(); /* 089d:0832 pop ds */
    TR(0x09203); AH = 0x0; /* 089d:0833 mov ah, 0 */
    TR(0x09205); while (or_int16_wait()) or_poll(); do_int(0x16); /* 089d:0835 int 0x16 */
    TR(0x09207); CYC(20); /* 089d:0837 cmp al, 0x52 */
    TR(0x09209); if (AL == 0x52) goto L09212; /* 089d:0839 je 0x9212 */
    TR(0x0920b); CYC(20); /* 089d:083b cmp al, 0x72 */
    TR(0x0920d); if (AL == 0x72) goto L09212; /* 089d:083d je 0x9212 */
    TR(0x0920f); CYC(15); goto L09239; /* 089d:083f jmp 0x9239 */
L09212:
    TR(0x09212); CYC(99); AH = 0x2; /* 089d:0842 mov ah, 2 */
    TR(0x09214); DX = 0x0; /* 089d:0844 mov dx, 0 */
    TR(0x09217); BH = 0x0; /* 089d:0847 mov bh, 0 */
    TR(0x09219); do_int(0x10); /* 089d:0849 int 0x10 */
    TR(0x0921b); CYC(79); AH = 0xf; /* 089d:084b mov ah, 0xf */
    TR(0x0921d); do_int(0x10); /* 089d:084d int 0x10 */
    TR(0x0921f); CYC(99); AH = 0xa; /* 089d:084f mov ah, 0xa */
    TR(0x09221); CX = 0x7d0; /* 089d:0851 mov cx, 0x7d0 */
    TR(0x09224); AL = 0x20; /* 089d:0854 mov al, 0x20 */
    TR(0x09226); do_int(0x10); /* 089d:0856 int 0x10 */
    TR(0x09228); CYC(122); PUSH(DS_); /* 089d:0858 push ds */
    TR(0x09229); AX = CS_; /* 089d:0859 mov ax, cs */
    TR(0x0922b); DS_ = AX; /* 089d:085b mov ds, ax */
    TR(0x0922d); AH = 0x9; /* 089d:085d mov ah, 9 */
    TR(0x0922f); DX = 0x1e56; /* 089d:085f mov dx, 0x1e56 */
    TR(0x09232); do_int(0x21); /* 089d:0862 int 0x21 */
    TR(0x09234); CYC(91); DS_ = POP(); /* 089d:0864 pop ds */
    TR(0x09235); AH = 0x0; /* 089d:0865 mov ah, 0 */
    TR(0x09237); while (or_int16_wait()) or_poll(); do_int(0x16); /* 089d:0867 int 0x16 */
L09239:
    TR(0x09239); CYC(99); AH = 0x2; /* 089d:0869 mov ah, 2 */
    TR(0x0923b); DX = 0x0; /* 089d:086b mov dx, 0 */
    TR(0x0923e); BH = 0x0; /* 089d:086e mov bh, 0 */
    TR(0x09240); do_int(0x10); /* 089d:0870 int 0x10 */
    TR(0x09242); CYC(122); PUSH(DS_); /* 089d:0872 push ds */
    TR(0x09243); AX = CS_; /* 089d:0873 mov ax, cs */
    TR(0x09245); DS_ = AX; /* 089d:0875 mov ds, ax */
    TR(0x09247); AH = 0x9; /* 089d:0877 mov ah, 9 */
    TR(0x09249); DX = 0x1710; /* 089d:0879 mov dx, 0x1710 */
    TR(0x0924c); do_int(0x21); /* 089d:087c int 0x21 */
    TR(0x0924e); CYC(91); DS_ = POP(); /* 089d:087e pop ds */
    TR(0x0924f); AH = 0x0; /* 089d:087f mov ah, 0 */
    TR(0x09251); while (or_int16_wait()) or_poll(); do_int(0x16); /* 089d:0881 int 0x16 */
    TR(0x09253); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:0883 ret  */

/* ---- f_089d_2455 */
L0ae25:
    TR(0x0ae25); CYC(18); VH(0x0ae25); { uint32_t k_ = or_fast(0x0ae25); if (k_) { jkey = k_; goto dispatch; } } SI = RW(DS_, 0x36); /* 089d:2455 mov si, word ptr [0x36] */
L0ae29:
    TR(0x0ae29); CYC(41); BX = RW(DS_, 0x2e); /* 089d:2459 mov bx, word ptr [0x2e] */
    TR(0x0ae2d); PUSH(0x2460); goto L0aeca; /* 089d:245d call 0xaeca */
L0ae30:
    TR(0x0ae30); CYC(106); AL = RB(DS_, SI); /* 089d:2460 mov al, byte ptr [si] */
    TR(0x0ae32); AH = 0x0; /* 089d:2462 mov ah, 0 */
    TR(0x0ae34); CL = RB(DS_, 0x3a); /* 089d:2464 mov cl, byte ptr [0x3a] */
    TR(0x0ae38); { uint16_t a_ = AX; unsigned n_ = CL & 0x1f, k_ = n_ % 16;   if (n_) { uint16_t r_ = k_ ? (uint16_t)((a_ >> k_) | (a_ << (16 - k_))) : a_;     AX = r_;   } } /* 089d:2468 ror ax, cl */
    TR(0x0ae3a); WW(ES_, BX, (uint16_t)(RW(ES_, BX) ^ AX)); /* 089d:246a xor word ptr es:[bx], ax */
    TR(0x0ae3d); SI++; /* 089d:246d inc si */
    TR(0x0ae3e); BX++; /* 089d:246e inc bx */
    TR(0x0ae3f); DL--; /* 089d:246f dec dl */
    TR(0x0ae41); if ((uint8_t)DL != 0) goto L0ae30; /* 089d:2471 jne 0xae30 */
    TR(0x0ae43); CYC(55); DL = DH; /* 089d:2473 mov dl, dh */
    TR(0x0ae45); WW(DS_, 0x2e, (uint16_t)(RW(DS_, 0x2e) + 1)); /* 089d:2475 inc word ptr [0x2e] */
    TR(0x0ae49); CH--; /* 089d:2479 dec ch */
    TR(0x0ae4b); if ((uint8_t)CH != 0) goto L0ae29; /* 089d:247b jne 0xae29 */
    TR(0x0ae4d); CYC(20); VH(0x0ae4d); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:247d ret  */

/* ---- f_089d_24b0 */
L0ae80:
    TR(0x0ae80); CYC(18); VH(0x0ae80); SI = RW(DS_, 0x36); /* 089d:24b0 mov si, word ptr [0x36] */
L0ae84:
    TR(0x0ae84); CYC(41); BX = RW(DS_, 0x2e); /* 089d:24b4 mov bx, word ptr [0x2e] */
    TR(0x0ae88); PUSH(0x24bb); goto L0aeca; /* 089d:24b8 call 0xaeca */
L0ae8b:
    TR(0x0ae8b); CYC(90); AL = RB(DS_, SI); /* 089d:24bb mov al, byte ptr [si] */
    TR(0x0ae8d); AH = 0x0; /* 089d:24bd mov ah, 0 */
    TR(0x0ae8f); DI = RW(DS_, 0x2a); /* 089d:24bf mov di, word ptr [0x2a] */
    TR(0x0ae93); AX &= DI; /* 089d:24c3 and ax, di */
    TR(0x0ae95); WB(ES_, BX, AL); /* 089d:24c5 mov byte ptr es:[bx], al */
    TR(0x0ae98); SI++; /* 089d:24c8 inc si */
    TR(0x0ae99); BX++; /* 089d:24c9 inc bx */
    TR(0x0ae9a); DL--; /* 089d:24ca dec dl */
    TR(0x0ae9c); if ((uint8_t)DL != 0) goto L0ae8b; /* 089d:24cc jne 0xae8b */
    TR(0x0ae9e); CYC(55); DL = DH; /* 089d:24ce mov dl, dh */
    TR(0x0aea0); WW(DS_, 0x2e, (uint16_t)(RW(DS_, 0x2e) + 1)); /* 089d:24d0 inc word ptr [0x2e] */
    TR(0x0aea4); CH--; /* 089d:24d4 dec ch */
    TR(0x0aea6); if ((uint8_t)CH != 0) goto L0ae84; /* 089d:24d6 jne 0xae84 */
    TR(0x0aea8); CYC(20); VH(0x0aea8); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:24d8 ret  */

/* ---- f_089d_24fa */
L0aeca:
    TR(0x0aeca); CYC(63); BX += BX; /* 089d:24fa add bx, bx */
    TR(0x0aecc); BX = RW(DS_, (uint16_t)(BX + 0x667e)); /* 089d:24fc mov bx, word ptr [bx + 0x667e] */
    TR(0x0aed0); BX += RW(DS_, 0x2c); /* 089d:2500 add bx, word ptr [0x2c] */
    TR(0x0aed4); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2504 ret  */

/* ---- f_089d_2505 */
L0aed5:
    TR(0x0aed5); CYC(64); BX += BX; /* 089d:2505 add bx, bx */
    TR(0x0aed7); BX = RW(DS_, (uint16_t)(BX + 0x694e)); /* 089d:2507 mov bx, word ptr [bx + 0x694e] */
    TR(0x0aedb); WW(DS_, 0x2a, BX); /* 089d:250b mov word ptr [0x2a], bx */
    TR(0x0aedf); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:250f ret  */

/* ---- f_089d_2544 */
L0af14:
    TR(0x0af14); CYC(134); PUSH(BX); /* 089d:2544 push bx */
    TR(0x0af15); PUSH(CX); /* 089d:2545 push cx */
    TR(0x0af16); PUSH(DX); /* 089d:2546 push dx */
    TR(0x0af17); PUSH(DI); /* 089d:2547 push di */
    TR(0x0af18); PUSH(SI); /* 089d:2548 push si */
    TR(0x0af19); AX = RW(DS_, 0x54); /* 089d:2549 mov ax, word ptr [0x54] */
    TR(0x0af1c); { uint16_t a_ = AX, b_ = RW(DS_, 0x50); unsigned r_ = (unsigned)a_ - b_;   AX = (uint16_t)r_;   SF = ((r_ >> 15) & 1);   OF = (((a_ ^ b_) & (a_ ^ r_)) >> 15) & 1; } /* 089d:254c sub ax, word ptr [0x50] */
    TR(0x0af20); SI = 0x1; /* 089d:2550 mov si, 1 */
    TR(0x0af23); if (SF == OF) goto L0af2a; /* 089d:2553 jge 0xaf2a */
    TR(0x0af25); CYC(20); SI = 0xffff; /* 089d:2555 mov si, 0xffff */
    TR(0x0af28); AX = (uint16_t)(0u - AX); /* 089d:2558 neg ax */
L0af2a:
    TR(0x0af2a); CYC(77); WW(DS_, 0x5e, AX); /* 089d:255a mov word ptr [0x5e], ax */
    TR(0x0af2d); AX = RW(DS_, 0x52); /* 089d:255d mov ax, word ptr [0x52] */
    TR(0x0af30); { uint16_t a_ = AX, b_ = RW(DS_, 0x4e); unsigned r_ = (unsigned)a_ - b_;   AX = (uint16_t)r_;   SF = ((r_ >> 15) & 1);   OF = (((a_ ^ b_) & (a_ ^ r_)) >> 15) & 1; } /* 089d:2560 sub ax, word ptr [0x4e] */
    TR(0x0af34); DI = 0x1; /* 089d:2564 mov di, 1 */
    TR(0x0af37); if (SF == OF) goto L0af3e; /* 089d:2567 jge 0xaf3e */
    TR(0x0af39); CYC(20); DI = 0xffff; /* 089d:2569 mov di, 0xffff */
    TR(0x0af3c); AX = (uint16_t)(0u - AX); /* 089d:256c neg ax */
L0af3e:
    TR(0x0af3e); CYC(65); WW(DS_, 0x5c, AX); /* 089d:256e mov word ptr [0x5c], ax */
    TR(0x0af41); AX = RW(DS_, 0x5c); /* 089d:2571 mov ax, word ptr [0x5c] */
    TR(0x0af44); /* 089d:2574 cmp ax, word ptr [0x5e] */
    TR(0x0af48); if ((int16_t)AX < (int16_t)RW(DS_, 0x5e)) goto L0af50; /* 089d:2578 jl 0xaf50 */
    TR(0x0af4a); CYC(23); PUSH(0x257d); goto L0af59; /* 089d:257a call 0xaf59 */
L0af4d:
    TR(0x0af4d); CYC(15); goto L0af53; /* 089d:257d jmp 0xaf53 */
L0af50:
    TR(0x0af50); CYC(23); PUSH(0x2583); goto L0af98; /* 089d:2580 call 0xaf98 */
L0af53:
    TR(0x0af53); CYC(80); SI = POP(); /* 089d:2583 pop si */
    TR(0x0af54); DI = POP(); /* 089d:2584 pop di */
    TR(0x0af55); DX = POP(); /* 089d:2585 pop dx */
    TR(0x0af56); CX = POP(); /* 089d:2586 pop cx */
    TR(0x0af57); BX = POP(); /* 089d:2587 pop bx */
    TR(0x0af58); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2588 ret  */

/* ---- f_089d_2589 */
L0af59:
    TR(0x0af59); CYC(92); AX = RW(DS_, 0x5c); /* 089d:2589 mov ax, word ptr [0x5c] */
    TR(0x0af5c); AX >>= 1; /* 089d:258c shr ax, 1 */
    TR(0x0af5e); WW(DS_, 0x56, AX); /* 089d:258e mov word ptr [0x56], ax */
    TR(0x0af61); BX = 0x0; /* 089d:2591 mov bx, 0 */
    TR(0x0af64); AX = RW(DS_, 0x5c); /* 089d:2594 mov ax, word ptr [0x5c] */
    TR(0x0af67); WW(DS_, 0x5a, AX); /* 089d:2597 mov word ptr [0x5a], ax */
L0af6a:
    TR(0x0af6a); CYC(104); PUSH(BX); /* 089d:259a push bx */
    TR(0x0af6b); PUSH(CX); /* 089d:259b push cx */
    TR(0x0af6c); PUSH(DX); /* 089d:259c push dx */
    TR(0x0af6d); BX = RW(DS_, 0x4e); /* 089d:259d mov bx, word ptr [0x4e] */
    TR(0x0af71); CX = RW(DS_, 0x50); /* 089d:25a1 mov cx, word ptr [0x50] */
    TR(0x0af75); PUSH(0x25a8); goto L0afd7; /* 089d:25a5 call 0xafd7 */
L0af78:
    TR(0x0af78); CYC(110); DX = POP(); /* 089d:25a8 pop dx */
    TR(0x0af79); CX = POP(); /* 089d:25a9 pop cx */
    TR(0x0af7a); BX = POP(); /* 089d:25aa pop bx */
    TR(0x0af7b); WW(DS_, 0x4e, (uint16_t)(RW(DS_, 0x4e) + DI)); /* 089d:25ab add word ptr [0x4e], di */
    TR(0x0af7f); BX += RW(DS_, 0x5e); /* 089d:25af add bx, word ptr [0x5e] */
    TR(0x0af83); /* 089d:25b3 cmp bx, word ptr [0x56] */
    TR(0x0af87); if ((int16_t)BX <= (int16_t)RW(DS_, 0x56)) goto L0af91; /* 089d:25b7 jle 0xaf91 */
    TR(0x0af89); CYC(45); BX -= RW(DS_, 0x5c); /* 089d:25b9 sub bx, word ptr [0x5c] */
    TR(0x0af8d); WW(DS_, 0x50, (uint16_t)(RW(DS_, 0x50) + SI)); /* 089d:25bd add word ptr [0x50], si */
L0af91:
    TR(0x0af91); CYC(39); { uint16_t a_ = RW(DS_, 0x5a), b_ = 1; unsigned r_ = (unsigned)a_ - 1;   WW(DS_, 0x5a, (uint16_t)r_);   SF = ((r_ >> 15) & 1);   OF = (((a_ ^ b_) & (a_ ^ r_)) >> 15) & 1; } /* 089d:25c1 dec word ptr [0x5a] */
    TR(0x0af95); if (SF == OF) goto L0af6a; /* 089d:25c5 jge 0xaf6a */
    TR(0x0af97); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:25c7 ret  */

/* ---- f_089d_25c8 */
L0af98:
    TR(0x0af98); CYC(92); AX = RW(DS_, 0x5e); /* 089d:25c8 mov ax, word ptr [0x5e] */
    TR(0x0af9b); AX >>= 1; /* 089d:25cb shr ax, 1 */
    TR(0x0af9d); WW(DS_, 0x58, AX); /* 089d:25cd mov word ptr [0x58], ax */
    TR(0x0afa0); BX = 0x0; /* 089d:25d0 mov bx, 0 */
    TR(0x0afa3); AX = RW(DS_, 0x5e); /* 089d:25d3 mov ax, word ptr [0x5e] */
    TR(0x0afa6); WW(DS_, 0x5a, AX); /* 089d:25d6 mov word ptr [0x5a], ax */
L0afa9:
    TR(0x0afa9); CYC(104); PUSH(BX); /* 089d:25d9 push bx */
    TR(0x0afaa); PUSH(CX); /* 089d:25da push cx */
    TR(0x0afab); PUSH(DX); /* 089d:25db push dx */
    TR(0x0afac); BX = RW(DS_, 0x4e); /* 089d:25dc mov bx, word ptr [0x4e] */
    TR(0x0afb0); CX = RW(DS_, 0x50); /* 089d:25e0 mov cx, word ptr [0x50] */
    TR(0x0afb4); PUSH(0x25e7); goto L0afd7; /* 089d:25e4 call 0xafd7 */
L0afb7:
    TR(0x0afb7); CYC(110); DX = POP(); /* 089d:25e7 pop dx */
    TR(0x0afb8); CX = POP(); /* 089d:25e8 pop cx */
    TR(0x0afb9); BX = POP(); /* 089d:25e9 pop bx */
    TR(0x0afba); WW(DS_, 0x50, (uint16_t)(RW(DS_, 0x50) + SI)); /* 089d:25ea add word ptr [0x50], si */
    TR(0x0afbe); BX += RW(DS_, 0x5c); /* 089d:25ee add bx, word ptr [0x5c] */
    TR(0x0afc2); /* 089d:25f2 cmp bx, word ptr [0x58] */
    TR(0x0afc6); if ((int16_t)BX <= (int16_t)RW(DS_, 0x58)) goto L0afd0; /* 089d:25f6 jle 0xafd0 */
    TR(0x0afc8); CYC(45); BX -= RW(DS_, 0x5e); /* 089d:25f8 sub bx, word ptr [0x5e] */
    TR(0x0afcc); WW(DS_, 0x4e, (uint16_t)(RW(DS_, 0x4e) + DI)); /* 089d:25fc add word ptr [0x4e], di */
L0afd0:
    TR(0x0afd0); CYC(39); { uint16_t a_ = RW(DS_, 0x5a), b_ = 1; unsigned r_ = (unsigned)a_ - 1;   WW(DS_, 0x5a, (uint16_t)r_);   SF = ((r_ >> 15) & 1);   OF = (((a_ ^ b_) & (a_ ^ r_)) >> 15) & 1; } /* 089d:2600 dec word ptr [0x5a] */
    TR(0x0afd4); if (SF == OF) goto L0afa9; /* 089d:2604 jge 0xafa9 */
    TR(0x0afd6); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2606 ret  */

/* ---- f_089d_2607 */
L0afd7:
    TR(0x0afd7); CYC(190); AL = RB(DS_, (uint16_t)(BX + 0x680e)); /* 089d:2607 mov al, byte ptr [bx + 0x680e] */
    TR(0x0afdb); AH = 0x0; /* 089d:260b mov ah, 0 */
    TR(0x0afdd); WW(DS_, 0x2c, AX); /* 089d:260d mov word ptr [0x2c], ax */
    TR(0x0afe0); AL = RB(DS_, (uint16_t)(BX + 0x6a9c)); /* 089d:2610 mov al, byte ptr [bx + 0x6a9c] */
    TR(0x0afe4); BX = CX; /* 089d:2614 mov bx, cx */
    TR(0x0afe6); BX += BX; /* 089d:2616 add bx, bx */
    TR(0x0afe8); BX = RW(DS_, (uint16_t)(BX + 0x667e)); /* 089d:2618 mov bx, word ptr [bx + 0x667e] */
    TR(0x0afec); BX += RW(DS_, 0x2c); /* 089d:261c add bx, word ptr [0x2c] */
    TR(0x0aff0); DL = RB(DS_, 0x2a); /* 089d:2620 mov dl, byte ptr [0x2a] */
    TR(0x0aff4); DL ^= RB(ES_, BX); /* 089d:2624 xor dl, byte ptr es:[bx] */
    TR(0x0aff7); AL &= DL; /* 089d:2627 and al, dl */
    TR(0x0aff9); WB(ES_, BX, (uint8_t)(RB(ES_, BX) ^ AL)); /* 089d:2629 xor byte ptr es:[bx], al */
    TR(0x0affc); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:262c ret  */

/* ---- f_089d_262d */
L0affd:
    TR(0x0affd); CYC(86); PUSH(CX); /* 089d:262d push cx */
    TR(0x0affe); PUSH(DI); /* 089d:262e push di */
    TR(0x0afff); PUSH(BX); /* 089d:262f push bx */
    TR(0x0b000); BX = RW(DS_, 0x2a); /* 089d:2630 mov bx, word ptr [0x2a] */
    TR(0x0b004); PUSH(0x2637); goto L0aed5; /* 089d:2634 call 0xaed5 */
L0b007:
    TR(0x0b007); CYC(71); BX = POP(); /* 089d:2637 pop bx */
    TR(0x0b008); DI = 0x1; /* 089d:2638 mov di, 1 */
    TR(0x0b00b); CX = RW(DS_, 0x64); /* 089d:263b mov cx, word ptr [0x64] */
    TR(0x0b00f); /* 089d:263f cmp cx, word ptr [0x66] */
    TR(0x0b013); if ((int16_t)CX <= (int16_t)RW(DS_, 0x66)) goto L0b018; /* 089d:2643 jle 0xb018 */
    TR(0x0b015); CYC(12); DI = 0xffff; /* 089d:2645 mov di, 0xffff */
L0b018:
    TR(0x0b018); CYC(147); AX = RW(DS_, 0x60); /* 089d:2648 mov ax, word ptr [0x60] */
    TR(0x0b01b); WW(DS_, 0x4e, AX); /* 089d:264b mov word ptr [0x4e], ax */
    TR(0x0b01e); AX = RW(DS_, 0x62); /* 089d:264e mov ax, word ptr [0x62] */
    TR(0x0b021); WW(DS_, 0x52, AX); /* 089d:2651 mov word ptr [0x52], ax */
    TR(0x0b024); AX = CX; /* 089d:2654 mov ax, cx */
    TR(0x0b026); WW(DS_, 0x50, AX); /* 089d:2656 mov word ptr [0x50], ax */
    TR(0x0b029); AX = CX; /* 089d:2659 mov ax, cx */
    TR(0x0b02b); WW(DS_, 0x54, AX); /* 089d:265b mov word ptr [0x54], ax */
    TR(0x0b02e); PUSH(0x2661); goto L0af14; /* 089d:265e call 0xaf14 */
L0b031:
    TR(0x0b031); CYC(37); CX += DI; /* 089d:2661 add cx, di */
    TR(0x0b033); /* 089d:2663 cmp cx, word ptr [0x66] */
    TR(0x0b037); if (CX != RW(DS_, 0x66)) goto L0b018; /* 089d:2667 jne 0xb018 */
    TR(0x0b039); CYC(44); DI = POP(); /* 089d:2669 pop di */
    TR(0x0b03a); CX = POP(); /* 089d:266a pop cx */
    TR(0x0b03b); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:266b ret  */

/* ---- f_089d_266c */
L0b03c:
    TR(0x0b03c); CYC(44); WW(DS_, 0x50de, BX); /* 089d:266c mov word ptr [0x50de], bx */
    TR(0x0b040); WW(DS_, 0x50e0, CX); /* 089d:2670 mov word ptr [0x50e0], cx */
    TR(0x0b044); BX = DX; /* 089d:2674 mov bx, dx */
L0b046:
    TR(0x0b046); CYC(34); AL = RB(CS_, BX); /* 089d:2676 mov al, byte ptr cs:[bx] */
    TR(0x0b049); /* 089d:2679 cmp al, 0x24 */
    TR(0x0b04b); if (AL != 0x24) goto L0b04e; /* 089d:267b jne 0xb04e */
    TR(0x0b04d); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:267d ret  */
L0b04e:
    TR(0x0b04e); CYC(23); PUSH(0x2681); goto L0b0eb; /* 089d:267e call 0xb0eb */
L0b051:
    TR(0x0b051); CYC(19); BX++; /* 089d:2681 inc bx */
    TR(0x0b052); goto L0b046; /* 089d:2682 jmp 0xb046 */

/* ---- f_089d_2684 */
L0b054:
    TR(0x0b054); CYC(97); PUSH(ES_); /* 089d:2684 push es */
    TR(0x0b055); AX = 0x0; /* 089d:2685 mov ax, 0 */
    TR(0x0b058); ES_ = AX; /* 089d:2688 mov es, ax */
    TR(0x0b05a); /* 089d:268a nop  */
    TR(0x0b05b); AX = RW(ES_, 0x41c); /* 089d:268b mov ax, word ptr es:[0x41c] */
    TR(0x0b05f); /* 089d:268f cmp word ptr es:[0x41a], ax */
    TR(0x0b064); if (RW(ES_, 0x41a) != AX) goto L0b06c; /* 089d:2694 jne 0xb06c */
    TR(0x0b066); CYC(27); AX = 0x0; /* 089d:2696 mov ax, 0 */
    TR(0x0b069); goto L0b070; /* 089d:2699 jmp 0xb070 */
L0b06c:
    TR(0x0b06c); CYC(79); AH = 0x0; /* 089d:269c mov ah, 0 */
    TR(0x0b06e); while (or_int16_wait()) or_poll(); do_int(0x16); /* 089d:269e int 0x16 */
L0b070:
    TR(0x0b070); CYC(50); WW(DS_, 0x40, AX); /* 089d:26a0 mov word ptr [0x40], ax */
    TR(0x0b073); ES_ = POP(); /* 089d:26a3 pop es */
    TR(0x0b074); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:26a4 ret  */

/* ---- f_089d_26b3 */
L0b083:
    TR(0x0b083); CYC(47); PUSH(CX); /* 089d:26b3 push cx */
    TR(0x0b084); CL = 0x0; /* 089d:26b4 mov cl, 0 */
    TR(0x0b086); /* 089d:26b6 cmp dx, 0xa */
    TR(0x0b089); if (DX == 0xa) goto L0b0d3; /* 089d:26b9 je 0xb0d3 */
    TR(0x0b08b); CYC(24); /* 089d:26bb cmp dx, 0x64 */
    TR(0x0b08e); if (DX == 0x64) goto L0b0c0; /* 089d:26be je 0xb0c0 */
    TR(0x0b090); CYC(28); /* 089d:26c0 cmp dx, 0x3e8 */
    TR(0x0b094); if (DX == 0x3e8) goto L0b0ab; /* 089d:26c4 je 0xb0ab */
L0b096:
    TR(0x0b096); CYC(28); /* 089d:26c6 cmp bx, 0x2710 */
    TR(0x0b09a); if (BX < 0x2710) goto L0b0a4; /* 089d:26ca jb 0xb0a4 */
    TR(0x0b09c); CYC(39); BX -= 0x2710; /* 089d:26cc sub bx, 0x2710 */
    TR(0x0b0a0); CL++; /* 089d:26d0 inc cl */
    TR(0x0b0a2); goto L0b096; /* 089d:26d2 jmp 0xb096 */
L0b0a4:
    TR(0x0b0a4); CYC(31); AL = CL; /* 089d:26d4 mov al, cl */
    TR(0x0b0a6); PUSH(0x26d9); goto L0b160; /* 089d:26d6 call 0xb160 */
L0b0a9:
    TR(0x0b0a9); CYC(8); CL = 0x0; /* 089d:26d9 mov cl, 0 */
L0b0ab:
    TR(0x0b0ab); CYC(28); /* 089d:26db cmp bx, 0x3e8 */
    TR(0x0b0af); if (BX < 0x3e8) goto L0b0b9; /* 089d:26df jb 0xb0b9 */
    TR(0x0b0b1); CYC(39); BX -= 0x3e8; /* 089d:26e1 sub bx, 0x3e8 */
    TR(0x0b0b5); CL++; /* 089d:26e5 inc cl */
    TR(0x0b0b7); goto L0b0ab; /* 089d:26e7 jmp 0xb0ab */
L0b0b9:
    TR(0x0b0b9); CYC(31); AL = CL; /* 089d:26e9 mov al, cl */
    TR(0x0b0bb); PUSH(0x26ee); goto L0b160; /* 089d:26eb call 0xb160 */
L0b0be:
    TR(0x0b0be); CYC(8); CL = 0x0; /* 089d:26ee mov cl, 0 */
L0b0c0:
    TR(0x0b0c0); CYC(24); /* 089d:26f0 cmp bx, 0x64 */
    TR(0x0b0c3); if (BX < 0x64) goto L0b0cc; /* 089d:26f3 jb 0xb0cc */
    TR(0x0b0c5); CYC(35); BX -= 0x64; /* 089d:26f5 sub bx, 0x64 */
    TR(0x0b0c8); CL++; /* 089d:26f8 inc cl */
    TR(0x0b0ca); goto L0b0c0; /* 089d:26fa jmp 0xb0c0 */
L0b0cc:
    TR(0x0b0cc); CYC(31); AL = CL; /* 089d:26fc mov al, cl */
    TR(0x0b0ce); PUSH(0x2701); goto L0b160; /* 089d:26fe call 0xb160 */
L0b0d1:
    TR(0x0b0d1); CYC(8); CL = 0x0; /* 089d:2701 mov cl, 0 */
L0b0d3:
    TR(0x0b0d3); CYC(24); /* 089d:2703 cmp bx, 0xa */
    TR(0x0b0d6); if (BX < 0xa) goto L0b0df; /* 089d:2706 jb 0xb0df */
    TR(0x0b0d8); CYC(35); BX -= 0xa; /* 089d:2708 sub bx, 0xa */
    TR(0x0b0db); CL++; /* 089d:270b inc cl */
    TR(0x0b0dd); goto L0b0d3; /* 089d:270d jmp 0xb0d3 */
L0b0df:
    TR(0x0b0df); CYC(31); AL = CL; /* 089d:270f mov al, cl */
    TR(0x0b0e1); PUSH(0x2714); goto L0b160; /* 089d:2711 call 0xb160 */
L0b0e4:
    TR(0x0b0e4); CYC(31); AL = BL; /* 089d:2714 mov al, bl */
    TR(0x0b0e6); PUSH(0x2719); goto L0b160; /* 089d:2716 call 0xb160 */
L0b0e9:
    TR(0x0b0e9); CYC(32); CX = POP(); /* 089d:2719 pop cx */
    TR(0x0b0ea); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:271a ret  */

/* ---- f_089d_271b */
L0b0eb:
    TR(0x0b0eb); CYC(20); /* 089d:271b cmp al, 0x20 */
    TR(0x0b0ed); if (AL == 0x20) goto L0b123; /* 089d:271d je 0xb123 */
    TR(0x0b0ef); CYC(294); AH = 0x0; /* 089d:271f mov ah, 0 */
    TR(0x0b0f1); AX -= 0x41; /* 089d:2721 sub ax, 0x41 */
    TR(0x0b0f4); PUSH(BX); /* 089d:2724 push bx */
    TR(0x0b0f5); PUSH(CX); /* 089d:2725 push cx */
    TR(0x0b0f6); PUSH(DX); /* 089d:2726 push dx */
    TR(0x0b0f7); PUSH(SI); /* 089d:2727 push si */
    TR(0x0b0f8); PUSH(DI); /* 089d:2728 push di */
    TR(0x0b0f9); AX = AX; /* 089d:2729 mov ax, ax */
    TR(0x0b0fb); AX += AX; /* 089d:272b add ax, ax */
    TR(0x0b0fd); DI = AX; /* 089d:272d mov di, ax */
    TR(0x0b0ff); SI = RW(DS_, (uint16_t)(DI + 0x6f67)); /* 089d:272f mov si, word ptr [di + 0x6f67] */
    TR(0x0b103); DL = RB(DS_, SI); /* 089d:2733 mov dl, byte ptr [si] */
    TR(0x0b105); DH = DL; /* 089d:2735 mov dh, dl */
    TR(0x0b107); SI++; /* 089d:2737 inc si */
    TR(0x0b108); CH = RB(DS_, SI); /* 089d:2738 mov ch, byte ptr [si] */
    TR(0x0b10a); SI++; /* 089d:273a inc si */
    TR(0x0b10b); WW(DS_, 0x36, SI); /* 089d:273b mov word ptr [0x36], si */
    TR(0x0b10f); AX = RW(DS_, 0x50e0); /* 089d:273f mov ax, word ptr [0x50e0] */
    TR(0x0b112); WW(DS_, 0x2e, AX); /* 089d:2742 mov word ptr [0x2e], ax */
    TR(0x0b115); AX = RW(DS_, 0x50de); /* 089d:2745 mov ax, word ptr [0x50de] */
    TR(0x0b118); WW(DS_, 0x2c, AX); /* 089d:2748 mov word ptr [0x2c], ax */
    TR(0x0b11b); PUSH(0x274e); goto L0ae80; /* 089d:274b call 0xae80 */
L0b11e:
    TR(0x0b11e); CYC(60); DI = POP(); /* 089d:274e pop di */
    TR(0x0b11f); SI = POP(); /* 089d:274f pop si */
    TR(0x0b120); DX = POP(); /* 089d:2750 pop dx */
    TR(0x0b121); CX = POP(); /* 089d:2751 pop cx */
    TR(0x0b122); BX = POP(); /* 089d:2752 pop bx */
L0b123:
    TR(0x0b123); CYC(48); WW(DS_, 0x50de, (uint16_t)(RW(DS_, 0x50de) + 0x3)); /* 089d:2753 add word ptr [0x50de], 3 */
    TR(0x0b128); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2758 ret  */

/* ---- f_089d_2759 */
L0b129:
    TR(0x0b129); CYC(282); AH = 0x0; /* 089d:2759 mov ah, 0 */
    TR(0x0b12b); PUSH(BX); /* 089d:275b push bx */
    TR(0x0b12c); PUSH(CX); /* 089d:275c push cx */
    TR(0x0b12d); PUSH(DX); /* 089d:275d push dx */
    TR(0x0b12e); PUSH(SI); /* 089d:275e push si */
    TR(0x0b12f); PUSH(DI); /* 089d:275f push di */
    TR(0x0b130); AX = AX; /* 089d:2760 mov ax, ax */
    TR(0x0b132); AX += AX; /* 089d:2762 add ax, ax */
    TR(0x0b134); DI = AX; /* 089d:2764 mov di, ax */
    TR(0x0b136); SI = RW(DS_, (uint16_t)(DI + 0x6e6d)); /* 089d:2766 mov si, word ptr [di + 0x6e6d] */
    TR(0x0b13a); DL = RB(DS_, SI); /* 089d:276a mov dl, byte ptr [si] */
    TR(0x0b13c); DH = DL; /* 089d:276c mov dh, dl */
    TR(0x0b13e); SI++; /* 089d:276e inc si */
    TR(0x0b13f); CH = RB(DS_, SI); /* 089d:276f mov ch, byte ptr [si] */
    TR(0x0b141); SI++; /* 089d:2771 inc si */
    TR(0x0b142); WW(DS_, 0x36, SI); /* 089d:2772 mov word ptr [0x36], si */
    TR(0x0b146); AX = RW(DS_, 0x50e0); /* 089d:2776 mov ax, word ptr [0x50e0] */
    TR(0x0b149); WW(DS_, 0x2e, AX); /* 089d:2779 mov word ptr [0x2e], ax */
    TR(0x0b14c); AX = RW(DS_, 0x50de); /* 089d:277c mov ax, word ptr [0x50de] */
    TR(0x0b14f); WW(DS_, 0x2c, AX); /* 089d:277f mov word ptr [0x2c], ax */
    TR(0x0b152); PUSH(0x2785); goto L0ae80; /* 089d:2782 call 0xae80 */
L0b155:
    TR(0x0b155); CYC(108); DI = POP(); /* 089d:2785 pop di */
    TR(0x0b156); SI = POP(); /* 089d:2786 pop si */
    TR(0x0b157); DX = POP(); /* 089d:2787 pop dx */
    TR(0x0b158); CX = POP(); /* 089d:2788 pop cx */
    TR(0x0b159); BX = POP(); /* 089d:2789 pop bx */
    TR(0x0b15a); WW(DS_, 0x50de, (uint16_t)(RW(DS_, 0x50de) + 0x3)); /* 089d:278a add word ptr [0x50de], 3 */
    TR(0x0b15f); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:278f ret  */

/* ---- f_089d_2790 */
L0b160:
    TR(0x0b160); CYC(23); PUSH(0x2793); goto L0b129; /* 089d:2790 call 0xb129 */
L0b163:
    TR(0x0b163); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2793 ret  */

/* ---- f_089d_27a2 */
L0b172:
    TR(0x0b172); CYC(118); PUSH(BX); /* 089d:27a2 push bx */
    TR(0x0b173); AH = 0xb; /* 089d:27a3 mov ah, 0xb */
    TR(0x0b175); BH = 0x0; /* 089d:27a5 mov bh, 0 */
    TR(0x0b177); BL = RB(DS_, 0x68); /* 089d:27a7 mov bl, byte ptr [0x68] */
    TR(0x0b17b); do_int(0x10); /* 089d:27ab int 0x10 */
    TR(0x0b17d); CYC(103); AH = 0xb; /* 089d:27ad mov ah, 0xb */
    TR(0x0b17f); BH = 0x1; /* 089d:27af mov bh, 1 */
    TR(0x0b181); BL = RB(DS_, 0x6a); /* 089d:27b1 mov bl, byte ptr [0x6a] */
    TR(0x0b185); do_int(0x10); /* 089d:27b5 int 0x10 */
    TR(0x0b187); CYC(32); BX = POP(); /* 089d:27b7 pop bx */
    TR(0x0b188); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:27b8 ret  */

/* ---- f_089d_28aa */
L0b27a:
    TR(0x0b27a); CYC(79); AH = 0x0; /* 089d:28aa mov ah, 0 */
    TR(0x0b27c); while (or_int16_wait()) or_poll(); do_int(0x16); /* 089d:28ac int 0x16 */
    TR(0x0b27e); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:28ae ret  */

/* ---- f_089d_28af */
L0b27f:
    TR(0x0b27f); CYC(340); PUSH(BX); /* 089d:28af push bx */
    TR(0x0b280); PUSH(CX); /* 089d:28b0 push cx */
    TR(0x0b281); PUSH(DX); /* 089d:28b1 push dx */
    TR(0x0b282); PUSH(SI); /* 089d:28b2 push si */
    TR(0x0b283); PUSH(DI); /* 089d:28b3 push di */
    TR(0x0b284); AX = 0x0; /* 089d:28b4 mov ax, 0 */
    TR(0x0b287); AX += AX; /* 089d:28b7 add ax, ax */
    TR(0x0b289); DI = AX; /* 089d:28b9 mov di, ax */
    TR(0x0b28b); SI = RW(DS_, (uint16_t)(DI + 0x6bdc)); /* 089d:28bb mov si, word ptr [di + 0x6bdc] */
    TR(0x0b28f); DL = RB(DS_, SI); /* 089d:28bf mov dl, byte ptr [si] */
    TR(0x0b291); DH = DL; /* 089d:28c1 mov dh, dl */
    TR(0x0b293); SI++; /* 089d:28c3 inc si */
    TR(0x0b294); CH = RB(DS_, SI); /* 089d:28c4 mov ch, byte ptr [si] */
    TR(0x0b296); SI++; /* 089d:28c6 inc si */
    TR(0x0b297); WW(DS_, 0x36, SI); /* 089d:28c7 mov word ptr [0x36], si */
    TR(0x0b29b); AX = RW(DS_, 0x4172); /* 089d:28cb mov ax, word ptr [0x4172] */
    TR(0x0b29e); WW(DS_, 0x2e, AX); /* 089d:28ce mov word ptr [0x2e], ax */
    TR(0x0b2a1); BX = RW(DS_, 0x4170); /* 089d:28d1 mov bx, word ptr [0x4170] */
    TR(0x0b2a5); AX = RW(DS_, (uint16_t)(BX + 0x680e)); /* 089d:28d5 mov ax, word ptr [bx + 0x680e] */
    TR(0x0b2a9); AH = 0x0; /* 089d:28d9 mov ah, 0 */
    TR(0x0b2ab); WW(DS_, 0x2c, AX); /* 089d:28db mov word ptr [0x2c], ax */
    TR(0x0b2ae); AX = RW(DS_, (uint16_t)(BX + 0x695c)); /* 089d:28de mov ax, word ptr [bx + 0x695c] */
    TR(0x0b2b2); WW(DS_, 0x3a, AX); /* 089d:28e2 mov word ptr [0x3a], ax */
    TR(0x0b2b5); PUSH(0x28e8); goto L0ae25; /* 089d:28e5 call 0xae25 */
L0b2b8:
    TR(0x0b2b8); CYC(80); DI = POP(); /* 089d:28e8 pop di */
    TR(0x0b2b9); SI = POP(); /* 089d:28e9 pop si */
    TR(0x0b2ba); DX = POP(); /* 089d:28ea pop dx */
    TR(0x0b2bb); CX = POP(); /* 089d:28eb pop cx */
    TR(0x0b2bc); BX = POP(); /* 089d:28ec pop bx */
    TR(0x0b2bd); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:28ed ret  */

/* ---- f_089d_28ee */
L0b2be:
    TR(0x0b2be); CYC(143); WW(DS_, 0x60, 0x0); /* 089d:28ee mov word ptr [0x60], 0 */
    TR(0x0b2c4); WW(DS_, 0x62, 0x13f); /* 089d:28f4 mov word ptr [0x62], 0x13f */
    TR(0x0b2ca); WW(DS_, 0x64, 0xb4); /* 089d:28fa mov word ptr [0x64], 0xb4 */
    TR(0x0b2d0); WW(DS_, 0x66, 0xc7); /* 089d:2900 mov word ptr [0x66], 0xc7 */
    TR(0x0b2d6); WW(DS_, 0x2a, 0x1); /* 089d:2906 mov word ptr [0x2a], 1 */
    TR(0x0b2dc); PUSH(0x290f); goto L0affd; /* 089d:290c call 0xaffd */
L0b2df:
    TR(0x0b2df); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:290f ret  */

/* ---- f_089d_2910 */
L0b2e0:
    TR(0x0b2e0); CYC(40); /* 089d:2910 cmp word ptr [0x4176], 1 */
    TR(0x0b2e5); if (RW(DS_, 0x4176) == 0x1) goto L0b2e8; /* 089d:2915 je 0xb2e8 */
    TR(0x0b2e7); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2917 ret  */
L0b2e8:
    TR(0x0b2e8); CYC(23); PUSH(0x291b); goto L0b27f; /* 089d:2918 call 0xb27f */
L0b2eb:
    TR(0x0b2eb); CYC(40); /* 089d:291b cmp word ptr [0x40], 0x4800 */
    TR(0x0b2f1); if (RW(DS_, 0x40) != 0x4800) goto L0b301; /* 089d:2921 jne 0xb301 */
    TR(0x0b2f3); CYC(40); /* 089d:2923 cmp word ptr [0x4172], 0xa6 */
    TR(0x0b2f9); if (RW(DS_, 0x4172) != 0xa6) goto L0b301; /* 089d:2929 jne 0xb301 */
    TR(0x0b2fb); CYC(24); WW(DS_, 0x4174, 0xfff8); /* 089d:292b mov word ptr [0x4174], 0xfff8 */
L0b301:
    TR(0x0b301); CYC(121); AX = RW(DS_, 0x4174); /* 089d:2931 mov ax, word ptr [0x4174] */
    TR(0x0b304); { uint16_t a_ = AX; unsigned n_ = 1 & 0x1f; AX = (uint16_t)((int16_t)a_ >> n_); } /* 089d:2934 sar ax, 1 */
    TR(0x0b306); WW(DS_, 0x4172, (uint16_t)(RW(DS_, 0x4172) + AX)); /* 089d:2936 add word ptr [0x4172], ax */
    TR(0x0b30a); WW(DS_, 0x4174, (uint16_t)(RW(DS_, 0x4174) + 1)); /* 089d:293a inc word ptr [0x4174] */
    TR(0x0b30e); /* 089d:293e cmp word ptr [0x4172], 0xa6 */
    TR(0x0b314); if ((int16_t)RW(DS_, 0x4172) < (int16_t)0xa6) goto L0b322; /* 089d:2944 jl 0xb322 */
    TR(0x0b316); CYC(48); WW(DS_, 0x4172, 0xa6); /* 089d:2946 mov word ptr [0x4172], 0xa6 */
    TR(0x0b31c); WW(DS_, 0x4174, 0x0); /* 089d:294c mov word ptr [0x4174], 0 */
L0b322:
    TR(0x0b322); CYC(23); PUSH(0x2955); goto L0b27f; /* 089d:2952 call 0xb27f */
L0b325:
    TR(0x0b325); CYC(36); /* 089d:2955 cmp byte ptr [0x40], 0x20 */
    TR(0x0b32a); if (RB(DS_, 0x40) != 0x20) goto L0b338; /* 089d:295a jne 0xb338 */
    TR(0x0b32c); CYC(48); WW(DS_, 0x505c, 0x1); /* 089d:295c mov word ptr [0x505c], 1 */
    TR(0x0b332); WW(DS_, 0x5066, 0x1); /* 089d:2962 mov word ptr [0x5066], 1 */
L0b338:
    TR(0x0b338); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2968 ret  */

/* ---- f_089d_2969 */
L0b339:
    TR(0x0b339); CYC(23); PUSH(0x296c); goto L0b357; /* 089d:2969 call 0xb357 */
L0b33c:
    TR(0x0b33c); CYC(94); AX = RW(DS_, 0x4a); /* 089d:296c mov ax, word ptr [0x4a] */
    TR(0x0b33f); AX >>= 1; /* 089d:296f shr ax, 1 */
    TR(0x0b341); WW(DS_, 0x417a, (uint16_t)(RW(DS_, 0x417a) + AX)); /* 089d:2971 add word ptr [0x417a], ax */
    TR(0x0b345); /* 089d:2975 cmp word ptr [0x417a], 0xc76 */
    TR(0x0b34b); if ((int16_t)RW(DS_, 0x417a) < (int16_t)0xc76) goto L0b353; /* 089d:297b jl 0xb353 */
    TR(0x0b34d); CYC(24); WW(DS_, 0x417a, 0x0); /* 089d:297d mov word ptr [0x417a], 0 */
L0b353:
    TR(0x0b353); CYC(23); PUSH(0x2986); goto L0b357; /* 089d:2983 call 0xb357 */
L0b356:
    TR(0x0b356); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2986 ret  */

/* ---- f_089d_2987 */
L0b357:
    TR(0x0b357); CYC(42); { uint32_t k_ = or_fast(0x0b357); if (k_) { jkey = k_; goto dispatch; } } SI = RW(DS_, 0x417a); /* 089d:2987 mov si, word ptr [0x417a] */
    TR(0x0b35b); WW(DS_, 0x2c, 0x0); /* 089d:298b mov word ptr [0x2c], 0 */
L0b361:
    TR(0x0b361); CYC(36); CX = 0x4; /* 089d:2991 mov cx, 4 */
    TR(0x0b364); WW(DS_, 0x417c, 0x80); /* 089d:2994 mov word ptr [0x417c], 0x80 */
L0b36a:
    TR(0x0b36a); CYC(47); BL = RB(DS_, (uint16_t)(SI + 0x417e)); /* 089d:299a mov bl, byte ptr [si + 0x417e] */
    TR(0x0b36e); BH = 0x0; /* 089d:299e mov bh, 0 */
    TR(0x0b370); PUSH(0x29a3); goto L0aeca; /* 089d:29a0 call 0xaeca */
L0b373:
    TR(0x0b373); CYC(78); AX = RW(DS_, 0x417c); /* 089d:29a3 mov ax, word ptr [0x417c] */
    TR(0x0b376); WW(ES_, BX, (uint16_t)(RW(ES_, BX) ^ AX)); /* 089d:29a6 xor word ptr es:[bx], ax */
    TR(0x0b379); SI++; /* 089d:29a9 inc si */
    TR(0x0b37a); { uint16_t a_ = SI, b_ = 0xc77; unsigned r_ = (unsigned)a_ - b_;   ZF = ((r_ & 0xffff) == 0);   CF = ((r_ >> 16) & 1); } /* 089d:29aa cmp si, 0xc77 */
    TR(0x0b37e); if (!ZF) goto L0b383; /* 089d:29ae jne 0xb383 */
    TR(0x0b380); CYC(12); SI = 0x0; /* 089d:29b0 mov si, 0 */
L0b383:
    TR(0x0b383); CYC(36); CL = 0x2; /* 089d:29b3 mov cl, 2 */
    TR(0x0b385); { uint16_t a_ = RW(DS_, 0x417c); unsigned n_ = CL & 0x1f, k_ = n_ % 16;   if (n_) { uint16_t r_ = k_ ? (uint16_t)((a_ >> k_) | (a_ << (16 - k_))) : a_;     WW(DS_, 0x417c, r_);     CF = (r_ >> 15) & 1;   } } /* 089d:29b5 ror word ptr [0x417c], cl */
    TR(0x0b389); if (!CF) goto L0b36a; /* 089d:29b9 jae 0xb36a */
    TR(0x0b38b); CYC(67); WW(DS_, 0x2c, (uint16_t)(RW(DS_, 0x2c) + 1)); /* 089d:29bb inc word ptr [0x2c] */
    TR(0x0b38f); /* 089d:29bf cmp word ptr [0x2c], 0x50 */
    TR(0x0b394); if (RW(DS_, 0x2c) != 0x50) goto L0b361; /* 089d:29c4 jne 0xb361 */
    TR(0x0b396); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:29c6 ret  */

/* ---- f_089d_29c7 */
L0b397:
    TR(0x0b397); CYC(72); CX = 0xc76; /* 089d:29c7 mov cx, 0xc76 */
    TR(0x0b39a); BX = 0x417e; /* 089d:29ca mov bx, 0x417e */
    TR(0x0b39d); WW(DS_, 0x44, 0x64); /* 089d:29cd mov word ptr [0x44], 0x64 */
    TR(0x0b3a3); WW(DS_, 0x50, 0x64); /* 089d:29d3 mov word ptr [0x50], 0x64 */
L0b3a9:
    TR(0x0b3a9); CYC(82); WW(DS_, 0x46, 0xffff); /* 089d:29d9 mov word ptr [0x46], 0xffff */
    TR(0x0b3af); AX = RW(DS_, 0x50); /* 089d:29df mov ax, word ptr [0x50] */
    TR(0x0b3b2); /* 089d:29e2 cmp word ptr [0x44], ax */
    TR(0x0b3b6); if ((int16_t)RW(DS_, 0x44) < (int16_t)AX) goto L0b3be; /* 089d:29e6 jl 0xb3be */
    TR(0x0b3b8); CYC(24); WW(DS_, 0x46, 0x1); /* 089d:29e8 mov word ptr [0x46], 1 */
L0b3be:
    TR(0x0b3be); CYC(40); /* 089d:29ee cmp word ptr [0x44], ax */
    TR(0x0b3c2); if (RW(DS_, 0x44) != AX) goto L0b3e3; /* 089d:29f2 jne 0xb3e3 */
L0b3c4:
    TR(0x0b3c4); CYC(23); PUSH(0x29f7); goto L0b412; /* 089d:29f4 call 0xb412 */
L0b3c7:
    TR(0x0b3c7); CYC(32); AH = 0x0; /* 089d:29f7 mov ah, 0 */
    TR(0x0b3c9); /* 089d:29f9 cmp ax, 0x64 */
    TR(0x0b3cc); if ((int16_t)AX > (int16_t)0x64) goto L0b3c4; /* 089d:29fc jg 0xb3c4 */
    TR(0x0b3ce); CYC(30); AX += 0x32; /* 089d:29fe add ax, 0x32 */
    TR(0x0b3d1); WW(DS_, 0x44, AX); /* 089d:2a01 mov word ptr [0x44], ax */
L0b3d4:
    TR(0x0b3d4); CYC(23); PUSH(0x2a07); goto L0b412; /* 089d:2a04 call 0xb412 */
L0b3d7:
    TR(0x0b3d7); CYC(20); /* 089d:2a07 cmp al, 0 */
    TR(0x0b3d9); if (AL == 0x0) goto L0b3d4; /* 089d:2a09 je 0xb3d4 */
    TR(0x0b3db); CYC(24); /* 089d:2a0b cmp ax, 0x1e */
    TR(0x0b3de); if ((int16_t)AX > (int16_t)0x1e) goto L0b3d4; /* 089d:2a0e jg 0xb3d4 */
    TR(0x0b3e0); CYC(18); WW(DS_, 0x42, AX); /* 089d:2a10 mov word ptr [0x42], ax */
L0b3e3:
    TR(0x0b3e3); CYC(40); /* 089d:2a13 cmp word ptr [0x42], 0 */
    TR(0x0b3e8); if (RW(DS_, 0x42) == 0x0) goto L0b3f4; /* 089d:2a18 je 0xb3f4 */
    TR(0x0b3ea); CYC(51); WW(DS_, 0x42, (uint16_t)(RW(DS_, 0x42) - 1)); /* 089d:2a1a dec word ptr [0x42] */
    TR(0x0b3ee); WW(DS_, 0x46, 0x0); /* 089d:2a1e mov word ptr [0x46], 0 */
L0b3f4:
    TR(0x0b3f4); CYC(24); /* 089d:2a24 cmp cx, 0x4b */
    TR(0x0b3f7); if ((int16_t)CX > (int16_t)0x4b) goto L0b3ff; /* 089d:2a27 jg 0xb3ff */
    TR(0x0b3f9); CYC(24); WW(DS_, 0x44, 0x64); /* 089d:2a29 mov word ptr [0x44], 0x64 */
L0b3ff:
    TR(0x0b3ff); CYC(103); AX = RW(DS_, 0x50); /* 089d:2a2f mov ax, word ptr [0x50] */
    TR(0x0b402); WW(DS_, BX, AX); /* 089d:2a32 mov word ptr [bx], ax */
    TR(0x0b404); BX++; /* 089d:2a34 inc bx */
    TR(0x0b405); AX = RW(DS_, 0x46); /* 089d:2a35 mov ax, word ptr [0x46] */
    TR(0x0b408); WW(DS_, 0x50, (uint16_t)(RW(DS_, 0x50) + AX)); /* 089d:2a38 add word ptr [0x50], ax */
    TR(0x0b40c); if (--CX) goto L0b3a9; /* 089d:2a3c loop 0xb3a9 */
    TR(0x0b40e); CYC(34); WB(DS_, BX, 0x64); /* 089d:2a3e mov byte ptr [bx], 0x64 */
    TR(0x0b411); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2a41 ret  */

/* ---- f_089d_2a42 */
L0b412:
    TR(0x0b412); CYC(177); { uint32_t k_ = or_fast(0x0b412); if (k_) { jkey = k_; goto dispatch; } } AL = 0x0; /* 089d:2a42 mov al, 0 */
    TR(0x0b414); io_out(0x43, AL); /* 089d:2a44 out 0x43, al */
    TR(0x0b416); AL = io_in(0x40); /* 089d:2a46 in al, 0x40 */
    TR(0x0b418); AL += RB(DS_, 0x4dfa); /* 089d:2a48 add al, byte ptr [0x4dfa] */
    TR(0x0b41c); AL += RB(DS_, 0x4dfb); /* 089d:2a4c add al, byte ptr [0x4dfb] */
    TR(0x0b420); PUSH(AX); /* 089d:2a50 push ax */
    TR(0x0b421); AL = RB(DS_, 0x4dfa); /* 089d:2a51 mov al, byte ptr [0x4dfa] */
    TR(0x0b424); WB(DS_, 0x4df9, AL); /* 089d:2a54 mov byte ptr [0x4df9], al */
    TR(0x0b427); AL = RB(DS_, 0x4dfb); /* 089d:2a57 mov al, byte ptr [0x4dfb] */
    TR(0x0b42a); WB(DS_, 0x4dfa, AL); /* 089d:2a5a mov byte ptr [0x4dfa], al */
    TR(0x0b42d); AX = POP(); /* 089d:2a5d pop ax */
    TR(0x0b42e); WB(DS_, 0x4dfb, AL); /* 089d:2a5e mov byte ptr [0x4dfb], al */
    TR(0x0b431); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2a61 ret  */

/* ---- f_089d_2a62 */
L0b432:
    TR(0x0b432); CYC(40); /* 089d:2a62 cmp word ptr [bx + 0x4dfc], 0x138 */
    TR(0x0b438); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x4dfc)) > (int16_t)0x138) goto L0b47f; /* 089d:2a68 jg 0xb47f */
    TR(0x0b43a); CYC(40); /* 089d:2a6a cmp word ptr [0x4dfc], 0 */
    TR(0x0b43f); if ((int16_t)RW(DS_, 0x4dfc) < (int16_t)0x0) goto L0b47f; /* 089d:2a6f jl 0xb47f */
    TR(0x0b441); CYC(334); PUSH(BX); /* 089d:2a71 push bx */
    TR(0x0b442); PUSH(CX); /* 089d:2a72 push cx */
    TR(0x0b443); PUSH(DX); /* 089d:2a73 push dx */
    TR(0x0b444); PUSH(SI); /* 089d:2a74 push si */
    TR(0x0b445); PUSH(DI); /* 089d:2a75 push di */
    TR(0x0b446); AX = 0x0; /* 089d:2a76 mov ax, 0 */
    TR(0x0b449); AX += AX; /* 089d:2a79 add ax, ax */
    TR(0x0b44b); DI = AX; /* 089d:2a7b mov di, ax */
    TR(0x0b44d); SI = RW(DS_, (uint16_t)(DI + 0x6c26)); /* 089d:2a7d mov si, word ptr [di + 0x6c26] */
    TR(0x0b451); DL = RB(DS_, SI); /* 089d:2a81 mov dl, byte ptr [si] */
    TR(0x0b453); DH = DL; /* 089d:2a83 mov dh, dl */
    TR(0x0b455); SI++; /* 089d:2a85 inc si */
    TR(0x0b456); CH = RB(DS_, SI); /* 089d:2a86 mov ch, byte ptr [si] */
    TR(0x0b458); SI++; /* 089d:2a88 inc si */
    TR(0x0b459); WW(DS_, 0x36, SI); /* 089d:2a89 mov word ptr [0x36], si */
    TR(0x0b45d); AX = 0xad; /* 089d:2a8d mov ax, 0xad */
    TR(0x0b460); WW(DS_, 0x2e, AX); /* 089d:2a90 mov word ptr [0x2e], ax */
    TR(0x0b463); BX = RW(DS_, (uint16_t)(BX + 0x4dfc)); /* 089d:2a93 mov bx, word ptr [bx + 0x4dfc] */
    TR(0x0b467); AX = RW(DS_, (uint16_t)(BX + 0x680e)); /* 089d:2a97 mov ax, word ptr [bx + 0x680e] */
    TR(0x0b46b); AH = 0x0; /* 089d:2a9b mov ah, 0 */
    TR(0x0b46d); WW(DS_, 0x2c, AX); /* 089d:2a9d mov word ptr [0x2c], ax */
    TR(0x0b470); AX = RW(DS_, (uint16_t)(BX + 0x695c)); /* 089d:2aa0 mov ax, word ptr [bx + 0x695c] */
    TR(0x0b474); WW(DS_, 0x3a, AX); /* 089d:2aa4 mov word ptr [0x3a], ax */
    TR(0x0b477); PUSH(0x2aaa); goto L0ae25; /* 089d:2aa7 call 0xae25 */
L0b47a:
    TR(0x0b47a); CYC(60); DI = POP(); /* 089d:2aaa pop di */
    TR(0x0b47b); SI = POP(); /* 089d:2aab pop si */
    TR(0x0b47c); DX = POP(); /* 089d:2aac pop dx */
    TR(0x0b47d); CX = POP(); /* 089d:2aad pop cx */
    TR(0x0b47e); BX = POP(); /* 089d:2aae pop bx */
L0b47f:
    TR(0x0b47f); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2aaf ret  */

/* ---- f_089d_2ab0 */
L0b480:
    TR(0x0b480); CYC(30); VH(0x0b480); BX = 0x0; /* 089d:2ab0 mov bx, 0 */
    TR(0x0b483); CX = RW(DS_, 0x4e60); /* 089d:2ab3 mov cx, word ptr [0x4e60] */
L0b487:
    TR(0x0b487); CYC(23); PUSH(0x2aba); goto L0b432; /* 089d:2ab7 call 0xb432 */
L0b48a:
    TR(0x0b48a); CYC(94); AX = RW(DS_, 0x4a); /* 089d:2aba mov ax, word ptr [0x4a] */
    TR(0x0b48d); AX = (uint16_t)(0u - AX); /* 089d:2abd neg ax */
    TR(0x0b48f); WW(DS_, (uint16_t)(BX + 0x4dfc), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x4dfc)) + AX)); /* 089d:2abf add word ptr [bx + 0x4dfc], ax */
    TR(0x0b493); /* 089d:2ac3 cmp word ptr [bx + 0x4dfc], 0 */
    TR(0x0b498); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x4dfc)) >= (int16_t)0x0) goto L0b4a0; /* 089d:2ac8 jge 0xb4a0 */
    TR(0x0b49a); CYC(24); WW(DS_, (uint16_t)(BX + 0x4dfc), 0x18ec); /* 089d:2aca mov word ptr [bx + 0x4dfc], 0x18ec */
L0b4a0:
    TR(0x0b4a0); CYC(23); PUSH(0x2ad3); goto L0b432; /* 089d:2ad0 call 0xb432 */
L0b4a3:
    TR(0x0b4a3); CYC(25); BX++; /* 089d:2ad3 inc bx */
    TR(0x0b4a4); BX++; /* 089d:2ad4 inc bx */
    TR(0x0b4a5); if (--CX) goto L0b487; /* 089d:2ad5 loop 0xb487 */
    TR(0x0b4a7); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2ad7 ret  */

/* ---- f_089d_2ad8 */
L0b4a8:
    TR(0x0b4a8); CYC(40); /* 089d:2ad8 cmp word ptr [0x4176], 1 */
    TR(0x0b4ad); if (RW(DS_, 0x4176) != 0x1) goto L0b4f1; /* 089d:2add jne 0xb4f1 */
    TR(0x0b4af); CYC(40); /* 089d:2adf cmp word ptr [0x4172], 0xa6 */
    TR(0x0b4b5); if (RW(DS_, 0x4172) != 0xa6) goto L0b4f1; /* 089d:2ae5 jne 0xb4f1 */
    TR(0x0b4b7); CYC(40); /* 089d:2ae7 cmp word ptr [0x40], 0x4d00 */
    TR(0x0b4bd); if (RW(DS_, 0x40) != 0x4d00) goto L0b4d4; /* 089d:2aed jne 0xb4d4 */
    TR(0x0b4bf); CYC(94); WW(DS_, 0x4a, (uint16_t)(RW(DS_, 0x4a) + 1)); /* 089d:2aef inc word ptr [0x4a] */
    TR(0x0b4c3); WW(DS_, 0x4a, (uint16_t)(RW(DS_, 0x4a) + 1)); /* 089d:2af3 inc word ptr [0x4a] */
    TR(0x0b4c7); /* 089d:2af7 cmp word ptr [0x4a], 0xa */
    TR(0x0b4cc); if ((int16_t)RW(DS_, 0x4a) <= (int16_t)0xa) goto L0b4d4; /* 089d:2afc jle 0xb4d4 */
    TR(0x0b4ce); CYC(24); WW(DS_, 0x4a, 0xa); /* 089d:2afe mov word ptr [0x4a], 0xa */
L0b4d4:
    TR(0x0b4d4); CYC(40); /* 089d:2b04 cmp word ptr [0x40], 0x4b00 */
    TR(0x0b4da); if (RW(DS_, 0x40) != 0x4b00) goto L0b4f1; /* 089d:2b0a jne 0xb4f1 */
    TR(0x0b4dc); CYC(94); WW(DS_, 0x4a, (uint16_t)(RW(DS_, 0x4a) - 1)); /* 089d:2b0c dec word ptr [0x4a] */
    TR(0x0b4e0); WW(DS_, 0x4a, (uint16_t)(RW(DS_, 0x4a) - 1)); /* 089d:2b10 dec word ptr [0x4a] */
    TR(0x0b4e4); /* 089d:2b14 cmp word ptr [0x4a], 0 */
    TR(0x0b4e9); if ((int16_t)RW(DS_, 0x4a) >= (int16_t)0x0) goto L0b4f1; /* 089d:2b19 jge 0xb4f1 */
    TR(0x0b4eb); CYC(24); WW(DS_, 0x4a, 0x0); /* 089d:2b1b mov word ptr [0x4a], 0 */
L0b4f1:
    TR(0x0b4f1); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2b21 ret  */

/* ---- f_089d_2b22 */
L0b4f2:
    TR(0x0b4f2); CYC(40); /* 089d:2b22 cmp word ptr [bx + 0x4e62], 0x12b */
    TR(0x0b4f8); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x4e62)) > (int16_t)0x12b) goto L0b540; /* 089d:2b28 jg 0xb540 */
    TR(0x0b4fa); CYC(40); /* 089d:2b2a cmp word ptr [bx + 0x4e62], 0 */
    TR(0x0b4ff); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x4e62)) < (int16_t)0x0) goto L0b540; /* 089d:2b2f jl 0xb540 */
    TR(0x0b501); CYC(340); PUSH(BX); /* 089d:2b31 push bx */
    TR(0x0b502); PUSH(CX); /* 089d:2b32 push cx */
    TR(0x0b503); PUSH(DX); /* 089d:2b33 push dx */
    TR(0x0b504); PUSH(SI); /* 089d:2b34 push si */
    TR(0x0b505); PUSH(DI); /* 089d:2b35 push di */
    TR(0x0b506); AX = RW(DS_, (uint16_t)(BX + 0x4ec6)); /* 089d:2b36 mov ax, word ptr [bx + 0x4ec6] */
    TR(0x0b50a); AX += AX; /* 089d:2b3a add ax, ax */
    TR(0x0b50c); DI = AX; /* 089d:2b3c mov di, ax */
    TR(0x0b50e); SI = RW(DS_, (uint16_t)(DI + 0x6c38)); /* 089d:2b3e mov si, word ptr [di + 0x6c38] */
    TR(0x0b512); DL = RB(DS_, SI); /* 089d:2b42 mov dl, byte ptr [si] */
    TR(0x0b514); DH = DL; /* 089d:2b44 mov dh, dl */
    TR(0x0b516); SI++; /* 089d:2b46 inc si */
    TR(0x0b517); CH = RB(DS_, SI); /* 089d:2b47 mov ch, byte ptr [si] */
    TR(0x0b519); SI++; /* 089d:2b49 inc si */
    TR(0x0b51a); WW(DS_, 0x36, SI); /* 089d:2b4a mov word ptr [0x36], si */
    TR(0x0b51e); AX = 0xab; /* 089d:2b4e mov ax, 0xab */
    TR(0x0b521); WW(DS_, 0x2e, AX); /* 089d:2b51 mov word ptr [0x2e], ax */
    TR(0x0b524); BX = RW(DS_, (uint16_t)(BX + 0x4e62)); /* 089d:2b54 mov bx, word ptr [bx + 0x4e62] */
    TR(0x0b528); AX = RW(DS_, (uint16_t)(BX + 0x680e)); /* 089d:2b58 mov ax, word ptr [bx + 0x680e] */
    TR(0x0b52c); AH = 0x0; /* 089d:2b5c mov ah, 0 */
    TR(0x0b52e); WW(DS_, 0x2c, AX); /* 089d:2b5e mov word ptr [0x2c], ax */
    TR(0x0b531); AX = RW(DS_, (uint16_t)(BX + 0x695c)); /* 089d:2b61 mov ax, word ptr [bx + 0x695c] */
    TR(0x0b535); WW(DS_, 0x3a, AX); /* 089d:2b65 mov word ptr [0x3a], ax */
    TR(0x0b538); PUSH(0x2b6b); goto L0ae25; /* 089d:2b68 call 0xae25 */
L0b53b:
    TR(0x0b53b); CYC(60); DI = POP(); /* 089d:2b6b pop di */
    TR(0x0b53c); SI = POP(); /* 089d:2b6c pop si */
    TR(0x0b53d); DX = POP(); /* 089d:2b6d pop dx */
    TR(0x0b53e); CX = POP(); /* 089d:2b6e pop cx */
    TR(0x0b53f); BX = POP(); /* 089d:2b6f pop bx */
L0b540:
    TR(0x0b540); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2b70 ret  */

/* ---- f_089d_2b71 */
L0b541:
    TR(0x0b541); CYC(40); /* 089d:2b71 cmp word ptr [0x4ff4], 1 */
    TR(0x0b546); if (RW(DS_, 0x4ff4) == 0x1) goto L0b549; /* 089d:2b76 je 0xb549 */
    TR(0x0b548); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2b78 ret  */
L0b549:
    TR(0x0b549); CYC(30); CX = RW(DS_, 0x4ff2); /* 089d:2b79 mov cx, word ptr [0x4ff2] */
    TR(0x0b54d); BX = 0x0; /* 089d:2b7d mov bx, 0 */
L0b550:
    TR(0x0b550); CYC(40); /* 089d:2b80 cmp word ptr [bx + 0x4f2a], 0 */
    TR(0x0b555); if (RW(DS_, (uint16_t)(BX + 0x4f2a)) == 0x0) goto L0b55a; /* 089d:2b85 je 0xb55a */
    TR(0x0b557); CYC(23); PUSH(0x2b8a); goto L0b55f; /* 089d:2b87 call 0xb55f */
L0b55a:
    TR(0x0b55a); CYC(25); BX++; /* 089d:2b8a inc bx */
    TR(0x0b55b); BX++; /* 089d:2b8b inc bx */
    TR(0x0b55c); if (--CX) goto L0b550; /* 089d:2b8c loop 0xb550 */
    TR(0x0b55e); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2b8e ret  */

/* ---- f_089d_2b8f */
L0b55f:
    TR(0x0b55f); CYC(23); PUSH(0x2b92); goto L0b4f2; /* 089d:2b8f call 0xb4f2 */
L0b562:
    TR(0x0b562); CYC(94); AX = RW(DS_, 0x4a); /* 089d:2b92 mov ax, word ptr [0x4a] */
    TR(0x0b565); AX = (uint16_t)(0u - AX); /* 089d:2b95 neg ax */
    TR(0x0b567); WW(DS_, (uint16_t)(BX + 0x4e62), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x4e62)) + AX)); /* 089d:2b97 add word ptr [bx + 0x4e62], ax */
    TR(0x0b56b); /* 089d:2b9b cmp word ptr [bx + 0x4e62], 0 */
    TR(0x0b570); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x4e62)) >= (int16_t)0x0) goto L0b578; /* 089d:2ba0 jge 0xb578 */
    TR(0x0b572); CYC(24); WW(DS_, (uint16_t)(BX + 0x4e62), 0x18ec); /* 089d:2ba2 mov word ptr [bx + 0x4e62], 0x18ec */
L0b578:
    TR(0x0b578); CYC(23); PUSH(0x2bab); goto L0b4f2; /* 089d:2ba8 call 0xb4f2 */
L0b57b:
    TR(0x0b57b); CYC(45); PUSH(CX); /* 089d:2bab push cx */
    TR(0x0b57c); CX = RW(DS_, 0x5062); /* 089d:2bac mov cx, word ptr [0x5062] */
    TR(0x0b580); SI = 0x0; /* 089d:2bb0 mov si, 0 */
L0b583:
    TR(0x0b583); CYC(40); /* 089d:2bb3 cmp word ptr [si + 0x501e], 0 */
    TR(0x0b588); if (RW(DS_, (uint16_t)(SI + 0x501e)) == 0x0) goto L0b5d8; /* 089d:2bb8 je 0xb5d8 */
    TR(0x0b58a); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x4e62)); /* 089d:2bba mov ax, word ptr [bx + 0x4e62] */
    TR(0x0b58e); /* 089d:2bbe cmp word ptr [si + 0x4ff6], ax */
    TR(0x0b592); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x4ff6)) < (int16_t)AX) goto L0b5d8; /* 089d:2bc2 jl 0xb5d8 */
    TR(0x0b594); CYC(52); AX += 0x14; /* 089d:2bc4 add ax, 0x14 */
    TR(0x0b597); /* 089d:2bc7 cmp word ptr [si + 0x4ff6], ax */
    TR(0x0b59b); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x4ff6)) > (int16_t)AX) goto L0b5d8; /* 089d:2bcb jg 0xb5d8 */
    TR(0x0b59d); CYC(52); AX = 0xaa; /* 089d:2bcd mov ax, 0xaa */
    TR(0x0b5a0); /* 089d:2bd0 cmp word ptr [si + 0x500a], ax */
    TR(0x0b5a4); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) < (int16_t)AX) goto L0b5d8; /* 089d:2bd4 jl 0xb5d8 */
    TR(0x0b5a6); CYC(154); WW(DS_, 0x50d6, 0x1); /* 089d:2bd6 mov word ptr [0x50d6], 1 */
    TR(0x0b5ac); AX = RW(DS_, (uint16_t)(BX + 0x4e62)); /* 089d:2bdc mov ax, word ptr [bx + 0x4e62] */
    TR(0x0b5b0); WW(DS_, 0x50d8, AX); /* 089d:2be0 mov word ptr [0x50d8], ax */
    TR(0x0b5b3); WW(DS_, 0x50da, 0xa1); /* 089d:2be3 mov word ptr [0x50da], 0xa1 */
    TR(0x0b5b9); WW(DS_, (uint16_t)(SI + 0x501e), 0x0); /* 089d:2be9 mov word ptr [si + 0x501e], 0 */
    TR(0x0b5bf); PUSH(BX); /* 089d:2bef push bx */
    TR(0x0b5c0); BX = SI; /* 089d:2bf0 mov bx, si */
    TR(0x0b5c2); PUSH(0x2bf5); goto L0b66e; /* 089d:2bf2 call 0xb66e */
L0b5c5:
    TR(0x0b5c5); CYC(59); BX = POP(); /* 089d:2bf5 pop bx */
    TR(0x0b5c6); WW(DS_, (uint16_t)(BX + 0x4f2a), 0x0); /* 089d:2bf6 mov word ptr [bx + 0x4f2a], 0 */
    TR(0x0b5cc); PUSH(0x2bff); goto L0b4f2; /* 089d:2bfc call 0xb4f2 */
L0b5cf:
    TR(0x0b5cf); CYC(35); AX = 0xa; /* 089d:2bff mov ax, 0xa */
    TR(0x0b5d2); PUSH(0x2c05); goto L0b829; /* 089d:2c02 call 0xb829 */
L0b5d5:
    TR(0x0b5d5); CYC(15); goto L0b5dc; /* 089d:2c05 jmp 0xb5dc */
L0b5d8:
    TR(0x0b5d8); CYC(25); SI++; /* 089d:2c08 inc si */
    TR(0x0b5d9); SI++; /* 089d:2c09 inc si */
    TR(0x0b5da); if (--CX) goto L0b583; /* 089d:2c0a loop 0xb583 */
L0b5dc:
    TR(0x0b5dc); CYC(52); CX = POP(); /* 089d:2c0c pop cx */
    TR(0x0b5dd); /* 089d:2c0d cmp word ptr [bx + 0x4f8e], 1 */
    TR(0x0b5e2); if (RW(DS_, (uint16_t)(BX + 0x4f8e)) == 0x1) goto L0b61f; /* 089d:2c12 je 0xb61f */
    TR(0x0b5e4); CYC(59); AX = RW(DS_, (uint16_t)(BX + 0x4e62)); /* 089d:2c14 mov ax, word ptr [bx + 0x4e62] */
    TR(0x0b5e8); AX += 0x14; /* 089d:2c18 add ax, 0x14 */
    TR(0x0b5eb); /* 089d:2c1b cmp ax, word ptr [0x4170] */
    TR(0x0b5ef); if ((int16_t)AX > (int16_t)RW(DS_, 0x4170)) goto L0b61f; /* 089d:2c1f jg 0xb61f */
    TR(0x0b5f1); CYC(59); WW(DS_, (uint16_t)(BX + 0x4f8e), 0x1); /* 089d:2c21 mov word ptr [bx + 0x4f8e], 1 */
    TR(0x0b5f7); AX = 0x19; /* 089d:2c27 mov ax, 0x19 */
    TR(0x0b5fa); PUSH(0x2c2d); goto L0b829; /* 089d:2c2a call 0xb829 */
L0b5fd:
    TR(0x0b5fd); CYC(144); WW(DS_, 0x5160, 0x1); /* 089d:2c2d mov word ptr [0x5160], 1 */
    TR(0x0b603); AX = RW(DS_, (uint16_t)(BX + 0x4e62)); /* 089d:2c33 mov ax, word ptr [bx + 0x4e62] */
    TR(0x0b607); AX += 0x5; /* 089d:2c37 add ax, 5 */
    TR(0x0b60a); WW(DS_, 0x5162, AX); /* 089d:2c3a mov word ptr [0x5162], ax */
    TR(0x0b60d); WW(DS_, 0x5164, 0xa5); /* 089d:2c3d mov word ptr [0x5164], 0xa5 */
    TR(0x0b613); WW(DS_, 0x5166, 0x0); /* 089d:2c43 mov word ptr [0x5166], 0 */
    TR(0x0b619); WW(DS_, 0x516a, 0x0); /* 089d:2c49 mov word ptr [0x516a], 0 */
L0b61f:
    TR(0x0b61f); CYC(40); /* 089d:2c4f cmp word ptr [0x4176], 1 */
    TR(0x0b624); if (RW(DS_, 0x4176) != 0x1) goto L0b66d; /* 089d:2c54 jne 0xb66d */
    TR(0x0b626); CYC(68); AX = RW(DS_, 0x4170); /* 089d:2c56 mov ax, word ptr [0x4170] */
    TR(0x0b629); DX = RW(DS_, (uint16_t)(BX + 0x4e62)); /* 089d:2c59 mov dx, word ptr [bx + 0x4e62] */
    TR(0x0b62d); AX += 0x14; /* 089d:2c5d add ax, 0x14 */
    TR(0x0b630); /* 089d:2c60 cmp ax, dx */
    TR(0x0b632); if ((int16_t)AX < (int16_t)DX) goto L0b66d; /* 089d:2c62 jl 0xb66d */
    TR(0x0b634); CYC(44); AX -= 0x14; /* 089d:2c64 sub ax, 0x14 */
    TR(0x0b637); DX += 0x14; /* 089d:2c67 add dx, 0x14 */
    TR(0x0b63a); /* 089d:2c6a cmp ax, dx */
    TR(0x0b63c); if ((int16_t)AX > (int16_t)DX) goto L0b66d; /* 089d:2c6c jg 0xb66d */
    TR(0x0b63e); CYC(62); AX = RW(DS_, 0x4172); /* 089d:2c6e mov ax, word ptr [0x4172] */
    TR(0x0b641); DX = 0xab; /* 089d:2c71 mov dx, 0xab */
    TR(0x0b644); AX += 0xe; /* 089d:2c74 add ax, 0xe */
    TR(0x0b647); /* 089d:2c77 cmp ax, dx */
    TR(0x0b649); if ((int16_t)AX < (int16_t)DX) goto L0b66d; /* 089d:2c79 jl 0xb66d */
    TR(0x0b64b); CYC(155); WW(DS_, 0x5360, 0x1); /* 089d:2c7b mov word ptr [0x5360], 1 */
    TR(0x0b651); WW(DS_, 0x50d6, 0x1); /* 089d:2c81 mov word ptr [0x50d6], 1 */
    TR(0x0b657); AX = RW(DS_, (uint16_t)(BX + 0x4e62)); /* 089d:2c87 mov ax, word ptr [bx + 0x4e62] */
    TR(0x0b65b); WW(DS_, 0x50d8, AX); /* 089d:2c8b mov word ptr [0x50d8], ax */
    TR(0x0b65e); WW(DS_, 0x50da, 0xa1); /* 089d:2c8e mov word ptr [0x50da], 0xa1 */
    TR(0x0b664); WW(DS_, (uint16_t)(BX + 0x4f2a), 0x0); /* 089d:2c94 mov word ptr [bx + 0x4f2a], 0 */
    TR(0x0b66a); PUSH(0x2c9d); goto L0b4f2; /* 089d:2c9a call 0xb4f2 */
L0b66d:
    TR(0x0b66d); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2c9d ret  */

/* ---- f_089d_2c9e */
L0b66e:
    TR(0x0b66e); CYC(40); /* 089d:2c9e cmp word ptr [bx + 0x4ff6], 0x13b */
    TR(0x0b674); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x4ff6)) > (int16_t)0x13b) goto L0b6bc; /* 089d:2ca4 jg 0xb6bc */
    TR(0x0b676); CYC(40); /* 089d:2ca6 cmp word ptr [bx + 0x4ff6], 0 */
    TR(0x0b67b); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x4ff6)) < (int16_t)0x0) goto L0b6bc; /* 089d:2cab jl 0xb6bc */
    TR(0x0b67d); CYC(340); PUSH(BX); /* 089d:2cad push bx */
    TR(0x0b67e); PUSH(CX); /* 089d:2cae push cx */
    TR(0x0b67f); PUSH(DX); /* 089d:2caf push dx */
    TR(0x0b680); PUSH(SI); /* 089d:2cb0 push si */
    TR(0x0b681); PUSH(DI); /* 089d:2cb1 push di */
    TR(0x0b682); AX = 0x0; /* 089d:2cb2 mov ax, 0 */
    TR(0x0b685); AX += AX; /* 089d:2cb5 add ax, ax */
    TR(0x0b687); DI = AX; /* 089d:2cb7 mov di, ax */
    TR(0x0b689); SI = RW(DS_, (uint16_t)(DI + 0x6ccb)); /* 089d:2cb9 mov si, word ptr [di + 0x6ccb] */
    TR(0x0b68d); DL = RB(DS_, SI); /* 089d:2cbd mov dl, byte ptr [si] */
    TR(0x0b68f); DH = DL; /* 089d:2cbf mov dh, dl */
    TR(0x0b691); SI++; /* 089d:2cc1 inc si */
    TR(0x0b692); CH = RB(DS_, SI); /* 089d:2cc2 mov ch, byte ptr [si] */
    TR(0x0b694); SI++; /* 089d:2cc4 inc si */
    TR(0x0b695); WW(DS_, 0x36, SI); /* 089d:2cc5 mov word ptr [0x36], si */
    TR(0x0b699); AX = RW(DS_, (uint16_t)(BX + 0x500a)); /* 089d:2cc9 mov ax, word ptr [bx + 0x500a] */
    TR(0x0b69d); WW(DS_, 0x2e, AX); /* 089d:2ccd mov word ptr [0x2e], ax */
    TR(0x0b6a0); BX = RW(DS_, (uint16_t)(BX + 0x4ff6)); /* 089d:2cd0 mov bx, word ptr [bx + 0x4ff6] */
    TR(0x0b6a4); AX = RW(DS_, (uint16_t)(BX + 0x680e)); /* 089d:2cd4 mov ax, word ptr [bx + 0x680e] */
    TR(0x0b6a8); AH = 0x0; /* 089d:2cd8 mov ah, 0 */
    TR(0x0b6aa); WW(DS_, 0x2c, AX); /* 089d:2cda mov word ptr [0x2c], ax */
    TR(0x0b6ad); AX = RW(DS_, (uint16_t)(BX + 0x695c)); /* 089d:2cdd mov ax, word ptr [bx + 0x695c] */
    TR(0x0b6b1); WW(DS_, 0x3a, AX); /* 089d:2ce1 mov word ptr [0x3a], ax */
    TR(0x0b6b4); PUSH(0x2ce7); goto L0ae25; /* 089d:2ce4 call 0xae25 */
L0b6b7:
    TR(0x0b6b7); CYC(60); DI = POP(); /* 089d:2ce7 pop di */
    TR(0x0b6b8); SI = POP(); /* 089d:2ce8 pop si */
    TR(0x0b6b9); DX = POP(); /* 089d:2ce9 pop dx */
    TR(0x0b6ba); CX = POP(); /* 089d:2cea pop cx */
    TR(0x0b6bb); BX = POP(); /* 089d:2ceb pop bx */
L0b6bc:
    TR(0x0b6bc); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2cec ret  */

/* ---- f_089d_2ced */
L0b6bd:
    TR(0x0b6bd); CYC(40); /* 089d:2ced cmp word ptr [0x505a], 1 */
    TR(0x0b6c2); if (RW(DS_, 0x505a) == 0x1) goto L0b6c5; /* 089d:2cf2 je 0xb6c5 */
    TR(0x0b6c4); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2cf4 ret  */
L0b6c5:
    TR(0x0b6c5); CYC(30); CX = RW(DS_, 0x5062); /* 089d:2cf5 mov cx, word ptr [0x5062] */
    TR(0x0b6c9); BX = 0x0; /* 089d:2cf9 mov bx, 0 */
L0b6cc:
    TR(0x0b6cc); CYC(40); /* 089d:2cfc cmp word ptr [bx + 0x501e], 1 */
    TR(0x0b6d1); if (RW(DS_, (uint16_t)(BX + 0x501e)) != 0x1) goto L0b6d9; /* 089d:2d01 jne 0xb6d9 */
    TR(0x0b6d3); CYC(23); PUSH(0x2d06); goto L0b725; /* 089d:2d03 call 0xb725 */
L0b6d6:
    TR(0x0b6d6); CYC(15); goto L0b71a; /* 089d:2d06 jmp 0xb71a */
L0b6d9:
    TR(0x0b6d9); CYC(40); /* 089d:2d09 cmp word ptr [0x505c], 0 */
    TR(0x0b6de); if (RW(DS_, 0x505c) == 0x0) goto L0b71a; /* 089d:2d0e je 0xb71a */
    TR(0x0b6e0); CYC(40); /* 089d:2d10 cmp word ptr [bx + 0x501e], 0 */
    TR(0x0b6e5); if (RW(DS_, (uint16_t)(BX + 0x501e)) != 0x0) goto L0b71a; /* 089d:2d15 jne 0xb71a */
    TR(0x0b6e7); CYC(239); WW(DS_, 0x505c, 0x0); /* 089d:2d17 mov word ptr [0x505c], 0 */
    TR(0x0b6ed); WW(DS_, (uint16_t)(BX + 0x501e), 0x1); /* 089d:2d1d mov word ptr [bx + 0x501e], 1 */
    TR(0x0b6f3); AX = RW(DS_, 0x4170); /* 089d:2d23 mov ax, word ptr [0x4170] */
    TR(0x0b6f6); AX += 0x14; /* 089d:2d26 add ax, 0x14 */
    TR(0x0b6f9); WW(DS_, (uint16_t)(BX + 0x4ff6), AX); /* 089d:2d29 mov word ptr [bx + 0x4ff6], ax */
    TR(0x0b6fd); AX = RW(DS_, 0x4172); /* 089d:2d2d mov ax, word ptr [0x4172] */
    TR(0x0b700); AX += 0x4; /* 089d:2d30 add ax, 4 */
    TR(0x0b703); WW(DS_, (uint16_t)(BX + 0x500a), AX); /* 089d:2d33 mov word ptr [bx + 0x500a], ax */
    TR(0x0b707); AX = RW(DS_, 0x4a); /* 089d:2d37 mov ax, word ptr [0x4a] */
    TR(0x0b70a); AX += 0xa; /* 089d:2d3a add ax, 0xa */
    TR(0x0b70d); WW(DS_, (uint16_t)(BX + 0x5032), AX); /* 089d:2d3d mov word ptr [bx + 0x5032], ax */
    TR(0x0b711); WW(DS_, (uint16_t)(BX + 0x5046), 0x0); /* 089d:2d41 mov word ptr [bx + 0x5046], 0 */
    TR(0x0b717); PUSH(0x2d4a); goto L0b66e; /* 089d:2d47 call 0xb66e */
L0b71a:
    TR(0x0b71a); CYC(25); BX++; /* 089d:2d4a inc bx */
    TR(0x0b71b); BX++; /* 089d:2d4b inc bx */
    TR(0x0b71c); if (--CX) goto L0b6cc; /* 089d:2d4c loop 0xb6cc */
    TR(0x0b71e); CYC(44); WW(DS_, 0x505c, 0x0); /* 089d:2d4e mov word ptr [0x505c], 0 */
    TR(0x0b724); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2d54 ret  */

/* ---- f_089d_2d55 */
L0b725:
    TR(0x0b725); CYC(23); PUSH(0x2d58); goto L0b66e; /* 089d:2d55 call 0xb66e */
L0b728:
    TR(0x0b728); CYC(219); AX = RW(DS_, (uint16_t)(BX + 0x5032)); /* 089d:2d58 mov ax, word ptr [bx + 0x5032] */
    TR(0x0b72c); AX -= RW(DS_, 0x4a); /* 089d:2d5c sub ax, word ptr [0x4a] */
    TR(0x0b730); WW(DS_, (uint16_t)(BX + 0x4ff6), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x4ff6)) + AX)); /* 089d:2d60 add word ptr [bx + 0x4ff6], ax */
    TR(0x0b734); WW(DS_, (uint16_t)(BX + 0x5046), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x5046)) + 1)); /* 089d:2d64 inc word ptr [bx + 0x5046] */
    TR(0x0b738); AX = RW(DS_, (uint16_t)(BX + 0x5046)); /* 089d:2d68 mov ax, word ptr [bx + 0x5046] */
    TR(0x0b73c); PUSH(CX); /* 089d:2d6c push cx */
    TR(0x0b73d); CL = 0x2; /* 089d:2d6d mov cl, 2 */
    TR(0x0b73f); AX >>= (CL & 0x1f); /* 089d:2d6f shr ax, cl */
    TR(0x0b741); CX = POP(); /* 089d:2d71 pop cx */
    TR(0x0b742); WW(DS_, (uint16_t)(BX + 0x500a), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x500a)) + AX)); /* 089d:2d72 add word ptr [bx + 0x500a], ax */
    TR(0x0b746); /* 089d:2d76 cmp byte ptr [bx + 0x500a], 0xb2 */
    TR(0x0b74b); if ((int8_t)RB(DS_, (uint16_t)(BX + 0x500a)) <= (int8_t)0xb2) goto L0b754; /* 089d:2d7b jle 0xb754 */
    TR(0x0b74d); CYC(44); WW(DS_, (uint16_t)(BX + 0x501e), 0x0); /* 089d:2d7d mov word ptr [bx + 0x501e], 0 */
    TR(0x0b753); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2d83 ret  */
L0b754:
    TR(0x0b754); CYC(23); PUSH(0x2d87); goto L0b66e; /* 089d:2d84 call 0xb66e */
L0b757:
    TR(0x0b757); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2d87 ret  */

/* ---- f_089d_2d88 */
L0b758:
    TR(0x0b758); CYC(40); /* 089d:2d88 cmp word ptr [bx + 0x5068], 0x12a */
    TR(0x0b75e); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x5068)) > (int16_t)0x12a) goto L0b7ab; /* 089d:2d8e jg 0xb7ab */
    TR(0x0b760); CYC(40); /* 089d:2d90 cmp word ptr [bx + 0x5068], 0 */
    TR(0x0b765); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x5068)) < (int16_t)0x0) goto L0b7ab; /* 089d:2d95 jl 0xb7ab */
    TR(0x0b767); CYC(362); AX = RW(DS_, (uint16_t)(BX + 0x50aa)); /* 089d:2d97 mov ax, word ptr [bx + 0x50aa] */
    TR(0x0b76b); AX >>= 1; /* 089d:2d9b shr ax, 1 */
    TR(0x0b76d); PUSH(BX); /* 089d:2d9d push bx */
    TR(0x0b76e); PUSH(CX); /* 089d:2d9e push cx */
    TR(0x0b76f); PUSH(DX); /* 089d:2d9f push dx */
    TR(0x0b770); PUSH(SI); /* 089d:2da0 push si */
    TR(0x0b771); PUSH(DI); /* 089d:2da1 push di */
    TR(0x0b772); AX = AX; /* 089d:2da2 mov ax, ax */
    TR(0x0b774); AX += AX; /* 089d:2da4 add ax, ax */
    TR(0x0b776); DI = AX; /* 089d:2da6 mov di, ax */
    TR(0x0b778); SI = RW(DS_, (uint16_t)(DI + 0x6cd2)); /* 089d:2da8 mov si, word ptr [di + 0x6cd2] */
    TR(0x0b77c); DL = RB(DS_, SI); /* 089d:2dac mov dl, byte ptr [si] */
    TR(0x0b77e); DH = DL; /* 089d:2dae mov dh, dl */
    TR(0x0b780); SI++; /* 089d:2db0 inc si */
    TR(0x0b781); CH = RB(DS_, SI); /* 089d:2db1 mov ch, byte ptr [si] */
    TR(0x0b783); SI++; /* 089d:2db3 inc si */
    TR(0x0b784); WW(DS_, 0x36, SI); /* 089d:2db4 mov word ptr [0x36], si */
    TR(0x0b788); AX = RW(DS_, (uint16_t)(BX + 0x507e)); /* 089d:2db8 mov ax, word ptr [bx + 0x507e] */
    TR(0x0b78c); WW(DS_, 0x2e, AX); /* 089d:2dbc mov word ptr [0x2e], ax */
    TR(0x0b78f); BX = RW(DS_, (uint16_t)(BX + 0x5068)); /* 089d:2dbf mov bx, word ptr [bx + 0x5068] */
    TR(0x0b793); AX = RW(DS_, (uint16_t)(BX + 0x680e)); /* 089d:2dc3 mov ax, word ptr [bx + 0x680e] */
    TR(0x0b797); AH = 0x0; /* 089d:2dc7 mov ah, 0 */
    TR(0x0b799); WW(DS_, 0x2c, AX); /* 089d:2dc9 mov word ptr [0x2c], ax */
    TR(0x0b79c); AX = RW(DS_, (uint16_t)(BX + 0x695c)); /* 089d:2dcc mov ax, word ptr [bx + 0x695c] */
    TR(0x0b7a0); WW(DS_, 0x3a, AX); /* 089d:2dd0 mov word ptr [0x3a], ax */
    TR(0x0b7a3); PUSH(0x2dd6); goto L0ae25; /* 089d:2dd3 call 0xae25 */
L0b7a6:
    TR(0x0b7a6); CYC(60); DI = POP(); /* 089d:2dd6 pop di */
    TR(0x0b7a7); SI = POP(); /* 089d:2dd7 pop si */
    TR(0x0b7a8); DX = POP(); /* 089d:2dd8 pop dx */
    TR(0x0b7a9); CX = POP(); /* 089d:2dd9 pop cx */
    TR(0x0b7aa); BX = POP(); /* 089d:2dda pop bx */
L0b7ab:
    TR(0x0b7ab); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2ddb ret  */

/* ---- f_089d_2ddc */
L0b7ac:
    TR(0x0b7ac); CYC(30); CX = RW(DS_, 0x50dc); /* 089d:2ddc mov cx, word ptr [0x50dc] */
    TR(0x0b7b0); BX = 0x0; /* 089d:2de0 mov bx, 0 */
L0b7b3:
    TR(0x0b7b3); CYC(40); /* 089d:2de3 cmp word ptr [bx + 0x5094], 0 */
    TR(0x0b7b8); if (RW(DS_, (uint16_t)(BX + 0x5094)) == 0x0) goto L0b7c0; /* 089d:2de8 je 0xb7c0 */
    TR(0x0b7ba); CYC(23); PUSH(0x2ded); goto L0b7fb; /* 089d:2dea call 0xb7fb */
L0b7bd:
    TR(0x0b7bd); CYC(15); goto L0b7f0; /* 089d:2ded jmp 0xb7f0 */
L0b7c0:
    TR(0x0b7c0); CYC(40); /* 089d:2df0 cmp word ptr [0x50d6], 0 */
    TR(0x0b7c5); if (RW(DS_, 0x50d6) == 0x0) goto L0b7f0; /* 089d:2df5 je 0xb7f0 */
    TR(0x0b7c7); CYC(191); WW(DS_, 0x50d6, 0x0); /* 089d:2df7 mov word ptr [0x50d6], 0 */
    TR(0x0b7cd); WW(DS_, (uint16_t)(BX + 0x5094), 0x1); /* 089d:2dfd mov word ptr [bx + 0x5094], 1 */
    TR(0x0b7d3); AX = RW(DS_, 0x50d8); /* 089d:2e03 mov ax, word ptr [0x50d8] */
    TR(0x0b7d6); WW(DS_, (uint16_t)(BX + 0x5068), AX); /* 089d:2e06 mov word ptr [bx + 0x5068], ax */
    TR(0x0b7da); AX = RW(DS_, 0x50da); /* 089d:2e0a mov ax, word ptr [0x50da] */
    TR(0x0b7dd); WW(DS_, (uint16_t)(BX + 0x507e), AX); /* 089d:2e0d mov word ptr [bx + 0x507e], ax */
    TR(0x0b7e1); WW(DS_, (uint16_t)(BX + 0x50aa), 0x0); /* 089d:2e11 mov word ptr [bx + 0x50aa], 0 */
    TR(0x0b7e7); WW(DS_, (uint16_t)(BX + 0x50c0), 0xf); /* 089d:2e17 mov word ptr [bx + 0x50c0], 0xf */
    TR(0x0b7ed); PUSH(0x2e20); goto L0b758; /* 089d:2e1d call 0xb758 */
L0b7f0:
    TR(0x0b7f0); CYC(25); BX++; /* 089d:2e20 inc bx */
    TR(0x0b7f1); BX++; /* 089d:2e21 inc bx */
    TR(0x0b7f2); if (--CX) goto L0b7b3; /* 089d:2e22 loop 0xb7b3 */
    TR(0x0b7f4); CYC(44); WW(DS_, 0x50d6, 0x0); /* 089d:2e24 mov word ptr [0x50d6], 0 */
    TR(0x0b7fa); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2e2a ret  */

/* ---- f_089d_2e2b */
L0b7fb:
    TR(0x0b7fb); CYC(23); PUSH(0x2e2e); goto L0b758; /* 089d:2e2b call 0xb758 */
L0b7fe:
    TR(0x0b7fe); CYC(121); AX = RW(DS_, 0x4a); /* 089d:2e2e mov ax, word ptr [0x4a] */
    TR(0x0b801); AX = (uint16_t)(0u - AX); /* 089d:2e31 neg ax */
    TR(0x0b803); WW(DS_, (uint16_t)(BX + 0x5068), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x5068)) + AX)); /* 089d:2e33 add word ptr [bx + 0x5068], ax */
    TR(0x0b807); WW(DS_, (uint16_t)(BX + 0x50aa), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x50aa)) + 1)); /* 089d:2e37 inc word ptr [bx + 0x50aa] */
    TR(0x0b80b); /* 089d:2e3b cmp word ptr [bx + 0x50aa], 6 */
    TR(0x0b810); if (RW(DS_, (uint16_t)(BX + 0x50aa)) != 0x6) goto L0b818; /* 089d:2e40 jne 0xb818 */
    TR(0x0b812); CYC(24); WW(DS_, (uint16_t)(BX + 0x50aa), 0x0); /* 089d:2e42 mov word ptr [bx + 0x50aa], 0 */
L0b818:
    TR(0x0b818); CYC(39); { uint16_t a_ = RW(DS_, (uint16_t)(BX + 0x50c0)), b_ = 1; unsigned r_ = (unsigned)a_ - 1;   WW(DS_, (uint16_t)(BX + 0x50c0), (uint16_t)r_);   ZF = ((r_ & 0xffff) == 0); } /* 089d:2e48 dec word ptr [bx + 0x50c0] */
    TR(0x0b81c); if (!ZF) goto L0b825; /* 089d:2e4c jne 0xb825 */
    TR(0x0b81e); CYC(44); WW(DS_, (uint16_t)(BX + 0x5094), 0x0); /* 089d:2e4e mov word ptr [bx + 0x5094], 0 */
    TR(0x0b824); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2e54 ret  */
L0b825:
    TR(0x0b825); CYC(23); PUSH(0x2e58); goto L0b758; /* 089d:2e55 call 0xb758 */
L0b828:
    TR(0x0b828); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2e58 ret  */

/* ---- f_089d_2e59 */
L0b829:
    TR(0x0b829); CYC(106); WW(DS_, 0x50e2, (uint16_t)(RW(DS_, 0x50e2) + AX)); /* 089d:2e59 add word ptr [0x50e2], ax */
    TR(0x0b82d); WW(DS_, 0x50e6, (uint16_t)(RW(DS_, 0x50e6) + AX)); /* 089d:2e5d add word ptr [0x50e6], ax */
    TR(0x0b831); PUSH(BX); /* 089d:2e61 push bx */
    TR(0x0b832); BX = 0x3; /* 089d:2e62 mov bx, 3 */
    TR(0x0b835); PUSH(0x2e68); goto L0aed5; /* 089d:2e65 call 0xaed5 */
L0b838:
    TR(0x0b838); CYC(158); BX = POP(); /* 089d:2e68 pop bx */
    TR(0x0b839); PUSH(BX); /* 089d:2e69 push bx */
    TR(0x0b83a); PUSH(CX); /* 089d:2e6a push cx */
    TR(0x0b83b); PUSH(DX); /* 089d:2e6b push dx */
    TR(0x0b83c); WW(DS_, 0x50de, 0x10); /* 089d:2e6c mov word ptr [0x50de], 0x10 */
    TR(0x0b842); WW(DS_, 0x50e0, 0x0); /* 089d:2e72 mov word ptr [0x50e0], 0 */
    TR(0x0b848); BX = RW(DS_, 0x50e2); /* 089d:2e78 mov bx, word ptr [0x50e2] */
    TR(0x0b84c); DX = 0x2710; /* 089d:2e7c mov dx, 0x2710 */
    TR(0x0b84f); PUSH(0x2e82); goto L0b083; /* 089d:2e7f call 0xb083 */
L0b852:
    TR(0x0b852); CYC(83); DX = POP(); /* 089d:2e82 pop dx */
    TR(0x0b853); CX = POP(); /* 089d:2e83 pop cx */
    TR(0x0b854); BX = POP(); /* 089d:2e84 pop bx */
    TR(0x0b855); AX = RW(DS_, 0x50e2); /* 089d:2e85 mov ax, word ptr [0x50e2] */
    TR(0x0b858); /* 089d:2e88 cmp ax, word ptr [0x50e4] */
    TR(0x0b85c); if (AX < RW(DS_, 0x50e4)) goto L0b87d; /* 089d:2e8c jb 0xb87d */
    TR(0x0b85e); CYC(164); WW(DS_, 0x50e4, AX); /* 089d:2e8e mov word ptr [0x50e4], ax */
    TR(0x0b861); PUSH(BX); /* 089d:2e91 push bx */
    TR(0x0b862); PUSH(CX); /* 089d:2e92 push cx */
    TR(0x0b863); PUSH(DX); /* 089d:2e93 push dx */
    TR(0x0b864); WW(DS_, 0x50de, 0x37); /* 089d:2e94 mov word ptr [0x50de], 0x37 */
    TR(0x0b86a); WW(DS_, 0x50e0, 0x0); /* 089d:2e9a mov word ptr [0x50e0], 0 */
    TR(0x0b870); BX = RW(DS_, 0x50e4); /* 089d:2ea0 mov bx, word ptr [0x50e4] */
    TR(0x0b874); DX = 0x2710; /* 089d:2ea4 mov dx, 0x2710 */
    TR(0x0b877); PUSH(0x2eaa); goto L0b083; /* 089d:2ea7 call 0xb083 */
L0b87a:
    TR(0x0b87a); CYC(36); DX = POP(); /* 089d:2eaa pop dx */
    TR(0x0b87b); CX = POP(); /* 089d:2eab pop cx */
    TR(0x0b87c); BX = POP(); /* 089d:2eac pop bx */
L0b87d:
    TR(0x0b87d); CYC(40); /* 089d:2ead cmp word ptr [0x50e6], 0x1388 */
    TR(0x0b883); if ((int16_t)RW(DS_, 0x50e6) < (int16_t)0x1388) goto L0b8ae; /* 089d:2eb3 jl 0xb8ae */
    TR(0x0b885); CYC(221); WW(DS_, 0x4178, (uint16_t)(RW(DS_, 0x4178) + 1)); /* 089d:2eb5 inc word ptr [0x4178] */
    TR(0x0b889); AX = RW(DS_, 0x50e6); /* 089d:2eb9 mov ax, word ptr [0x50e6] */
    TR(0x0b88c); AX -= 0x1388; /* 089d:2ebc sub ax, 0x1388 */
    TR(0x0b88f); WW(DS_, 0x50e6, AX); /* 089d:2ebf mov word ptr [0x50e6], ax */
    TR(0x0b892); PUSH(BX); /* 089d:2ec2 push bx */
    TR(0x0b893); PUSH(CX); /* 089d:2ec3 push cx */
    TR(0x0b894); PUSH(DX); /* 089d:2ec4 push dx */
    TR(0x0b895); WW(DS_, 0x50de, 0x13); /* 089d:2ec5 mov word ptr [0x50de], 0x13 */
    TR(0x0b89b); WW(DS_, 0x50e0, 0xa); /* 089d:2ecb mov word ptr [0x50e0], 0xa */
    TR(0x0b8a1); BX = RW(DS_, 0x4178); /* 089d:2ed1 mov bx, word ptr [0x4178] */
    TR(0x0b8a5); DX = 0xa; /* 089d:2ed5 mov dx, 0xa */
    TR(0x0b8a8); PUSH(0x2edb); goto L0b083; /* 089d:2ed8 call 0xb083 */
L0b8ab:
    TR(0x0b8ab); CYC(36); DX = POP(); /* 089d:2edb pop dx */
    TR(0x0b8ac); CX = POP(); /* 089d:2edc pop cx */
    TR(0x0b8ad); BX = POP(); /* 089d:2edd pop bx */
L0b8ae:
    TR(0x0b8ae); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2ede ret  */

/* ---- f_089d_2edf */
L0b8af:
    TR(0x0b8af); CYC(30); CX = RW(DS_, 0x5168); /* 089d:2edf mov cx, word ptr [0x5168] */
    TR(0x0b8b3); BX = 0x0; /* 089d:2ee3 mov bx, 0 */
L0b8b6:
    TR(0x0b8b6); CYC(40); /* 089d:2ee6 cmp word ptr [bx + 0x5138], 0 */
    TR(0x0b8bb); if (RW(DS_, (uint16_t)(BX + 0x5138)) == 0x0) goto L0b8c3; /* 089d:2eeb je 0xb8c3 */
    TR(0x0b8bd); CYC(23); PUSH(0x2ef0); goto L0b906; /* 089d:2eed call 0xb906 */
L0b8c0:
    TR(0x0b8c0); CYC(15); goto L0b8fb; /* 089d:2ef0 jmp 0xb8fb */
L0b8c3:
    TR(0x0b8c3); CYC(40); /* 089d:2ef3 cmp word ptr [0x5160], 0 */
    TR(0x0b8c8); if (RW(DS_, 0x5160) == 0x0) goto L0b8fb; /* 089d:2ef8 je 0xb8fb */
    TR(0x0b8ca); CYC(239); WW(DS_, 0x5160, 0x0); /* 089d:2efa mov word ptr [0x5160], 0 */
    TR(0x0b8d0); WW(DS_, (uint16_t)(BX + 0x5138), 0x1); /* 089d:2f00 mov word ptr [bx + 0x5138], 1 */
    TR(0x0b8d6); AX = RW(DS_, 0x5162); /* 089d:2f06 mov ax, word ptr [0x5162] */
    TR(0x0b8d9); WW(DS_, (uint16_t)(BX + 0x50e8), AX); /* 089d:2f09 mov word ptr [bx + 0x50e8], ax */
    TR(0x0b8dd); AX = RW(DS_, 0x5164); /* 089d:2f0d mov ax, word ptr [0x5164] */
    TR(0x0b8e0); WW(DS_, (uint16_t)(BX + 0x50fc), AX); /* 089d:2f10 mov word ptr [bx + 0x50fc], ax */
    TR(0x0b8e4); AX = RW(DS_, 0x5166); /* 089d:2f14 mov ax, word ptr [0x5166] */
    TR(0x0b8e7); WW(DS_, (uint16_t)(BX + 0x5124), AX); /* 089d:2f17 mov word ptr [bx + 0x5124], ax */
    TR(0x0b8eb); AX = RW(DS_, 0x516a); /* 089d:2f1b mov ax, word ptr [0x516a] */
    TR(0x0b8ee); WW(DS_, (uint16_t)(BX + 0x514c), AX); /* 089d:2f1e mov word ptr [bx + 0x514c], ax */
    TR(0x0b8f2); WW(DS_, (uint16_t)(BX + 0x5110), 0xf); /* 089d:2f22 mov word ptr [bx + 0x5110], 0xf */
    TR(0x0b8f8); PUSH(0x2f2b); goto L0b926; /* 089d:2f28 call 0xb926 */
L0b8fb:
    TR(0x0b8fb); CYC(25); BX++; /* 089d:2f2b inc bx */
    TR(0x0b8fc); BX++; /* 089d:2f2c inc bx */
    TR(0x0b8fd); if (--CX) goto L0b8b6; /* 089d:2f2d loop 0xb8b6 */
    TR(0x0b8ff); CYC(44); WW(DS_, 0x5160, 0x0); /* 089d:2f2f mov word ptr [0x5160], 0 */
    TR(0x0b905); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2f35 ret  */

/* ---- f_089d_2f36 */
L0b906:
    TR(0x0b906); CYC(23); PUSH(0x2f39); goto L0b926; /* 089d:2f36 call 0xb926 */
L0b909:
    TR(0x0b909); CYC(102); AX = RW(DS_, (uint16_t)(BX + 0x514c)); /* 089d:2f39 mov ax, word ptr [bx + 0x514c] */
    TR(0x0b90d); AX -= RW(DS_, 0x4a); /* 089d:2f3d sub ax, word ptr [0x4a] */
    TR(0x0b911); WW(DS_, (uint16_t)(BX + 0x50e8), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x50e8)) + AX)); /* 089d:2f41 add word ptr [bx + 0x50e8], ax */
    TR(0x0b915); { uint16_t a_ = RW(DS_, (uint16_t)(BX + 0x5110)), b_ = 1; unsigned r_ = (unsigned)a_ - 1;   WW(DS_, (uint16_t)(BX + 0x5110), (uint16_t)r_);   ZF = ((r_ & 0xffff) == 0); } /* 089d:2f45 dec word ptr [bx + 0x5110] */
    TR(0x0b919); if (!ZF) goto L0b922; /* 089d:2f49 jne 0xb922 */
    TR(0x0b91b); CYC(44); WW(DS_, (uint16_t)(BX + 0x5138), 0x0); /* 089d:2f4b mov word ptr [bx + 0x5138], 0 */
    TR(0x0b921); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2f51 ret  */
L0b922:
    TR(0x0b922); CYC(23); PUSH(0x2f55); goto L0b926; /* 089d:2f52 call 0xb926 */
L0b925:
    TR(0x0b925); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2f55 ret  */

/* ---- f_089d_2f56 */
L0b926:
    TR(0x0b926); CYC(40); /* 089d:2f56 cmp word ptr [bx + 0x50e8], 0x12a */
    TR(0x0b92c); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x50e8)) > (int16_t)0x12a) goto L0b977; /* 089d:2f5c jg 0xb977 */
    TR(0x0b92e); CYC(40); /* 089d:2f5e cmp word ptr [bx + 0x50e8], 0 */
    TR(0x0b933); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x50e8)) < (int16_t)0x0) goto L0b977; /* 089d:2f63 jl 0xb977 */
    TR(0x0b935); CYC(354); AX = RW(DS_, (uint16_t)(BX + 0x5124)); /* 089d:2f65 mov ax, word ptr [bx + 0x5124] */
    TR(0x0b939); PUSH(BX); /* 089d:2f69 push bx */
    TR(0x0b93a); PUSH(CX); /* 089d:2f6a push cx */
    TR(0x0b93b); PUSH(DX); /* 089d:2f6b push dx */
    TR(0x0b93c); PUSH(SI); /* 089d:2f6c push si */
    TR(0x0b93d); PUSH(DI); /* 089d:2f6d push di */
    TR(0x0b93e); AX = AX; /* 089d:2f6e mov ax, ax */
    TR(0x0b940); AX += AX; /* 089d:2f70 add ax, ax */
    TR(0x0b942); DI = AX; /* 089d:2f72 mov di, ax */
    TR(0x0b944); SI = RW(DS_, (uint16_t)(DI + 0x71f1)); /* 089d:2f74 mov si, word ptr [di + 0x71f1] */
    TR(0x0b948); DL = RB(DS_, SI); /* 089d:2f78 mov dl, byte ptr [si] */
    TR(0x0b94a); DH = DL; /* 089d:2f7a mov dh, dl */
    TR(0x0b94c); SI++; /* 089d:2f7c inc si */
    TR(0x0b94d); CH = RB(DS_, SI); /* 089d:2f7d mov ch, byte ptr [si] */
    TR(0x0b94f); SI++; /* 089d:2f7f inc si */
    TR(0x0b950); WW(DS_, 0x36, SI); /* 089d:2f80 mov word ptr [0x36], si */
    TR(0x0b954); AX = RW(DS_, (uint16_t)(BX + 0x50fc)); /* 089d:2f84 mov ax, word ptr [bx + 0x50fc] */
    TR(0x0b958); WW(DS_, 0x2e, AX); /* 089d:2f88 mov word ptr [0x2e], ax */
    TR(0x0b95b); BX = RW(DS_, (uint16_t)(BX + 0x50e8)); /* 089d:2f8b mov bx, word ptr [bx + 0x50e8] */
    TR(0x0b95f); AX = RW(DS_, (uint16_t)(BX + 0x680e)); /* 089d:2f8f mov ax, word ptr [bx + 0x680e] */
    TR(0x0b963); AH = 0x0; /* 089d:2f93 mov ah, 0 */
    TR(0x0b965); WW(DS_, 0x2c, AX); /* 089d:2f95 mov word ptr [0x2c], ax */
    TR(0x0b968); AX = RW(DS_, (uint16_t)(BX + 0x695c)); /* 089d:2f98 mov ax, word ptr [bx + 0x695c] */
    TR(0x0b96c); WW(DS_, 0x3a, AX); /* 089d:2f9c mov word ptr [0x3a], ax */
    TR(0x0b96f); PUSH(0x2fa2); goto L0ae25; /* 089d:2f9f call 0xae25 */
L0b972:
    TR(0x0b972); CYC(60); DI = POP(); /* 089d:2fa2 pop di */
    TR(0x0b973); SI = POP(); /* 089d:2fa3 pop si */
    TR(0x0b974); DX = POP(); /* 089d:2fa4 pop dx */
    TR(0x0b975); CX = POP(); /* 089d:2fa5 pop cx */
    TR(0x0b976); BX = POP(); /* 089d:2fa6 pop bx */
L0b977:
    TR(0x0b977); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2fa7 ret  */

/* ---- f_089d_2fa8 */
L0b978:
    TR(0x0b978); CYC(40); /* 089d:2fa8 cmp word ptr [0x5360], 0 */
    TR(0x0b97d); if (RW(DS_, 0x5360) != 0x0) goto L0b980; /* 089d:2fad jne 0xb980 */
    TR(0x0b97f); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:2faf ret  */
L0b980:
    TR(0x0b980); CYC(40); /* 089d:2fb0 cmp word ptr [0x5364], 1 */
    TR(0x0b985); if (RW(DS_, 0x5364) == 0x1) goto L0b9f5; /* 089d:2fb5 je 0xb9f5 */
    TR(0x0b987); CYC(119); WW(DS_, 0x5364, 0x1); /* 089d:2fb7 mov word ptr [0x5364], 1 */
    TR(0x0b98d); WW(DS_, 0x4a, 0x0); /* 089d:2fbd mov word ptr [0x4a], 0 */
    TR(0x0b993); WW(DS_, 0x4176, 0x0); /* 089d:2fc3 mov word ptr [0x4176], 0 */
    TR(0x0b999); WW(DS_, 0x5366, 0x32); /* 089d:2fc9 mov word ptr [0x5366], 0x32 */
    TR(0x0b99f); PUSH(0x2fd2); goto L0b27f; /* 089d:2fcf call 0xb27f */
L0b9a2:
    TR(0x0b9a2); CYC(30); CX = RW(DS_, 0x5362); /* 089d:2fd2 mov cx, word ptr [0x5362] */
    TR(0x0b9a6); BX = 0x0; /* 089d:2fd6 mov bx, 0 */
L0b9a9:
    TR(0x0b9a9); CYC(23); PUSH(0x2fdc); goto L0b412; /* 089d:2fd9 call 0xb412 */
L0b9ac:
    TR(0x0b9ac); CYC(20); /* 089d:2fdc cmp al, 0xa */
    TR(0x0b9ae); if (AL == 0xa) goto L0b9a9; /* 089d:2fde je 0xb9a9 */
    TR(0x0b9b0); CYC(20); /* 089d:2fe0 cmp al, 0x14 */
    TR(0x0b9b2); if (AL >= 0x14) goto L0b9a9; /* 089d:2fe2 jae 0xb9a9 */
    TR(0x0b9b4); CYC(38); AH = 0x0; /* 089d:2fe4 mov ah, 0 */
    TR(0x0b9b6); AX -= 0xa; /* 089d:2fe6 sub ax, 0xa */
    TR(0x0b9b9); WW(DS_, (uint16_t)(BX + 0x5234), AX); /* 089d:2fe9 mov word ptr [bx + 0x5234], ax */
L0b9bd:
    TR(0x0b9bd); CYC(23); PUSH(0x2ff0); goto L0b412; /* 089d:2fed call 0xb412 */
L0b9c0:
    TR(0x0b9c0); CYC(20); /* 089d:2ff0 cmp al, 0x13 */
    TR(0x0b9c2); if (AL >= 0x13) goto L0b9bd; /* 089d:2ff2 jae 0xb9bd */
    TR(0x0b9c4); CYC(134); AH = 0x0; /* 089d:2ff4 mov ah, 0 */
    TR(0x0b9c6); AX -= 0x14; /* 089d:2ff6 sub ax, 0x14 */
    TR(0x0b9c9); WW(DS_, (uint16_t)(BX + 0x5298), AX); /* 089d:2ff9 mov word ptr [bx + 0x5298], ax */
    TR(0x0b9cd); AX = RW(DS_, 0x4170); /* 089d:2ffd mov ax, word ptr [0x4170] */
    TR(0x0b9d0); AX += 0xa; /* 089d:3000 add ax, 0xa */
    TR(0x0b9d3); WW(DS_, (uint16_t)(BX + 0x516c), AX); /* 089d:3003 mov word ptr [bx + 0x516c], ax */
    TR(0x0b9d7); AX = RW(DS_, 0x4172); /* 089d:3007 mov ax, word ptr [0x4172] */
    TR(0x0b9da); AX += 0x7; /* 089d:300a add ax, 7 */
    TR(0x0b9dd); WW(DS_, (uint16_t)(BX + 0x51d0), AX); /* 089d:300d mov word ptr [bx + 0x51d0], ax */
L0b9e1:
    TR(0x0b9e1); CYC(23); PUSH(0x3014); goto L0b412; /* 089d:3011 call 0xb412 */
L0b9e4:
    TR(0x0b9e4); CYC(20); /* 089d:3014 cmp al, 5 */
    TR(0x0b9e6); if (AL >= 0x5) goto L0b9e1; /* 089d:3016 jae 0xb9e1 */
    TR(0x0b9e8); CYC(49); AH = 0x0; /* 089d:3018 mov ah, 0 */
    TR(0x0b9ea); WW(DS_, (uint16_t)(BX + 0x52fc), AX); /* 089d:301a mov word ptr [bx + 0x52fc], ax */
    TR(0x0b9ee); PUSH(0x3021); goto L0ba67; /* 089d:301e call 0xba67 */
L0b9f1:
    TR(0x0b9f1); CYC(25); BX++; /* 089d:3021 inc bx */
    TR(0x0b9f2); BX++; /* 089d:3022 inc bx */
    TR(0x0b9f3); if (--CX) goto L0b9a9; /* 089d:3023 loop 0xb9a9 */
L0b9f5:
    TR(0x0b9f5); CYC(30); CX = RW(DS_, 0x5362); /* 089d:3025 mov cx, word ptr [0x5362] */
    TR(0x0b9f9); BX = 0x0; /* 089d:3029 mov bx, 0 */
L0b9fc:
    TR(0x0b9fc); CYC(23); PUSH(0x302f); goto L0ba32; /* 089d:302c call 0xba32 */
L0b9ff:
    TR(0x0b9ff); CYC(25); BX++; /* 089d:302f inc bx */
    TR(0x0ba00); BX++; /* 089d:3030 inc bx */
    TR(0x0ba01); if (--CX) goto L0b9fc; /* 089d:3031 loop 0xb9fc */
    TR(0x0ba03); CYC(67); WW(DS_, 0x5366, (uint16_t)(RW(DS_, 0x5366) - 1)); /* 089d:3033 dec word ptr [0x5366] */
    TR(0x0ba07); /* 089d:3037 cmp word ptr [0x5366], 0 */
    TR(0x0ba0c); if (RW(DS_, 0x5366) != 0x0) goto L0ba31; /* 089d:303c jne 0xba31 */
    TR(0x0ba0e); CYC(115); WW(DS_, 0x5360, 0x0); /* 089d:303e mov word ptr [0x5360], 0 */
    TR(0x0ba14); WW(DS_, 0x5364, 0x0); /* 089d:3044 mov word ptr [0x5364], 0 */
    TR(0x0ba1a); WW(DS_, 0x4178, (uint16_t)(RW(DS_, 0x4178) - 1)); /* 089d:304a dec word ptr [0x4178] */
    TR(0x0ba1e); /* 089d:304e cmp word ptr [0x4178], 0 */
    TR(0x0ba23); if (RW(DS_, 0x4178) != 0x0) goto L0ba2b; /* 089d:3053 jne 0xba2b */
    TR(0x0ba25); CYC(27); SP = 0x1fc; /* 089d:3055 mov sp, 0x1fc */
    TR(0x0ba28); goto L089e3; /* 089d:3058 jmp 0x89e3 */
L0ba2b:
    TR(0x0ba2b); CYC(23); PUSH(0x305e); goto L0bac0; /* 089d:305b call 0xbac0 */
L0ba2e:
    TR(0x0ba2e); CYC(23); PUSH(0x3061); goto L08aca; /* 089d:305e call 0x8aca */
L0ba31:
    TR(0x0ba31); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3061 ret  */

/* ---- f_089d_3062 */
L0ba32:
    TR(0x0ba32); CYC(23); PUSH(0x3065); goto L0ba67; /* 089d:3062 call 0xba67 */
L0ba35:
    TR(0x0ba35); CYC(159); AX = RW(DS_, (uint16_t)(BX + 0x5234)); /* 089d:3065 mov ax, word ptr [bx + 0x5234] */
    TR(0x0ba39); WW(DS_, (uint16_t)(BX + 0x516c), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x516c)) + AX)); /* 089d:3069 add word ptr [bx + 0x516c], ax */
    TR(0x0ba3d); AX = RW(DS_, (uint16_t)(BX + 0x5298)); /* 089d:306d mov ax, word ptr [bx + 0x5298] */
    TR(0x0ba41); WW(DS_, (uint16_t)(BX + 0x51d0), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x51d0)) + AX)); /* 089d:3071 add word ptr [bx + 0x51d0], ax */
    TR(0x0ba45); WW(DS_, (uint16_t)(BX + 0x5298), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x5298)) + 1)); /* 089d:3075 inc word ptr [bx + 0x5298] */
    TR(0x0ba49); /* 089d:3079 cmp word ptr [bx + 0x51d0], 0xb0 */
    TR(0x0ba4f); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x51d0)) < (int16_t)0xb0) goto L0ba63; /* 089d:307f jl 0xba63 */
    TR(0x0ba51); CYC(72); WW(DS_, (uint16_t)(BX + 0x5234), 0x0); /* 089d:3081 mov word ptr [bx + 0x5234], 0 */
    TR(0x0ba57); WW(DS_, (uint16_t)(BX + 0x5298), 0x0); /* 089d:3087 mov word ptr [bx + 0x5298], 0 */
    TR(0x0ba5d); WW(DS_, (uint16_t)(BX + 0x51d0), 0xb0); /* 089d:308d mov word ptr [bx + 0x51d0], 0xb0 */
L0ba63:
    TR(0x0ba63); CYC(23); PUSH(0x3096); goto L0ba67; /* 089d:3093 call 0xba67 */
L0ba66:
    TR(0x0ba66); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3096 ret  */

/* ---- f_089d_3097 */
L0ba67:
    TR(0x0ba67); CYC(40); /* 089d:3097 cmp word ptr [bx + 0x516c], 0x12f */
    TR(0x0ba6d); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x516c)) > (int16_t)0x12f) goto L0babf; /* 089d:309d jg 0xbabf */
    TR(0x0ba6f); CYC(40); /* 089d:309f cmp word ptr [bx + 0x516c], 0 */
    TR(0x0ba74); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x516c)) < (int16_t)0x0) goto L0babf; /* 089d:30a4 jl 0xbabf */
    TR(0x0ba76); CYC(40); /* 089d:30a6 cmp word ptr [bx + 0x51d0], 0x19 */
    TR(0x0ba7b); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x51d0)) < (int16_t)0x19) goto L0babf; /* 089d:30ab jl 0xbabf */
    TR(0x0ba7d); CYC(354); AX = RW(DS_, (uint16_t)(BX + 0x52fc)); /* 089d:30ad mov ax, word ptr [bx + 0x52fc] */
    TR(0x0ba81); PUSH(BX); /* 089d:30b1 push bx */
    TR(0x0ba82); PUSH(CX); /* 089d:30b2 push cx */
    TR(0x0ba83); PUSH(DX); /* 089d:30b3 push dx */
    TR(0x0ba84); PUSH(SI); /* 089d:30b4 push si */
    TR(0x0ba85); PUSH(DI); /* 089d:30b5 push di */
    TR(0x0ba86); AX = AX; /* 089d:30b6 mov ax, ax */
    TR(0x0ba88); AX += AX; /* 089d:30b8 add ax, ax */
    TR(0x0ba8a); DI = AX; /* 089d:30ba mov di, ax */
    TR(0x0ba8c); SI = RW(DS_, (uint16_t)(DI + 0x7281)); /* 089d:30bc mov si, word ptr [di + 0x7281] */
    TR(0x0ba90); DL = RB(DS_, SI); /* 089d:30c0 mov dl, byte ptr [si] */
    TR(0x0ba92); DH = DL; /* 089d:30c2 mov dh, dl */
    TR(0x0ba94); SI++; /* 089d:30c4 inc si */
    TR(0x0ba95); CH = RB(DS_, SI); /* 089d:30c5 mov ch, byte ptr [si] */
    TR(0x0ba97); SI++; /* 089d:30c7 inc si */
    TR(0x0ba98); WW(DS_, 0x36, SI); /* 089d:30c8 mov word ptr [0x36], si */
    TR(0x0ba9c); AX = RW(DS_, (uint16_t)(BX + 0x51d0)); /* 089d:30cc mov ax, word ptr [bx + 0x51d0] */
    TR(0x0baa0); WW(DS_, 0x2e, AX); /* 089d:30d0 mov word ptr [0x2e], ax */
    TR(0x0baa3); BX = RW(DS_, (uint16_t)(BX + 0x516c)); /* 089d:30d3 mov bx, word ptr [bx + 0x516c] */
    TR(0x0baa7); AX = RW(DS_, (uint16_t)(BX + 0x680e)); /* 089d:30d7 mov ax, word ptr [bx + 0x680e] */
    TR(0x0baab); AH = 0x0; /* 089d:30db mov ah, 0 */
    TR(0x0baad); WW(DS_, 0x2c, AX); /* 089d:30dd mov word ptr [0x2c], ax */
    TR(0x0bab0); AX = RW(DS_, (uint16_t)(BX + 0x695c)); /* 089d:30e0 mov ax, word ptr [bx + 0x695c] */
    TR(0x0bab4); WW(DS_, 0x3a, AX); /* 089d:30e4 mov word ptr [0x3a], ax */
    TR(0x0bab7); PUSH(0x30ea); goto L0ae25; /* 089d:30e7 call 0xae25 */
L0baba:
    TR(0x0baba); CYC(60); DI = POP(); /* 089d:30ea pop di */
    TR(0x0babb); SI = POP(); /* 089d:30eb pop si */
    TR(0x0babc); DX = POP(); /* 089d:30ec pop dx */
    TR(0x0babd); CX = POP(); /* 089d:30ed pop cx */
    TR(0x0babe); BX = POP(); /* 089d:30ee pop bx */
L0babf:
    TR(0x0babf); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:30ef ret  */

/* ---- f_089d_30f0 */
L0bac0:
    TR(0x0bac0); CYC(48); VH(0x0bac0); { uint32_t k_ = or_fast(0x0bac0); if (k_) { jkey = k_; goto dispatch; } } WW(DS_, 0x44, 0x15); /* 089d:30f0 mov word ptr [0x44], 0x15 */
    TR(0x0bac6); WW(DS_, 0x2c, 0x0); /* 089d:30f6 mov word ptr [0x2c], 0 */
L0bacc:
    TR(0x0bacc); CYC(41); BX = RW(DS_, 0x44); /* 089d:30fc mov bx, word ptr [0x44] */
    TR(0x0bad0); PUSH(0x3103); goto L0aeca; /* 089d:3100 call 0xaeca */
L0bad3:
    TR(0x0bad3); CYC(12); CX = 0x50; /* 089d:3103 mov cx, 0x50 */
L0bad6:
    TR(0x0bad6); CYC(37); WB(ES_, BX, 0x0); /* 089d:3106 mov byte ptr es:[bx], 0 */
    TR(0x0bada); BX++; /* 089d:310a inc bx */
    TR(0x0badb); if (--CX) goto L0bad6; /* 089d:310b loop 0xbad6 */
    TR(0x0badd); CYC(67); WW(DS_, 0x44, (uint16_t)(RW(DS_, 0x44) + 1)); /* 089d:310d inc word ptr [0x44] */
    TR(0x0bae1); /* 089d:3111 cmp word ptr [0x44], 0xb4 */
    TR(0x0bae7); if ((int16_t)RW(DS_, 0x44) < (int16_t)0xb4) goto L0bacc; /* 089d:3117 jl 0xbacc */
    TR(0x0bae9); CYC(20); VH(0x0bae9); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3119 ret  */

/* ---- f_089d_311a */
L0baea:
    TR(0x0baea); CYC(104); PUSH(BX); /* 089d:311a push bx */
    TR(0x0baeb); PUSH(CX); /* 089d:311b push cx */
    TR(0x0baec); PUSH(DX); /* 089d:311c push dx */
    TR(0x0baed); DX = 0x312b; /* 089d:311d mov dx, 0x312b */
    TR(0x0baf0); BX = 0x1c; /* 089d:3120 mov bx, 0x1c */
    TR(0x0baf3); CX = 0x4b; /* 089d:3123 mov cx, 0x4b */
    TR(0x0baf6); PUSH(0x3129); goto L0b03c; /* 089d:3126 call 0xb03c */
L0baf9:
    TR(0x0baf9); CYC(15); goto L0bb01; /* 089d:3129 jmp 0xbb01 */
L0bb01:
    TR(0x0bb01); CYC(182); DX = POP(); /* 089d:3131 pop dx */
    TR(0x0bb02); CX = POP(); /* 089d:3132 pop cx */
    TR(0x0bb03); BX = POP(); /* 089d:3133 pop bx */
    TR(0x0bb04); PUSH(BX); /* 089d:3134 push bx */
    TR(0x0bb05); PUSH(CX); /* 089d:3135 push cx */
    TR(0x0bb06); PUSH(DX); /* 089d:3136 push dx */
    TR(0x0bb07); WW(DS_, 0x50de, 0x2e); /* 089d:3137 mov word ptr [0x50de], 0x2e */
    TR(0x0bb0d); WW(DS_, 0x50e0, 0x4b); /* 089d:313d mov word ptr [0x50e0], 0x4b */
    TR(0x0bb13); BX = RW(DS_, 0x5368); /* 089d:3143 mov bx, word ptr [0x5368] */
    TR(0x0bb17); DX = 0xa; /* 089d:3147 mov dx, 0xa */
    TR(0x0bb1a); PUSH(0x314d); goto L0b083; /* 089d:314a call 0xb083 */
L0bb1d:
    TR(0x0bb1d); CYC(436); DX = POP(); /* 089d:314d pop dx */
    TR(0x0bb1e); CX = POP(); /* 089d:314e pop cx */
    TR(0x0bb1f); BX = POP(); /* 089d:314f pop bx */
    TR(0x0bb20); WW(DS_, 0x4ff4, 0x0); /* 089d:3150 mov word ptr [0x4ff4], 0 */
    TR(0x0bb26); WW(DS_, 0x53e4, 0x0); /* 089d:3156 mov word ptr [0x53e4], 0 */
    TR(0x0bb2c); WW(DS_, 0x5456, 0x0); /* 089d:315c mov word ptr [0x5456], 0 */
    TR(0x0bb32); WW(DS_, 0x56b2, 0x0); /* 089d:3162 mov word ptr [0x56b2], 0 */
    TR(0x0bb38); WW(DS_, 0x59d8, 0x0); /* 089d:3168 mov word ptr [0x59d8], 0 */
    TR(0x0bb3e); WW(DS_, 0x505a, 0x0); /* 089d:316e mov word ptr [0x505a], 0 */
    TR(0x0bb44); WW(DS_, 0x5064, 0x0); /* 089d:3174 mov word ptr [0x5064], 0 */
    TR(0x0bb4a); WW(DS_, 0x5c86, 0x0); /* 089d:317a mov word ptr [0x5c86], 0 */
    TR(0x0bb50); WW(DS_, 0x5f46, 0x0); /* 089d:3180 mov word ptr [0x5f46], 0 */
    TR(0x0bb56); WW(DS_, 0x5fea, 0x0); /* 089d:3186 mov word ptr [0x5fea], 0 */
    TR(0x0bb5c); WW(DS_, 0x6190, 0x0); /* 089d:318c mov word ptr [0x6190], 0 */
    TR(0x0bb62); WW(DS_, 0x6272, 0x0); /* 089d:3192 mov word ptr [0x6272], 0 */
    TR(0x0bb68); WW(DS_, 0x62f8, 0x0); /* 089d:3198 mov word ptr [0x62f8], 0 */
    TR(0x0bb6e); WW(DS_, 0x6308, 0x0); /* 089d:319e mov word ptr [0x6308], 0 */
    TR(0x0bb74); WW(DS_, 0x667c, 0x0); /* 089d:31a4 mov word ptr [0x667c], 0 */
    TR(0x0bb7a); /* 089d:31aa cmp word ptr [0x5368], 1 */
    TR(0x0bb7f); if (RW(DS_, 0x5368) != 0x1) goto L0bb93; /* 089d:31af jne 0xbb93 */
    TR(0x0bb81); CYC(72); WW(DS_, 0x4ff4, 0x1); /* 089d:31b1 mov word ptr [0x4ff4], 1 */
    TR(0x0bb87); WW(DS_, 0x53e4, 0x1); /* 089d:31b7 mov word ptr [0x53e4], 1 */
    TR(0x0bb8d); WW(DS_, 0x505a, 0x1); /* 089d:31bd mov word ptr [0x505a], 1 */
L0bb93:
    TR(0x0bb93); CYC(40); /* 089d:31c3 cmp word ptr [0x5368], 2 */
    TR(0x0bb98); if (RW(DS_, 0x5368) != 0x2) goto L0bbb2; /* 089d:31c8 jne 0xbbb2 */
    TR(0x0bb9a); CYC(96); WW(DS_, 0x5456, 0x1); /* 089d:31ca mov word ptr [0x5456], 1 */
    TR(0x0bba0); WW(DS_, 0x53e4, 0x1); /* 089d:31d0 mov word ptr [0x53e4], 1 */
    TR(0x0bba6); WW(DS_, 0x505a, 0x1); /* 089d:31d6 mov word ptr [0x505a], 1 */
    TR(0x0bbac); WW(DS_, 0x4ff4, 0x1); /* 089d:31dc mov word ptr [0x4ff4], 1 */
L0bbb2:
    TR(0x0bbb2); CYC(40); /* 089d:31e2 cmp word ptr [0x5368], 3 */
    TR(0x0bbb7); if (RW(DS_, 0x5368) != 0x3) goto L0bbcb; /* 089d:31e7 jne 0xbbcb */
    TR(0x0bbb9); CYC(72); WW(DS_, 0x4ff4, 0x1); /* 089d:31e9 mov word ptr [0x4ff4], 1 */
    TR(0x0bbbf); WW(DS_, 0x56b2, 0x1); /* 089d:31ef mov word ptr [0x56b2], 1 */
    TR(0x0bbc5); WW(DS_, 0x505a, 0x1); /* 089d:31f5 mov word ptr [0x505a], 1 */
L0bbcb:
    TR(0x0bbcb); CYC(40); /* 089d:31fb cmp word ptr [0x5368], 4 */
    TR(0x0bbd0); if (RW(DS_, 0x5368) != 0x4) goto L0bbea; /* 089d:3200 jne 0xbbea */
    TR(0x0bbd2); CYC(96); WW(DS_, 0x59d8, 0x1); /* 089d:3202 mov word ptr [0x59d8], 1 */
    TR(0x0bbd8); WW(DS_, 0x5064, 0x1); /* 089d:3208 mov word ptr [0x5064], 1 */
    TR(0x0bbde); WW(DS_, 0x505a, 0x1); /* 089d:320e mov word ptr [0x505a], 1 */
    TR(0x0bbe4); WW(DS_, 0x53e4, 0x1); /* 089d:3214 mov word ptr [0x53e4], 1 */
L0bbea:
    TR(0x0bbea); CYC(40); /* 089d:321a cmp word ptr [0x5368], 5 */
    TR(0x0bbef); if (RW(DS_, 0x5368) != 0x5) goto L0bc0f; /* 089d:321f jne 0xbc0f */
    TR(0x0bbf1); CYC(120); WW(DS_, 0x5fea, 0x1); /* 089d:3221 mov word ptr [0x5fea], 1 */
    TR(0x0bbf7); WW(DS_, 0x6190, 0x1); /* 089d:3227 mov word ptr [0x6190], 1 */
    TR(0x0bbfd); WW(DS_, 0x505a, 0x1); /* 089d:322d mov word ptr [0x505a], 1 */
    TR(0x0bc03); WW(DS_, 0x5064, 0x1); /* 089d:3233 mov word ptr [0x5064], 1 */
    TR(0x0bc09); WW(DS_, 0x56b2, 0x1); /* 089d:3239 mov word ptr [0x56b2], 1 */
L0bc0f:
    TR(0x0bc0f); CYC(40); /* 089d:323f cmp word ptr [0x5368], 6 */
    TR(0x0bc14); if (RW(DS_, 0x5368) != 0x6) goto L0bc2e; /* 089d:3244 jne 0xbc2e */
    TR(0x0bc16); CYC(96); WW(DS_, 0x5c86, 0x1); /* 089d:3246 mov word ptr [0x5c86], 1 */
    TR(0x0bc1c); WW(DS_, 0x505a, 0x1); /* 089d:324c mov word ptr [0x505a], 1 */
    TR(0x0bc22); WW(DS_, 0x5f46, 0x1); /* 089d:3252 mov word ptr [0x5f46], 1 */
    TR(0x0bc28); WW(DS_, 0x5064, 0x1); /* 089d:3258 mov word ptr [0x5064], 1 */
L0bc2e:
    TR(0x0bc2e); CYC(40); /* 089d:325e cmp word ptr [0x5368], 7 */
    TR(0x0bc33); if (RW(DS_, 0x5368) != 0x7) goto L0bc53; /* 089d:3263 jne 0xbc53 */
    TR(0x0bc35); CYC(120); WW(DS_, 0x6272, 0x1); /* 089d:3265 mov word ptr [0x6272], 1 */
    TR(0x0bc3b); WW(DS_, 0x4ff4, 0x1); /* 089d:326b mov word ptr [0x4ff4], 1 */
    TR(0x0bc41); WW(DS_, 0x505a, 0x1); /* 089d:3271 mov word ptr [0x505a], 1 */
    TR(0x0bc47); WW(DS_, 0x5064, 0x1); /* 089d:3277 mov word ptr [0x5064], 1 */
    TR(0x0bc4d); WW(DS_, 0x62f8, 0x1); /* 089d:327d mov word ptr [0x62f8], 1 */
L0bc53:
    TR(0x0bc53); CYC(40); /* 089d:3283 cmp word ptr [0x5368], 8 */
    TR(0x0bc58); if (RW(DS_, 0x5368) != 0x8) goto L0bc78; /* 089d:3288 jne 0xbc78 */
    TR(0x0bc5a); CYC(120); WW(DS_, 0x6308, 0x1); /* 089d:328a mov word ptr [0x6308], 1 */
    TR(0x0bc60); WW(DS_, 0x505a, 0x1); /* 089d:3290 mov word ptr [0x505a], 1 */
    TR(0x0bc66); WW(DS_, 0x5064, 0x1); /* 089d:3296 mov word ptr [0x5064], 1 */
    TR(0x0bc6c); WW(DS_, 0x667c, 0x1); /* 089d:329c mov word ptr [0x667c], 1 */
    TR(0x0bc72); WW(DS_, 0x6190, 0x1); /* 089d:32a2 mov word ptr [0x6190], 1 */
L0bc78:
    TR(0x0bc78); CYC(40); /* 089d:32a8 cmp word ptr [0x5368], 9 */
    TR(0x0bc7d); if (RW(DS_, 0x5368) == 0x9) goto L0bc82; /* 089d:32ad je 0xbc82 */
    TR(0x0bc7f); CYC(15); goto L0bd3d; /* 089d:32af jmp 0xbd3d */
L0bc82:
    TR(0x0bc82); CYC(23); PUSH(0x32b5); goto L0bac0; /* 089d:32b2 call 0xbac0 */
L0bc85:
    TR(0x0bc85); CYC(104); PUSH(BX); /* 089d:32b5 push bx */
    TR(0x0bc86); PUSH(CX); /* 089d:32b6 push cx */
    TR(0x0bc87); PUSH(DX); /* 089d:32b7 push dx */
    TR(0x0bc88); DX = 0x32c6; /* 089d:32b8 mov dx, 0x32c6 */
    TR(0x0bc8b); BX = 0x7; /* 089d:32bb mov bx, 7 */
    TR(0x0bc8e); CX = 0x1e; /* 089d:32be mov cx, 0x1e */
    TR(0x0bc91); PUSH(0x32c4); goto L0b03c; /* 089d:32c1 call 0xb03c */
L0bc94:
    TR(0x0bc94); CYC(15); goto L0bcaa; /* 089d:32c4 jmp 0xbcaa */
L0bcaa:
    TR(0x0bcaa); CYC(140); DX = POP(); /* 089d:32da pop dx */
    TR(0x0bcab); CX = POP(); /* 089d:32db pop cx */
    TR(0x0bcac); BX = POP(); /* 089d:32dc pop bx */
    TR(0x0bcad); PUSH(BX); /* 089d:32dd push bx */
    TR(0x0bcae); PUSH(CX); /* 089d:32de push cx */
    TR(0x0bcaf); PUSH(DX); /* 089d:32df push dx */
    TR(0x0bcb0); DX = 0x32ee; /* 089d:32e0 mov dx, 0x32ee */
    TR(0x0bcb3); BX = 0x7; /* 089d:32e3 mov bx, 7 */
    TR(0x0bcb6); CX = 0x2d; /* 089d:32e6 mov cx, 0x2d */
    TR(0x0bcb9); PUSH(0x32ec); goto L0b03c; /* 089d:32e9 call 0xb03c */
L0bcbc:
    TR(0x0bcbc); CYC(15); goto L0bcd5; /* 089d:32ec jmp 0xbcd5 */
L0bcd5:
    TR(0x0bcd5); CYC(140); DX = POP(); /* 089d:3305 pop dx */
    TR(0x0bcd6); CX = POP(); /* 089d:3306 pop cx */
    TR(0x0bcd7); BX = POP(); /* 089d:3307 pop bx */
    TR(0x0bcd8); PUSH(BX); /* 089d:3308 push bx */
    TR(0x0bcd9); PUSH(CX); /* 089d:3309 push cx */
    TR(0x0bcda); PUSH(DX); /* 089d:330a push dx */
    TR(0x0bcdb); DX = 0x3319; /* 089d:330b mov dx, 0x3319 */
    TR(0x0bcde); BX = 0x7; /* 089d:330e mov bx, 7 */
    TR(0x0bce1); CX = 0x3c; /* 089d:3311 mov cx, 0x3c */
    TR(0x0bce4); PUSH(0x3317); goto L0b03c; /* 089d:3314 call 0xb03c */
L0bce7:
    TR(0x0bce7); CYC(15); goto L0bd00; /* 089d:3317 jmp 0xbd00 */
L0bd00:
    TR(0x0bd00); CYC(140); DX = POP(); /* 089d:3330 pop dx */
    TR(0x0bd01); CX = POP(); /* 089d:3331 pop cx */
    TR(0x0bd02); BX = POP(); /* 089d:3332 pop bx */
    TR(0x0bd03); PUSH(BX); /* 089d:3333 push bx */
    TR(0x0bd04); PUSH(CX); /* 089d:3334 push cx */
    TR(0x0bd05); PUSH(DX); /* 089d:3335 push dx */
    TR(0x0bd06); DX = 0x3344; /* 089d:3336 mov dx, 0x3344 */
    TR(0x0bd09); BX = 0x7; /* 089d:3339 mov bx, 7 */
    TR(0x0bd0c); CX = 0x4b; /* 089d:333c mov cx, 0x4b */
    TR(0x0bd0f); PUSH(0x3342); goto L0b03c; /* 089d:333f call 0xb03c */
L0bd12:
    TR(0x0bd12); CYC(15); goto L0bd26; /* 089d:3342 jmp 0xbd26 */
L0bd26:
    TR(0x0bd26); CYC(139); DX = POP(); /* 089d:3356 pop dx */
    TR(0x0bd27); CX = POP(); /* 089d:3357 pop cx */
    TR(0x0bd28); BX = POP(); /* 089d:3358 pop bx */
    TR(0x0bd29); WW(DS_, 0x5368, 0x1); /* 089d:3359 mov word ptr [0x5368], 1 */
    TR(0x0bd2f); AH = 0x0; /* 089d:335f mov ah, 0 */
    TR(0x0bd31); while (or_int16_wait()) or_poll(); do_int(0x16); /* 089d:3361 int 0x16 */
    TR(0x0bd33); CYC(23); PUSH(0x3366); goto L0bac0; /* 089d:3363 call 0xbac0 */
L0bd36:
    TR(0x0bd36); CYC(42); WW(DS_, 0x4178, (uint16_t)(RW(DS_, 0x4178) + 1)); /* 089d:3366 inc word ptr [0x4178] */
    TR(0x0bd3a); goto L0baea; /* 089d:336a jmp 0xbaea */
L0bd3d:
    TR(0x0bd3d); CYC(23); PUSH(0x3370); goto L0b397; /* 089d:336d call 0xb397 */
L0bd40:
    TR(0x0bd40); CYC(24); CX = 0x0; /* 089d:3370 mov cx, 0 */
    TR(0x0bd43); DX = 0x5; /* 089d:3373 mov dx, 5 */
L0bd46:
    TR(0x0bd46); CYC(17); SPIN(); /* 089d:3376 loop 0xbd46 */
    TR(0x0bd48); CYC(16); DX--; /* 089d:3378 dec dx */
    TR(0x0bd49); if ((uint16_t)DX != 0) goto L0bd46; /* 089d:3379 jne 0xbd46 */
    TR(0x0bd4b); CYC(23); PUSH(0x337e); goto L0bac0; /* 089d:337b call 0xbac0 */
L0bd4e:
    TR(0x0bd4e); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:337e ret  */

/* ---- f_089d_337f */
L0bd4f:
    TR(0x0bd4f); CYC(40); /* 089d:337f cmp word ptr [0x53e4], 1 */
    TR(0x0bd54); if (RW(DS_, 0x53e4) == 0x1) goto L0bd57; /* 089d:3384 je 0xbd57 */
    TR(0x0bd56); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3386 ret  */
L0bd57:
    TR(0x0bd57); CYC(30); CX = RW(DS_, 0x53e2); /* 089d:3387 mov cx, word ptr [0x53e2] */
    TR(0x0bd5b); BX = 0x0; /* 089d:338b mov bx, 0 */
L0bd5e:
    TR(0x0bd5e); CYC(40); /* 089d:338e cmp word ptr [bx + 0x5388], 0 */
    TR(0x0bd63); if (RW(DS_, (uint16_t)(BX + 0x5388)) == 0x0) goto L0bd68; /* 089d:3393 je 0xbd68 */
    TR(0x0bd65); CYC(23); PUSH(0x3398); goto L0bd6d; /* 089d:3395 call 0xbd6d */
L0bd68:
    TR(0x0bd68); CYC(25); BX++; /* 089d:3398 inc bx */
    TR(0x0bd69); BX++; /* 089d:3399 inc bx */
    TR(0x0bd6a); if (--CX) goto L0bd5e; /* 089d:339a loop 0xbd5e */
    TR(0x0bd6c); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:339c ret  */

/* ---- f_089d_339d */
L0bd6d:
    TR(0x0bd6d); CYC(23); PUSH(0x33a0); goto L0bea4; /* 089d:339d call 0xbea4 */
L0bd70:
    TR(0x0bd70); CYC(103); AX = RW(DS_, (uint16_t)(BX + 0x53c4)); /* 089d:33a0 mov ax, word ptr [bx + 0x53c4] */
    TR(0x0bd74); AX -= RW(DS_, 0x4a); /* 089d:33a4 sub ax, word ptr [0x4a] */
    TR(0x0bd78); WW(DS_, (uint16_t)(BX + 0x536a), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x536a)) + AX)); /* 089d:33a8 add word ptr [bx + 0x536a], ax */
    TR(0x0bd7c); /* 089d:33ac cmp word ptr [bx + 0x536a], 0 */
    TR(0x0bd81); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x536a)) >= (int16_t)0x0) goto L0bd89; /* 089d:33b1 jge 0xbd89 */
    TR(0x0bd83); CYC(24); WW(DS_, (uint16_t)(BX + 0x536a), 0x18ec); /* 089d:33b3 mov word ptr [bx + 0x536a], 0x18ec */
L0bd89:
    TR(0x0bd89); CYC(40); /* 089d:33b9 cmp word ptr [bx + 0x536a], 0x18ec */
    TR(0x0bd8f); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x536a)) <= (int16_t)0x18ec) goto L0bd97; /* 089d:33bf jle 0xbd97 */
    TR(0x0bd91); CYC(24); WW(DS_, (uint16_t)(BX + 0x536a), 0x0); /* 089d:33c1 mov word ptr [bx + 0x536a], 0 */
L0bd97:
    TR(0x0bd97); CYC(23); PUSH(0x33ca); goto L0bea4; /* 089d:33c7 call 0xbea4 */
L0bd9a:
    TR(0x0bd9a); CYC(45); PUSH(CX); /* 089d:33ca push cx */
    TR(0x0bd9b); CX = RW(DS_, 0x5062); /* 089d:33cb mov cx, word ptr [0x5062] */
    TR(0x0bd9f); SI = 0x0; /* 089d:33cf mov si, 0 */
L0bda2:
    TR(0x0bda2); CYC(40); /* 089d:33d2 cmp word ptr [si + 0x501e], 0 */
    TR(0x0bda7); if (RW(DS_, (uint16_t)(SI + 0x501e)) == 0x0) goto L0bdf7; /* 089d:33d7 je 0xbdf7 */
    TR(0x0bda9); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x536a)); /* 089d:33d9 mov ax, word ptr [bx + 0x536a] */
    TR(0x0bdad); /* 089d:33dd cmp word ptr [si + 0x4ff6], ax */
    TR(0x0bdb1); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x4ff6)) < (int16_t)AX) goto L0bdf7; /* 089d:33e1 jl 0xbdf7 */
    TR(0x0bdb3); CYC(52); AX += 0x14; /* 089d:33e3 add ax, 0x14 */
    TR(0x0bdb6); /* 089d:33e6 cmp word ptr [si + 0x4ff6], ax */
    TR(0x0bdba); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x4ff6)) > (int16_t)AX) goto L0bdf7; /* 089d:33ea jg 0xbdf7 */
    TR(0x0bdbc); CYC(52); AX = 0xa7; /* 089d:33ec mov ax, 0xa7 */
    TR(0x0bdbf); /* 089d:33ef cmp word ptr [si + 0x500a], ax */
    TR(0x0bdc3); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) < (int16_t)AX) goto L0bdf7; /* 089d:33f3 jl 0xbdf7 */
    TR(0x0bdc5); CYC(154); WW(DS_, 0x50d6, 0x1); /* 089d:33f5 mov word ptr [0x50d6], 1 */
    TR(0x0bdcb); AX = RW(DS_, (uint16_t)(BX + 0x536a)); /* 089d:33fb mov ax, word ptr [bx + 0x536a] */
    TR(0x0bdcf); WW(DS_, 0x50d8, AX); /* 089d:33ff mov word ptr [0x50d8], ax */
    TR(0x0bdd2); WW(DS_, 0x50da, 0xa1); /* 089d:3402 mov word ptr [0x50da], 0xa1 */
    TR(0x0bdd8); WW(DS_, (uint16_t)(SI + 0x501e), 0x0); /* 089d:3408 mov word ptr [si + 0x501e], 0 */
    TR(0x0bdde); PUSH(BX); /* 089d:340e push bx */
    TR(0x0bddf); BX = SI; /* 089d:340f mov bx, si */
    TR(0x0bde1); PUSH(0x3414); goto L0b66e; /* 089d:3411 call 0xb66e */
L0bde4:
    TR(0x0bde4); CYC(59); BX = POP(); /* 089d:3414 pop bx */
    TR(0x0bde5); WW(DS_, (uint16_t)(BX + 0x5388), 0x0); /* 089d:3415 mov word ptr [bx + 0x5388], 0 */
    TR(0x0bdeb); PUSH(0x341e); goto L0bea4; /* 089d:341b call 0xbea4 */
L0bdee:
    TR(0x0bdee); CYC(35); AX = 0x32; /* 089d:341e mov ax, 0x32 */
    TR(0x0bdf1); PUSH(0x3424); goto L0b829; /* 089d:3421 call 0xb829 */
L0bdf4:
    TR(0x0bdf4); CYC(15); goto L0bdfb; /* 089d:3424 jmp 0xbdfb */
L0bdf7:
    TR(0x0bdf7); CYC(25); SI++; /* 089d:3427 inc si */
    TR(0x0bdf8); SI++; /* 089d:3428 inc si */
    TR(0x0bdf9); if (--CX) goto L0bda2; /* 089d:3429 loop 0xbda2 */
L0bdfb:
    TR(0x0bdfb); CYC(52); CX = POP(); /* 089d:342b pop cx */
    TR(0x0bdfc); /* 089d:342c cmp word ptr [bx + 0x53a6], 1 */
    TR(0x0be01); if (RW(DS_, (uint16_t)(BX + 0x53a6)) == 0x1) goto L0be55; /* 089d:3431 je 0xbe55 */
    TR(0x0be03); CYC(40); /* 089d:3433 cmp word ptr [0x4176], 1 */
    TR(0x0be08); if (RW(DS_, 0x4176) != 0x1) goto L0be55; /* 089d:3438 jne 0xbe55 */
    TR(0x0be0a); CYC(68); AX = RW(DS_, 0x4170); /* 089d:343a mov ax, word ptr [0x4170] */
    TR(0x0be0d); DX = RW(DS_, (uint16_t)(BX + 0x536a)); /* 089d:343d mov dx, word ptr [bx + 0x536a] */
    TR(0x0be11); AX += 0x14; /* 089d:3441 add ax, 0x14 */
    TR(0x0be14); /* 089d:3444 cmp ax, dx */
    TR(0x0be16); if ((int16_t)AX < (int16_t)DX) goto L0be55; /* 089d:3446 jl 0xbe55 */
    TR(0x0be18); CYC(44); AX -= 0x14; /* 089d:3448 sub ax, 0x14 */
    TR(0x0be1b); DX += 0x14; /* 089d:344b add dx, 0x14 */
    TR(0x0be1e); /* 089d:344e cmp ax, dx */
    TR(0x0be20); if ((int16_t)AX > (int16_t)DX) goto L0be55; /* 089d:3450 jg 0xbe55 */
    TR(0x0be22); CYC(59); WW(DS_, (uint16_t)(BX + 0x53a6), 0x1); /* 089d:3452 mov word ptr [bx + 0x53a6], 1 */
    TR(0x0be28); AX = 0x64; /* 089d:3458 mov ax, 0x64 */
    TR(0x0be2b); PUSH(0x345e); goto L0b829; /* 089d:345b call 0xb829 */
L0be2e:
    TR(0x0be2e); CYC(173); WW(DS_, 0x5160, 0x1); /* 089d:345e mov word ptr [0x5160], 1 */
    TR(0x0be34); AX = RW(DS_, (uint16_t)(BX + 0x536a)); /* 089d:3464 mov ax, word ptr [bx + 0x536a] */
    TR(0x0be38); AX += 0x8; /* 089d:3468 add ax, 8 */
    TR(0x0be3b); AX -= RW(DS_, 0x4a); /* 089d:346b sub ax, word ptr [0x4a] */
    TR(0x0be3f); WW(DS_, 0x5162, AX); /* 089d:346f mov word ptr [0x5162], ax */
    TR(0x0be42); WW(DS_, 0x5164, 0x9d); /* 089d:3472 mov word ptr [0x5164], 0x9d */
    TR(0x0be48); WW(DS_, 0x5166, 0x3); /* 089d:3478 mov word ptr [0x5166], 3 */
    TR(0x0be4e); AX = RW(DS_, (uint16_t)(BX + 0x53c4)); /* 089d:347e mov ax, word ptr [bx + 0x53c4] */
    TR(0x0be52); WW(DS_, 0x516a, AX); /* 089d:3482 mov word ptr [0x516a], ax */
L0be55:
    TR(0x0be55); CYC(40); /* 089d:3485 cmp word ptr [0x4176], 1 */
    TR(0x0be5a); if (RW(DS_, 0x4176) != 0x1) goto L0bea3; /* 089d:348a jne 0xbea3 */
    TR(0x0be5c); CYC(68); AX = RW(DS_, 0x4170); /* 089d:348c mov ax, word ptr [0x4170] */
    TR(0x0be5f); DX = RW(DS_, (uint16_t)(BX + 0x536a)); /* 089d:348f mov dx, word ptr [bx + 0x536a] */
    TR(0x0be63); AX += 0x14; /* 089d:3493 add ax, 0x14 */
    TR(0x0be66); /* 089d:3496 cmp ax, dx */
    TR(0x0be68); if ((int16_t)AX < (int16_t)DX) goto L0bea3; /* 089d:3498 jl 0xbea3 */
    TR(0x0be6a); CYC(44); AX -= 0x14; /* 089d:349a sub ax, 0x14 */
    TR(0x0be6d); DX += 0x14; /* 089d:349d add dx, 0x14 */
    TR(0x0be70); /* 089d:34a0 cmp ax, dx */
    TR(0x0be72); if ((int16_t)AX > (int16_t)DX) goto L0bea3; /* 089d:34a2 jg 0xbea3 */
    TR(0x0be74); CYC(62); AX = RW(DS_, 0x4172); /* 089d:34a4 mov ax, word ptr [0x4172] */
    TR(0x0be77); DX = 0xab; /* 089d:34a7 mov dx, 0xab */
    TR(0x0be7a); AX += 0xe; /* 089d:34aa add ax, 0xe */
    TR(0x0be7d); /* 089d:34ad cmp ax, dx */
    TR(0x0be7f); if ((int16_t)AX < (int16_t)DX) goto L0bea3; /* 089d:34af jl 0xbea3 */
    TR(0x0be81); CYC(155); WW(DS_, 0x5360, 0x1); /* 089d:34b1 mov word ptr [0x5360], 1 */
    TR(0x0be87); WW(DS_, 0x50d6, 0x1); /* 089d:34b7 mov word ptr [0x50d6], 1 */
    TR(0x0be8d); AX = RW(DS_, (uint16_t)(BX + 0x536a)); /* 089d:34bd mov ax, word ptr [bx + 0x536a] */
    TR(0x0be91); WW(DS_, 0x50d8, AX); /* 089d:34c1 mov word ptr [0x50d8], ax */
    TR(0x0be94); WW(DS_, 0x50da, 0xa1); /* 089d:34c4 mov word ptr [0x50da], 0xa1 */
    TR(0x0be9a); WW(DS_, (uint16_t)(BX + 0x5388), 0x0); /* 089d:34ca mov word ptr [bx + 0x5388], 0 */
    TR(0x0bea0); PUSH(0x34d3); goto L0bea4; /* 089d:34d0 call 0xbea4 */
L0bea3:
    TR(0x0bea3); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:34d3 ret  */

/* ---- f_089d_34d4 */
L0bea4:
    TR(0x0bea4); CYC(40); /* 089d:34d4 cmp word ptr [bx + 0x536a], 0x12f */
    TR(0x0beaa); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x536a)) > (int16_t)0x12f) goto L0bef1; /* 089d:34da jg 0xbef1 */
    TR(0x0beac); CYC(40); /* 089d:34dc cmp word ptr [bx + 0x536a], 0 */
    TR(0x0beb1); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x536a)) < (int16_t)0x0) goto L0bef1; /* 089d:34e1 jl 0xbef1 */
    TR(0x0beb3); CYC(334); PUSH(BX); /* 089d:34e3 push bx */
    TR(0x0beb4); PUSH(CX); /* 089d:34e4 push cx */
    TR(0x0beb5); PUSH(DX); /* 089d:34e5 push dx */
    TR(0x0beb6); PUSH(SI); /* 089d:34e6 push si */
    TR(0x0beb7); PUSH(DI); /* 089d:34e7 push di */
    TR(0x0beb8); AX = 0x0; /* 089d:34e8 mov ax, 0 */
    TR(0x0bebb); AX += AX; /* 089d:34eb add ax, ax */
    TR(0x0bebd); DI = AX; /* 089d:34ed mov di, ax */
    TR(0x0bebf); SI = RW(DS_, (uint16_t)(DI + 0x7725)); /* 089d:34ef mov si, word ptr [di + 0x7725] */
    TR(0x0bec3); DL = RB(DS_, SI); /* 089d:34f3 mov dl, byte ptr [si] */
    TR(0x0bec5); DH = DL; /* 089d:34f5 mov dh, dl */
    TR(0x0bec7); SI++; /* 089d:34f7 inc si */
    TR(0x0bec8); CH = RB(DS_, SI); /* 089d:34f8 mov ch, byte ptr [si] */
    TR(0x0beca); SI++; /* 089d:34fa inc si */
    TR(0x0becb); WW(DS_, 0x36, SI); /* 089d:34fb mov word ptr [0x36], si */
    TR(0x0becf); AX = 0xa7; /* 089d:34ff mov ax, 0xa7 */
    TR(0x0bed2); WW(DS_, 0x2e, AX); /* 089d:3502 mov word ptr [0x2e], ax */
    TR(0x0bed5); BX = RW(DS_, (uint16_t)(BX + 0x536a)); /* 089d:3505 mov bx, word ptr [bx + 0x536a] */
    TR(0x0bed9); AX = RW(DS_, (uint16_t)(BX + 0x680e)); /* 089d:3509 mov ax, word ptr [bx + 0x680e] */
    TR(0x0bedd); AH = 0x0; /* 089d:350d mov ah, 0 */
    TR(0x0bedf); WW(DS_, 0x2c, AX); /* 089d:350f mov word ptr [0x2c], ax */
    TR(0x0bee2); AX = RW(DS_, (uint16_t)(BX + 0x695c)); /* 089d:3512 mov ax, word ptr [bx + 0x695c] */
    TR(0x0bee6); WW(DS_, 0x3a, AX); /* 089d:3516 mov word ptr [0x3a], ax */
    TR(0x0bee9); PUSH(0x351c); goto L0ae25; /* 089d:3519 call 0xae25 */
L0beec:
    TR(0x0beec); CYC(60); DI = POP(); /* 089d:351c pop di */
    TR(0x0beed); SI = POP(); /* 089d:351d pop si */
    TR(0x0beee); DX = POP(); /* 089d:351e pop dx */
    TR(0x0beef); CX = POP(); /* 089d:351f pop cx */
    TR(0x0bef0); BX = POP(); /* 089d:3520 pop bx */
L0bef1:
    TR(0x0bef1); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3521 ret  */

/* ---- f_089d_3522 */
L0bef2:
    TR(0x0bef2); CYC(40); /* 089d:3522 cmp word ptr [0x5456], 1 */
    TR(0x0bef7); if (RW(DS_, 0x5456) == 0x1) goto L0befa; /* 089d:3527 je 0xbefa */
    TR(0x0bef9); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3529 ret  */
L0befa:
    TR(0x0befa); CYC(30); CX = RW(DS_, 0x5454); /* 089d:352a mov cx, word ptr [0x5454] */
    TR(0x0befe); BX = 0x0; /* 089d:352e mov bx, 0 */
L0bf01:
    TR(0x0bf01); CYC(40); /* 089d:3531 cmp word ptr [bx + 0x5404], 0 */
    TR(0x0bf06); if (RW(DS_, (uint16_t)(BX + 0x5404)) == 0x0) goto L0bf0b; /* 089d:3536 je 0xbf0b */
    TR(0x0bf08); CYC(23); PUSH(0x353b); goto L0bf10; /* 089d:3538 call 0xbf10 */
L0bf0b:
    TR(0x0bf0b); CYC(25); BX++; /* 089d:353b inc bx */
    TR(0x0bf0c); BX++; /* 089d:353c inc bx */
    TR(0x0bf0d); if (--CX) goto L0bf01; /* 089d:353d loop 0xbf01 */
    TR(0x0bf0f); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:353f ret  */

/* ---- f_089d_3540 */
L0bf10:
    TR(0x0bf10); CYC(23); PUSH(0x3543); goto L0c047; /* 089d:3540 call 0xc047 */
L0bf13:
    TR(0x0bf13); CYC(103); AX = RW(DS_, (uint16_t)(BX + 0x5422)); /* 089d:3543 mov ax, word ptr [bx + 0x5422] */
    TR(0x0bf17); AX -= RW(DS_, 0x4a); /* 089d:3547 sub ax, word ptr [0x4a] */
    TR(0x0bf1b); WW(DS_, (uint16_t)(BX + 0x53e6), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x53e6)) + AX)); /* 089d:354b add word ptr [bx + 0x53e6], ax */
    TR(0x0bf1f); /* 089d:354f cmp word ptr [bx + 0x53e6], 0 */
    TR(0x0bf24); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x53e6)) >= (int16_t)0x0) goto L0bf2c; /* 089d:3554 jge 0xbf2c */
    TR(0x0bf26); CYC(24); WW(DS_, (uint16_t)(BX + 0x53e6), 0x18ec); /* 089d:3556 mov word ptr [bx + 0x53e6], 0x18ec */
L0bf2c:
    TR(0x0bf2c); CYC(40); /* 089d:355c cmp word ptr [bx + 0x53e6], 0x18ec */
    TR(0x0bf32); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x53e6)) <= (int16_t)0x18ec) goto L0bf3a; /* 089d:3562 jle 0xbf3a */
    TR(0x0bf34); CYC(24); WW(DS_, (uint16_t)(BX + 0x53e6), 0x0); /* 089d:3564 mov word ptr [bx + 0x53e6], 0 */
L0bf3a:
    TR(0x0bf3a); CYC(23); PUSH(0x356d); goto L0c047; /* 089d:356a call 0xc047 */
L0bf3d:
    TR(0x0bf3d); CYC(45); PUSH(CX); /* 089d:356d push cx */
    TR(0x0bf3e); CX = RW(DS_, 0x5062); /* 089d:356e mov cx, word ptr [0x5062] */
    TR(0x0bf42); SI = 0x0; /* 089d:3572 mov si, 0 */
L0bf45:
    TR(0x0bf45); CYC(40); /* 089d:3575 cmp word ptr [si + 0x501e], 0 */
    TR(0x0bf4a); if (RW(DS_, (uint16_t)(SI + 0x501e)) == 0x0) goto L0bf9a; /* 089d:357a je 0xbf9a */
    TR(0x0bf4c); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x53e6)); /* 089d:357c mov ax, word ptr [bx + 0x53e6] */
    TR(0x0bf50); /* 089d:3580 cmp word ptr [si + 0x4ff6], ax */
    TR(0x0bf54); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x4ff6)) < (int16_t)AX) goto L0bf9a; /* 089d:3584 jl 0xbf9a */
    TR(0x0bf56); CYC(52); AX += 0x14; /* 089d:3586 add ax, 0x14 */
    TR(0x0bf59); /* 089d:3589 cmp word ptr [si + 0x4ff6], ax */
    TR(0x0bf5d); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x4ff6)) > (int16_t)AX) goto L0bf9a; /* 089d:358d jg 0xbf9a */
    TR(0x0bf5f); CYC(52); AX = 0xa7; /* 089d:358f mov ax, 0xa7 */
    TR(0x0bf62); /* 089d:3592 cmp word ptr [si + 0x500a], ax */
    TR(0x0bf66); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) < (int16_t)AX) goto L0bf9a; /* 089d:3596 jl 0xbf9a */
    TR(0x0bf68); CYC(154); WW(DS_, 0x50d6, 0x1); /* 089d:3598 mov word ptr [0x50d6], 1 */
    TR(0x0bf6e); AX = RW(DS_, (uint16_t)(BX + 0x53e6)); /* 089d:359e mov ax, word ptr [bx + 0x53e6] */
    TR(0x0bf72); WW(DS_, 0x50d8, AX); /* 089d:35a2 mov word ptr [0x50d8], ax */
    TR(0x0bf75); WW(DS_, 0x50da, 0xa1); /* 089d:35a5 mov word ptr [0x50da], 0xa1 */
    TR(0x0bf7b); WW(DS_, (uint16_t)(SI + 0x501e), 0x0); /* 089d:35ab mov word ptr [si + 0x501e], 0 */
    TR(0x0bf81); PUSH(BX); /* 089d:35b1 push bx */
    TR(0x0bf82); BX = SI; /* 089d:35b2 mov bx, si */
    TR(0x0bf84); PUSH(0x35b7); goto L0b66e; /* 089d:35b4 call 0xb66e */
L0bf87:
    TR(0x0bf87); CYC(59); BX = POP(); /* 089d:35b7 pop bx */
    TR(0x0bf88); WW(DS_, (uint16_t)(BX + 0x5404), 0x0); /* 089d:35b8 mov word ptr [bx + 0x5404], 0 */
    TR(0x0bf8e); PUSH(0x35c1); goto L0c047; /* 089d:35be call 0xc047 */
L0bf91:
    TR(0x0bf91); CYC(35); AX = 0x32; /* 089d:35c1 mov ax, 0x32 */
    TR(0x0bf94); PUSH(0x35c7); goto L0b829; /* 089d:35c4 call 0xb829 */
L0bf97:
    TR(0x0bf97); CYC(15); goto L0bf9e; /* 089d:35c7 jmp 0xbf9e */
L0bf9a:
    TR(0x0bf9a); CYC(25); SI++; /* 089d:35ca inc si */
    TR(0x0bf9b); SI++; /* 089d:35cb inc si */
    TR(0x0bf9c); if (--CX) goto L0bf45; /* 089d:35cc loop 0xbf45 */
L0bf9e:
    TR(0x0bf9e); CYC(52); CX = POP(); /* 089d:35ce pop cx */
    TR(0x0bf9f); /* 089d:35cf cmp word ptr [bx + 0x5440], 1 */
    TR(0x0bfa4); if (RW(DS_, (uint16_t)(BX + 0x5440)) == 0x1) goto L0bff8; /* 089d:35d4 je 0xbff8 */
    TR(0x0bfa6); CYC(40); /* 089d:35d6 cmp word ptr [0x4176], 1 */
    TR(0x0bfab); if (RW(DS_, 0x4176) != 0x1) goto L0bff8; /* 089d:35db jne 0xbff8 */
    TR(0x0bfad); CYC(68); AX = RW(DS_, 0x4170); /* 089d:35dd mov ax, word ptr [0x4170] */
    TR(0x0bfb0); DX = RW(DS_, (uint16_t)(BX + 0x53e6)); /* 089d:35e0 mov dx, word ptr [bx + 0x53e6] */
    TR(0x0bfb4); AX += 0x14; /* 089d:35e4 add ax, 0x14 */
    TR(0x0bfb7); /* 089d:35e7 cmp ax, dx */
    TR(0x0bfb9); if ((int16_t)AX < (int16_t)DX) goto L0bff8; /* 089d:35e9 jl 0xbff8 */
    TR(0x0bfbb); CYC(44); AX -= 0x14; /* 089d:35eb sub ax, 0x14 */
    TR(0x0bfbe); DX += 0x18; /* 089d:35ee add dx, 0x18 */
    TR(0x0bfc1); /* 089d:35f1 cmp ax, dx */
    TR(0x0bfc3); if ((int16_t)AX > (int16_t)DX) goto L0bff8; /* 089d:35f3 jg 0xbff8 */
    TR(0x0bfc5); CYC(59); WW(DS_, (uint16_t)(BX + 0x5440), 0x1); /* 089d:35f5 mov word ptr [bx + 0x5440], 1 */
    TR(0x0bfcb); AX = 0x64; /* 089d:35fb mov ax, 0x64 */
    TR(0x0bfce); PUSH(0x3601); goto L0b829; /* 089d:35fe call 0xb829 */
L0bfd1:
    TR(0x0bfd1); CYC(173); WW(DS_, 0x5160, 0x1); /* 089d:3601 mov word ptr [0x5160], 1 */
    TR(0x0bfd7); AX = RW(DS_, (uint16_t)(BX + 0x53e6)); /* 089d:3607 mov ax, word ptr [bx + 0x53e6] */
    TR(0x0bfdb); AX += 0x3; /* 089d:360b add ax, 3 */
    TR(0x0bfde); AX -= RW(DS_, 0x4a); /* 089d:360e sub ax, word ptr [0x4a] */
    TR(0x0bfe2); WW(DS_, 0x5162, AX); /* 089d:3612 mov word ptr [0x5162], ax */
    TR(0x0bfe5); WW(DS_, 0x5164, 0x9d); /* 089d:3615 mov word ptr [0x5164], 0x9d */
    TR(0x0bfeb); WW(DS_, 0x5166, 0x3); /* 089d:361b mov word ptr [0x5166], 3 */
    TR(0x0bff1); AX = RW(DS_, (uint16_t)(BX + 0x5422)); /* 089d:3621 mov ax, word ptr [bx + 0x5422] */
    TR(0x0bff5); WW(DS_, 0x516a, AX); /* 089d:3625 mov word ptr [0x516a], ax */
L0bff8:
    TR(0x0bff8); CYC(40); /* 089d:3628 cmp word ptr [0x4176], 1 */
    TR(0x0bffd); if (RW(DS_, 0x4176) != 0x1) goto L0c046; /* 089d:362d jne 0xc046 */
    TR(0x0bfff); CYC(68); AX = RW(DS_, 0x4170); /* 089d:362f mov ax, word ptr [0x4170] */
    TR(0x0c002); DX = RW(DS_, (uint16_t)(BX + 0x53e6)); /* 089d:3632 mov dx, word ptr [bx + 0x53e6] */
    TR(0x0c006); AX += 0x14; /* 089d:3636 add ax, 0x14 */
    TR(0x0c009); /* 089d:3639 cmp ax, dx */
    TR(0x0c00b); if ((int16_t)AX < (int16_t)DX) goto L0c046; /* 089d:363b jl 0xc046 */
    TR(0x0c00d); CYC(44); AX -= 0x14; /* 089d:363d sub ax, 0x14 */
    TR(0x0c010); DX += 0x18; /* 089d:3640 add dx, 0x18 */
    TR(0x0c013); /* 089d:3643 cmp ax, dx */
    TR(0x0c015); if ((int16_t)AX > (int16_t)DX) goto L0c046; /* 089d:3645 jg 0xc046 */
    TR(0x0c017); CYC(62); AX = RW(DS_, 0x4172); /* 089d:3647 mov ax, word ptr [0x4172] */
    TR(0x0c01a); DX = 0xab; /* 089d:364a mov dx, 0xab */
    TR(0x0c01d); AX += 0xe; /* 089d:364d add ax, 0xe */
    TR(0x0c020); /* 089d:3650 cmp ax, dx */
    TR(0x0c022); if ((int16_t)AX < (int16_t)DX) goto L0c046; /* 089d:3652 jl 0xc046 */
    TR(0x0c024); CYC(155); WW(DS_, 0x5360, 0x1); /* 089d:3654 mov word ptr [0x5360], 1 */
    TR(0x0c02a); WW(DS_, 0x50d6, 0x1); /* 089d:365a mov word ptr [0x50d6], 1 */
    TR(0x0c030); AX = RW(DS_, (uint16_t)(BX + 0x53e6)); /* 089d:3660 mov ax, word ptr [bx + 0x53e6] */
    TR(0x0c034); WW(DS_, 0x50d8, AX); /* 089d:3664 mov word ptr [0x50d8], ax */
    TR(0x0c037); WW(DS_, 0x50da, 0xa1); /* 089d:3667 mov word ptr [0x50da], 0xa1 */
    TR(0x0c03d); WW(DS_, (uint16_t)(BX + 0x5404), 0x0); /* 089d:366d mov word ptr [bx + 0x5404], 0 */
    TR(0x0c043); PUSH(0x3676); goto L0c047; /* 089d:3673 call 0xc047 */
L0c046:
    TR(0x0c046); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3676 ret  */

/* ---- f_089d_3677 */
L0c047:
    TR(0x0c047); CYC(40); /* 089d:3677 cmp word ptr [bx + 0x53e6], 0x127 */
    TR(0x0c04d); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x53e6)) > (int16_t)0x127) goto L0c094; /* 089d:367d jg 0xc094 */
    TR(0x0c04f); CYC(40); /* 089d:367f cmp word ptr [bx + 0x53e6], 0 */
    TR(0x0c054); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x53e6)) < (int16_t)0x0) goto L0c094; /* 089d:3684 jl 0xc094 */
    TR(0x0c056); CYC(334); PUSH(BX); /* 089d:3686 push bx */
    TR(0x0c057); PUSH(CX); /* 089d:3687 push cx */
    TR(0x0c058); PUSH(DX); /* 089d:3688 push dx */
    TR(0x0c059); PUSH(SI); /* 089d:3689 push si */
    TR(0x0c05a); PUSH(DI); /* 089d:368a push di */
    TR(0x0c05b); AX = 0x0; /* 089d:368b mov ax, 0 */
    TR(0x0c05e); AX += AX; /* 089d:368e add ax, ax */
    TR(0x0c060); DI = AX; /* 089d:3690 mov di, ax */
    TR(0x0c062); SI = RW(DS_, (uint16_t)(DI + 0x776a)); /* 089d:3692 mov si, word ptr [di + 0x776a] */
    TR(0x0c066); DL = RB(DS_, SI); /* 089d:3696 mov dl, byte ptr [si] */
    TR(0x0c068); DH = DL; /* 089d:3698 mov dh, dl */
    TR(0x0c06a); SI++; /* 089d:369a inc si */
    TR(0x0c06b); CH = RB(DS_, SI); /* 089d:369b mov ch, byte ptr [si] */
    TR(0x0c06d); SI++; /* 089d:369d inc si */
    TR(0x0c06e); WW(DS_, 0x36, SI); /* 089d:369e mov word ptr [0x36], si */
    TR(0x0c072); AX = 0xa8; /* 089d:36a2 mov ax, 0xa8 */
    TR(0x0c075); WW(DS_, 0x2e, AX); /* 089d:36a5 mov word ptr [0x2e], ax */
    TR(0x0c078); BX = RW(DS_, (uint16_t)(BX + 0x53e6)); /* 089d:36a8 mov bx, word ptr [bx + 0x53e6] */
    TR(0x0c07c); AX = RW(DS_, (uint16_t)(BX + 0x680e)); /* 089d:36ac mov ax, word ptr [bx + 0x680e] */
    TR(0x0c080); AH = 0x0; /* 089d:36b0 mov ah, 0 */
    TR(0x0c082); WW(DS_, 0x2c, AX); /* 089d:36b2 mov word ptr [0x2c], ax */
    TR(0x0c085); AX = RW(DS_, (uint16_t)(BX + 0x695c)); /* 089d:36b5 mov ax, word ptr [bx + 0x695c] */
    TR(0x0c089); WW(DS_, 0x3a, AX); /* 089d:36b9 mov word ptr [0x3a], ax */
    TR(0x0c08c); PUSH(0x36bf); goto L0ae25; /* 089d:36bc call 0xae25 */
L0c08f:
    TR(0x0c08f); CYC(60); DI = POP(); /* 089d:36bf pop di */
    TR(0x0c090); SI = POP(); /* 089d:36c0 pop si */
    TR(0x0c091); DX = POP(); /* 089d:36c1 pop dx */
    TR(0x0c092); CX = POP(); /* 089d:36c2 pop cx */
    TR(0x0c093); BX = POP(); /* 089d:36c3 pop bx */
L0c094:
    TR(0x0c094); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:36c4 ret  */

/* ---- f_089d_36c5 */
L0c095:
    TR(0x0c095); CYC(40); /* 089d:36c5 cmp word ptr [0x417a], 0xc6c */
    TR(0x0c09b); if ((int16_t)RW(DS_, 0x417a) < (int16_t)0xc6c) goto L0c0ad; /* 089d:36cb jl 0xc0ad */
    TR(0x0c09d); CYC(50); WW(DS_, 0x5368, (uint16_t)(RW(DS_, 0x5368) + 1)); /* 089d:36cd inc word ptr [0x5368] */
    TR(0x0c0a1); PUSH(0x36d4); goto L0bac0; /* 089d:36d1 call 0xbac0 */
L0c0a4:
    TR(0x0c0a4); CYC(23); PUSH(0x36d7); goto L0baea; /* 089d:36d4 call 0xbaea */
L0c0a7:
    TR(0x0c0a7); CYC(23); PUSH(0x36da); goto L0b397; /* 089d:36d7 call 0xb397 */
L0c0aa:
    TR(0x0c0aa); CYC(23); PUSH(0x36dd); goto L08aca; /* 089d:36da call 0x8aca */
L0c0ad:
    TR(0x0c0ad); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:36dd ret  */

/* ---- f_089d_36de */
L0c0ae:
    TR(0x0c0ae); CYC(40); /* 089d:36de cmp word ptr [bx + 0x5458], 0x12b */
    TR(0x0c0b4); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x5458)) > (int16_t)0x12b) goto L0c101; /* 089d:36e4 jg 0xc101 */
    TR(0x0c0b6); CYC(40); /* 089d:36e6 cmp word ptr [bx + 0x5458], 0 */
    TR(0x0c0bb); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x5458)) < (int16_t)0x0) goto L0c101; /* 089d:36eb jl 0xc101 */
    TR(0x0c0bd); CYC(362); AX = RW(DS_, (uint16_t)(BX + 0x54bc)); /* 089d:36ed mov ax, word ptr [bx + 0x54bc] */
    TR(0x0c0c1); AX >>= 1; /* 089d:36f1 shr ax, 1 */
    TR(0x0c0c3); PUSH(BX); /* 089d:36f3 push bx */
    TR(0x0c0c4); PUSH(CX); /* 089d:36f4 push cx */
    TR(0x0c0c5); PUSH(DX); /* 089d:36f5 push dx */
    TR(0x0c0c6); PUSH(SI); /* 089d:36f6 push si */
    TR(0x0c0c7); PUSH(DI); /* 089d:36f7 push di */
    TR(0x0c0c8); AX = AX; /* 089d:36f8 mov ax, ax */
    TR(0x0c0ca); AX += AX; /* 089d:36fa add ax, ax */
    TR(0x0c0cc); DI = AX; /* 089d:36fc mov di, ax */
    TR(0x0c0ce); SI = RW(DS_, (uint16_t)(DI + 0x77b6)); /* 089d:36fe mov si, word ptr [di + 0x77b6] */
    TR(0x0c0d2); DL = RB(DS_, SI); /* 089d:3702 mov dl, byte ptr [si] */
    TR(0x0c0d4); DH = DL; /* 089d:3704 mov dh, dl */
    TR(0x0c0d6); SI++; /* 089d:3706 inc si */
    TR(0x0c0d7); CH = RB(DS_, SI); /* 089d:3707 mov ch, byte ptr [si] */
    TR(0x0c0d9); SI++; /* 089d:3709 inc si */
    TR(0x0c0da); WW(DS_, 0x36, SI); /* 089d:370a mov word ptr [0x36], si */
    TR(0x0c0de); AX = RW(DS_, (uint16_t)(BX + 0x564c)); /* 089d:370e mov ax, word ptr [bx + 0x564c] */
    TR(0x0c0e2); WW(DS_, 0x2e, AX); /* 089d:3712 mov word ptr [0x2e], ax */
    TR(0x0c0e5); BX = RW(DS_, (uint16_t)(BX + 0x5458)); /* 089d:3715 mov bx, word ptr [bx + 0x5458] */
    TR(0x0c0e9); AX = RW(DS_, (uint16_t)(BX + 0x680e)); /* 089d:3719 mov ax, word ptr [bx + 0x680e] */
    TR(0x0c0ed); AH = 0x0; /* 089d:371d mov ah, 0 */
    TR(0x0c0ef); WW(DS_, 0x2c, AX); /* 089d:371f mov word ptr [0x2c], ax */
    TR(0x0c0f2); AX = RW(DS_, (uint16_t)(BX + 0x695c)); /* 089d:3722 mov ax, word ptr [bx + 0x695c] */
    TR(0x0c0f6); WW(DS_, 0x3a, AX); /* 089d:3726 mov word ptr [0x3a], ax */
    TR(0x0c0f9); PUSH(0x372c); goto L0ae25; /* 089d:3729 call 0xae25 */
L0c0fc:
    TR(0x0c0fc); CYC(60); DI = POP(); /* 089d:372c pop di */
    TR(0x0c0fd); SI = POP(); /* 089d:372d pop si */
    TR(0x0c0fe); DX = POP(); /* 089d:372e pop dx */
    TR(0x0c0ff); CX = POP(); /* 089d:372f pop cx */
    TR(0x0c100); BX = POP(); /* 089d:3730 pop bx */
L0c101:
    TR(0x0c101); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3731 ret  */

/* ---- f_089d_3732 */
L0c102:
    TR(0x0c102); CYC(40); /* 089d:3732 cmp word ptr [0x56b2], 1 */
    TR(0x0c107); if (RW(DS_, 0x56b2) == 0x1) goto L0c10a; /* 089d:3737 je 0xc10a */
    TR(0x0c109); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3739 ret  */
L0c10a:
    TR(0x0c10a); CYC(30); CX = RW(DS_, 0x56b0); /* 089d:373a mov cx, word ptr [0x56b0] */
    TR(0x0c10e); BX = 0x0; /* 089d:373e mov bx, 0 */
L0c111:
    TR(0x0c111); CYC(40); /* 089d:3741 cmp word ptr [bx + 0x5520], 0 */
    TR(0x0c116); if (RW(DS_, (uint16_t)(BX + 0x5520)) == 0x0) goto L0c11b; /* 089d:3746 je 0xc11b */
    TR(0x0c118); CYC(23); PUSH(0x374b); goto L0c120; /* 089d:3748 call 0xc120 */
L0c11b:
    TR(0x0c11b); CYC(25); BX++; /* 089d:374b inc bx */
    TR(0x0c11c); BX++; /* 089d:374c inc bx */
    TR(0x0c11d); if (--CX) goto L0c111; /* 089d:374d loop 0xc111 */
    TR(0x0c11f); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:374f ret  */

/* ---- f_089d_3750 */
L0c120:
    TR(0x0c120); CYC(23); PUSH(0x3753); goto L0c0ae; /* 089d:3750 call 0xc0ae */
L0c123:
    TR(0x0c123); CYC(111); AX = RW(DS_, 0x4a); /* 089d:3753 mov ax, word ptr [0x4a] */
    TR(0x0c126); AX = (uint16_t)(0u - AX); /* 089d:3756 neg ax */
    TR(0x0c128); AX += RW(DS_, (uint16_t)(BX + 0x55e8)); /* 089d:3758 add ax, word ptr [bx + 0x55e8] */
    TR(0x0c12c); WW(DS_, (uint16_t)(BX + 0x5458), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x5458)) + AX)); /* 089d:375c add word ptr [bx + 0x5458], ax */
    TR(0x0c130); /* 089d:3760 cmp word ptr [bx + 0x5458], 0 */
    TR(0x0c135); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x5458)) >= (int16_t)0x0) goto L0c13d; /* 089d:3765 jge 0xc13d */
    TR(0x0c137); CYC(24); WW(DS_, (uint16_t)(BX + 0x5458), 0x18ec); /* 089d:3767 mov word ptr [bx + 0x5458], 0x18ec */
L0c13d:
    TR(0x0c13d); CYC(86); AX = RW(DS_, (uint16_t)(BX + 0x5584)); /* 089d:376d mov ax, word ptr [bx + 0x5584] */
    TR(0x0c141); WW(DS_, (uint16_t)(BX + 0x564c), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x564c)) + AX)); /* 089d:3771 add word ptr [bx + 0x564c], ax */
    TR(0x0c145); /* 089d:3775 cmp word ptr [bx + 0x564c], 0xa2 */
    TR(0x0c14b); if (RW(DS_, (uint16_t)(BX + 0x564c)) < 0xa2) goto L0c162; /* 089d:377b jb 0xc162 */
L0c14d:
    TR(0x0c14d); CYC(23); PUSH(0x3780); goto L0b412; /* 089d:377d call 0xb412 */
L0c150:
    TR(0x0c150); CYC(20); /* 089d:3780 cmp al, 0xf */
    TR(0x0c152); if (AL >= 0xf) goto L0c14d; /* 089d:3782 jae 0xc14d */
    TR(0x0c154); CYC(58); AH = 0x0; /* 089d:3784 mov ah, 0 */
    TR(0x0c156); AX = (uint16_t)(0u - AX); /* 089d:3786 neg ax */
    TR(0x0c158); WW(DS_, (uint16_t)(BX + 0x5584), AX); /* 089d:3788 mov word ptr [bx + 0x5584], ax */
    TR(0x0c15c); WW(DS_, (uint16_t)(BX + 0x564c), 0xa2); /* 089d:378c mov word ptr [bx + 0x564c], 0xa2 */
L0c162:
    TR(0x0c162); CYC(94); WW(DS_, (uint16_t)(BX + 0x5584), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x5584)) + 1)); /* 089d:3792 inc word ptr [bx + 0x5584] */
    TR(0x0c166); WW(DS_, (uint16_t)(BX + 0x54bc), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x54bc)) - 1)); /* 089d:3796 dec word ptr [bx + 0x54bc] */
    TR(0x0c16a); /* 089d:379a cmp word ptr [bx + 0x54bc], -1 */
    TR(0x0c16f); if (RW(DS_, (uint16_t)(BX + 0x54bc)) != 0xffff) goto L0c177; /* 089d:379f jne 0xc177 */
    TR(0x0c171); CYC(24); WW(DS_, (uint16_t)(BX + 0x54bc), 0x11); /* 089d:37a1 mov word ptr [bx + 0x54bc], 0x11 */
L0c177:
    TR(0x0c177); CYC(23); PUSH(0x37aa); goto L0c0ae; /* 089d:37a7 call 0xc0ae */
L0c17a:
    TR(0x0c17a); CYC(45); PUSH(CX); /* 089d:37aa push cx */
    TR(0x0c17b); CX = RW(DS_, 0x5062); /* 089d:37ab mov cx, word ptr [0x5062] */
    TR(0x0c17f); SI = 0x0; /* 089d:37af mov si, 0 */
L0c182:
    TR(0x0c182); CYC(40); /* 089d:37b2 cmp word ptr [si + 0x501e], 0 */
    TR(0x0c187); if (RW(DS_, (uint16_t)(SI + 0x501e)) == 0x0) goto L0c1fd; /* 089d:37b7 je 0xc1fd */
    TR(0x0c189); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x5458)); /* 089d:37b9 mov ax, word ptr [bx + 0x5458] */
    TR(0x0c18d); /* 089d:37bd cmp word ptr [si + 0x4ff6], ax */
    TR(0x0c191); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x4ff6)) < (int16_t)AX) goto L0c1fd; /* 089d:37c1 jl 0xc1fd */
    TR(0x0c193); CYC(52); AX += 0x14; /* 089d:37c3 add ax, 0x14 */
    TR(0x0c196); /* 089d:37c6 cmp word ptr [si + 0x4ff6], ax */
    TR(0x0c19a); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x4ff6)) > (int16_t)AX) goto L0c1fd; /* 089d:37ca jg 0xc1fd */
    TR(0x0c19c); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x564c)); /* 089d:37cc mov ax, word ptr [bx + 0x564c] */
    TR(0x0c1a0); /* 089d:37d0 cmp word ptr [si + 0x500a], ax */
    TR(0x0c1a4); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) < (int16_t)AX) goto L0c1fd; /* 089d:37d4 jl 0xc1fd */
    TR(0x0c1a6); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x564c)); /* 089d:37d6 mov ax, word ptr [bx + 0x564c] */
    TR(0x0c1aa); /* 089d:37da cmp word ptr [si + 0x500a], ax */
    TR(0x0c1ae); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) < (int16_t)AX) goto L0c1fd; /* 089d:37de jl 0xc1fd */
    TR(0x0c1b0); CYC(52); AX += 0x12; /* 089d:37e0 add ax, 0x12 */
    TR(0x0c1b3); /* 089d:37e3 cmp word ptr [si + 0x500a], ax */
    TR(0x0c1b7); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) > (int16_t)AX) goto L0c1fd; /* 089d:37e7 jg 0xc1fd */
    TR(0x0c1b9); CYC(136); WW(DS_, 0x50d6, 0x1); /* 089d:37e9 mov word ptr [0x50d6], 1 */
    TR(0x0c1bf); AX = RW(DS_, (uint16_t)(BX + 0x5458)); /* 089d:37ef mov ax, word ptr [bx + 0x5458] */
    TR(0x0c1c3); WW(DS_, 0x50d8, AX); /* 089d:37f3 mov word ptr [0x50d8], ax */
    TR(0x0c1c6); AX = RW(DS_, (uint16_t)(BX + 0x564c)); /* 089d:37f6 mov ax, word ptr [bx + 0x564c] */
    TR(0x0c1ca); WW(DS_, 0x50da, AX); /* 089d:37fa mov word ptr [0x50da], ax */
    TR(0x0c1cd); /* 089d:37fd cmp word ptr [si + 0x501e], 1 */
    TR(0x0c1d2); if (RW(DS_, (uint16_t)(SI + 0x501e)) != 0x1) goto L0c1de; /* 089d:3802 jne 0xc1de */
    TR(0x0c1d4); CYC(46); PUSH(BX); /* 089d:3804 push bx */
    TR(0x0c1d5); BX = SI; /* 089d:3805 mov bx, si */
    TR(0x0c1d7); PUSH(0x380a); goto L0b66e; /* 089d:3807 call 0xb66e */
L0c1da:
    TR(0x0c1da); CYC(27); BX = POP(); /* 089d:380a pop bx */
    TR(0x0c1db); goto L0c1e5; /* 089d:380b jmp 0xc1e5 */
L0c1de:
    TR(0x0c1de); CYC(46); PUSH(BX); /* 089d:380e push bx */
    TR(0x0c1df); BX = SI; /* 089d:380f mov bx, si */
    TR(0x0c1e1); PUSH(0x3814); goto L0c6c3; /* 089d:3811 call 0xc6c3 */
L0c1e4:
    TR(0x0c1e4); CYC(12); BX = POP(); /* 089d:3814 pop bx */
L0c1e5:
    TR(0x0c1e5); CYC(71); WW(DS_, (uint16_t)(SI + 0x501e), 0x0); /* 089d:3815 mov word ptr [si + 0x501e], 0 */
    TR(0x0c1eb); WW(DS_, (uint16_t)(BX + 0x5520), 0x0); /* 089d:381b mov word ptr [bx + 0x5520], 0 */
    TR(0x0c1f1); PUSH(0x3824); goto L0c0ae; /* 089d:3821 call 0xc0ae */
L0c1f4:
    TR(0x0c1f4); CYC(35); AX = 0x14; /* 089d:3824 mov ax, 0x14 */
    TR(0x0c1f7); PUSH(0x382a); goto L0b829; /* 089d:3827 call 0xb829 */
L0c1fa:
    TR(0x0c1fa); CYC(15); goto L0c201; /* 089d:382a jmp 0xc201 */
L0c1fd:
    TR(0x0c1fd); CYC(25); SI++; /* 089d:382d inc si */
    TR(0x0c1fe); SI++; /* 089d:382e inc si */
    TR(0x0c1ff); if (--CX) goto L0c182; /* 089d:382f loop 0xc182 */
L0c201:
    TR(0x0c201); CYC(52); CX = POP(); /* 089d:3831 pop cx */
    TR(0x0c202); /* 089d:3832 cmp word ptr [0x4176], 1 */
    TR(0x0c207); if (RW(DS_, 0x4176) != 0x1) goto L0c263; /* 089d:3837 jne 0xc263 */
    TR(0x0c209); CYC(40); /* 089d:3839 cmp word ptr [bx + 0x5520], 1 */
    TR(0x0c20e); if (RW(DS_, (uint16_t)(BX + 0x5520)) != 0x1) goto L0c263; /* 089d:383e jne 0xc263 */
    TR(0x0c210); CYC(68); AX = RW(DS_, 0x4170); /* 089d:3840 mov ax, word ptr [0x4170] */
    TR(0x0c213); DX = RW(DS_, (uint16_t)(BX + 0x5458)); /* 089d:3843 mov dx, word ptr [bx + 0x5458] */
    TR(0x0c217); AX += 0x14; /* 089d:3847 add ax, 0x14 */
    TR(0x0c21a); /* 089d:384a cmp ax, dx */
    TR(0x0c21c); if ((int16_t)AX < (int16_t)DX) goto L0c263; /* 089d:384c jl 0xc263 */
    TR(0x0c21e); CYC(44); AX -= 0x14; /* 089d:384e sub ax, 0x14 */
    TR(0x0c221); DX += 0x14; /* 089d:3851 add dx, 0x14 */
    TR(0x0c224); /* 089d:3854 cmp ax, dx */
    TR(0x0c226); if ((int16_t)AX > (int16_t)DX) goto L0c263; /* 089d:3856 jg 0xc263 */
    TR(0x0c228); CYC(68); AX = RW(DS_, 0x4172); /* 089d:3858 mov ax, word ptr [0x4172] */
    TR(0x0c22b); DX = RW(DS_, (uint16_t)(BX + 0x564c)); /* 089d:385b mov dx, word ptr [bx + 0x564c] */
    TR(0x0c22f); AX += 0xe; /* 089d:385f add ax, 0xe */
    TR(0x0c232); /* 089d:3862 cmp ax, dx */
    TR(0x0c234); if ((int16_t)AX < (int16_t)DX) goto L0c263; /* 089d:3864 jl 0xc263 */
    TR(0x0c236); CYC(44); AX -= 0xe; /* 089d:3866 sub ax, 0xe */
    TR(0x0c239); DX += 0x12; /* 089d:3869 add dx, 0x12 */
    TR(0x0c23c); /* 089d:386c cmp ax, dx */
    TR(0x0c23e); if ((int16_t)AX > (int16_t)DX) goto L0c263; /* 089d:386e jg 0xc263 */
    TR(0x0c240); CYC(167); WW(DS_, 0x5360, 0x1); /* 089d:3870 mov word ptr [0x5360], 1 */
    TR(0x0c246); WW(DS_, 0x50d6, 0x1); /* 089d:3876 mov word ptr [0x50d6], 1 */
    TR(0x0c24c); AX = RW(DS_, (uint16_t)(BX + 0x5458)); /* 089d:387c mov ax, word ptr [bx + 0x5458] */
    TR(0x0c250); WW(DS_, 0x50d8, AX); /* 089d:3880 mov word ptr [0x50d8], ax */
    TR(0x0c253); AX = RW(DS_, (uint16_t)(BX + 0x564c)); /* 089d:3883 mov ax, word ptr [bx + 0x564c] */
    TR(0x0c257); WW(DS_, 0x50da, AX); /* 089d:3887 mov word ptr [0x50da], ax */
    TR(0x0c25a); WW(DS_, (uint16_t)(BX + 0x5520), 0x0); /* 089d:388a mov word ptr [bx + 0x5520], 0 */
    TR(0x0c260); PUSH(0x3893); goto L0c0ae; /* 089d:3890 call 0xc0ae */
L0c263:
    TR(0x0c263); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3893 ret  */

/* ---- f_089d_3894 */
L0c264:
    TR(0x0c264); CYC(23); PUSH(0x3897); goto L0c281; /* 089d:3894 call 0xc281 */
L0c267:
    TR(0x0c267); CYC(94); AX = RW(DS_, 0x4a); /* 089d:3897 mov ax, word ptr [0x4a] */
    TR(0x0c26a); AX = (uint16_t)(0u - AX); /* 089d:389a neg ax */
    TR(0x0c26c); WW(DS_, 0x56b4, (uint16_t)(RW(DS_, 0x56b4) + AX)); /* 089d:389c add word ptr [0x56b4], ax */
    TR(0x0c270); /* 089d:38a0 cmp word ptr [0x56b4], 0 */
    TR(0x0c275); if ((int16_t)RW(DS_, 0x56b4) > (int16_t)0x0) goto L0c27d; /* 089d:38a5 jg 0xc27d */
    TR(0x0c277); CYC(24); WW(DS_, 0x56b4, 0x18d8); /* 089d:38a7 mov word ptr [0x56b4], 0x18d8 */
L0c27d:
    TR(0x0c27d); CYC(23); PUSH(0x38b0); goto L0c281; /* 089d:38ad call 0xc281 */
L0c280:
    TR(0x0c280); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:38b0 ret  */

/* ---- f_089d_38b1 */
L0c281:
    TR(0x0c281); CYC(40); /* 089d:38b1 cmp word ptr [0x56b4], 0x10f */
    TR(0x0c287); if ((int16_t)RW(DS_, 0x56b4) > (int16_t)0x10f) goto L0c2ce; /* 089d:38b7 jg 0xc2ce */
    TR(0x0c289); CYC(40); /* 089d:38b9 cmp word ptr [0x56b4], 0 */
    TR(0x0c28e); if ((int16_t)RW(DS_, 0x56b4) < (int16_t)0x0) goto L0c2ce; /* 089d:38be jl 0xc2ce */
    TR(0x0c290); CYC(334); PUSH(BX); /* 089d:38c0 push bx */
    TR(0x0c291); PUSH(CX); /* 089d:38c1 push cx */
    TR(0x0c292); PUSH(DX); /* 089d:38c2 push dx */
    TR(0x0c293); PUSH(SI); /* 089d:38c3 push si */
    TR(0x0c294); PUSH(DI); /* 089d:38c4 push di */
    TR(0x0c295); AX = 0x0; /* 089d:38c5 mov ax, 0 */
    TR(0x0c298); AX += AX; /* 089d:38c8 add ax, ax */
    TR(0x0c29a); DI = AX; /* 089d:38ca mov di, ax */
    TR(0x0c29c); SI = RW(DS_, (uint16_t)(DI + 0x7ab0)); /* 089d:38cc mov si, word ptr [di + 0x7ab0] */
    TR(0x0c2a0); DL = RB(DS_, SI); /* 089d:38d0 mov dl, byte ptr [si] */
    TR(0x0c2a2); DH = DL; /* 089d:38d2 mov dh, dl */
    TR(0x0c2a4); SI++; /* 089d:38d4 inc si */
    TR(0x0c2a5); CH = RB(DS_, SI); /* 089d:38d5 mov ch, byte ptr [si] */
    TR(0x0c2a7); SI++; /* 089d:38d7 inc si */
    TR(0x0c2a8); WW(DS_, 0x36, SI); /* 089d:38d8 mov word ptr [0x36], si */
    TR(0x0c2ac); AX = 0x19; /* 089d:38dc mov ax, 0x19 */
    TR(0x0c2af); WW(DS_, 0x2e, AX); /* 089d:38df mov word ptr [0x2e], ax */
    TR(0x0c2b2); BX = RW(DS_, 0x56b4); /* 089d:38e2 mov bx, word ptr [0x56b4] */
    TR(0x0c2b6); AX = RW(DS_, (uint16_t)(BX + 0x680e)); /* 089d:38e6 mov ax, word ptr [bx + 0x680e] */
    TR(0x0c2ba); AH = 0x0; /* 089d:38ea mov ah, 0 */
    TR(0x0c2bc); WW(DS_, 0x2c, AX); /* 089d:38ec mov word ptr [0x2c], ax */
    TR(0x0c2bf); AX = RW(DS_, (uint16_t)(BX + 0x695c)); /* 089d:38ef mov ax, word ptr [bx + 0x695c] */
    TR(0x0c2c3); WW(DS_, 0x3a, AX); /* 089d:38f3 mov word ptr [0x3a], ax */
    TR(0x0c2c6); PUSH(0x38f9); goto L0ae25; /* 089d:38f6 call 0xae25 */
L0c2c9:
    TR(0x0c2c9); CYC(60); DI = POP(); /* 089d:38f9 pop di */
    TR(0x0c2ca); SI = POP(); /* 089d:38fa pop si */
    TR(0x0c2cb); DX = POP(); /* 089d:38fb pop dx */
    TR(0x0c2cc); CX = POP(); /* 089d:38fc pop cx */
    TR(0x0c2cd); BX = POP(); /* 089d:38fd pop bx */
L0c2ce:
    TR(0x0c2ce); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:38fe ret  */

/* ---- f_089d_38ff */
L0c2cf:
    TR(0x0c2cf); CYC(40); /* 089d:38ff cmp word ptr [bx + 0x56b6], 0x123 */
    TR(0x0c2d5); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x56b6)) > (int16_t)0x123) goto L0c322; /* 089d:3905 jg 0xc322 */
    TR(0x0c2d7); CYC(40); /* 089d:3907 cmp word ptr [bx + 0x56b6], 0 */
    TR(0x0c2dc); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x56b6)) < (int16_t)0x0) goto L0c322; /* 089d:390c jl 0xc322 */
    TR(0x0c2de); CYC(362); AX = RW(DS_, (uint16_t)(BX + 0x571a)); /* 089d:390e mov ax, word ptr [bx + 0x571a] */
    TR(0x0c2e2); AX >>= 1; /* 089d:3912 shr ax, 1 */
    TR(0x0c2e4); PUSH(BX); /* 089d:3914 push bx */
    TR(0x0c2e5); PUSH(CX); /* 089d:3915 push cx */
    TR(0x0c2e6); PUSH(DX); /* 089d:3916 push dx */
    TR(0x0c2e7); PUSH(SI); /* 089d:3917 push si */
    TR(0x0c2e8); PUSH(DI); /* 089d:3918 push di */
    TR(0x0c2e9); AX = AX; /* 089d:3919 mov ax, ax */
    TR(0x0c2eb); AX += AX; /* 089d:391b add ax, ax */
    TR(0x0c2ed); DI = AX; /* 089d:391d mov di, ax */
    TR(0x0c2ef); SI = RW(DS_, (uint16_t)(DI + 0x72bb)); /* 089d:391f mov si, word ptr [di + 0x72bb] */
    TR(0x0c2f3); DL = RB(DS_, SI); /* 089d:3923 mov dl, byte ptr [si] */
    TR(0x0c2f5); DH = DL; /* 089d:3925 mov dh, dl */
    TR(0x0c2f7); SI++; /* 089d:3927 inc si */
    TR(0x0c2f8); CH = RB(DS_, SI); /* 089d:3928 mov ch, byte ptr [si] */
    TR(0x0c2fa); SI++; /* 089d:392a inc si */
    TR(0x0c2fb); WW(DS_, 0x36, SI); /* 089d:392b mov word ptr [0x36], si */
    TR(0x0c2ff); AX = RW(DS_, (uint16_t)(BX + 0x58aa)); /* 089d:392f mov ax, word ptr [bx + 0x58aa] */
    TR(0x0c303); WW(DS_, 0x2e, AX); /* 089d:3933 mov word ptr [0x2e], ax */
    TR(0x0c306); BX = RW(DS_, (uint16_t)(BX + 0x56b6)); /* 089d:3936 mov bx, word ptr [bx + 0x56b6] */
    TR(0x0c30a); AX = RW(DS_, (uint16_t)(BX + 0x680e)); /* 089d:393a mov ax, word ptr [bx + 0x680e] */
    TR(0x0c30e); AH = 0x0; /* 089d:393e mov ah, 0 */
    TR(0x0c310); WW(DS_, 0x2c, AX); /* 089d:3940 mov word ptr [0x2c], ax */
    TR(0x0c313); AX = RW(DS_, (uint16_t)(BX + 0x695c)); /* 089d:3943 mov ax, word ptr [bx + 0x695c] */
    TR(0x0c317); WW(DS_, 0x3a, AX); /* 089d:3947 mov word ptr [0x3a], ax */
    TR(0x0c31a); PUSH(0x394d); goto L0ae25; /* 089d:394a call 0xae25 */
L0c31d:
    TR(0x0c31d); CYC(60); DI = POP(); /* 089d:394d pop di */
    TR(0x0c31e); SI = POP(); /* 089d:394e pop si */
    TR(0x0c31f); DX = POP(); /* 089d:394f pop dx */
    TR(0x0c320); CX = POP(); /* 089d:3950 pop cx */
    TR(0x0c321); BX = POP(); /* 089d:3951 pop bx */
L0c322:
    TR(0x0c322); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3952 ret  */

/* ---- f_089d_3953 */
L0c323:
    TR(0x0c323); CYC(40); /* 089d:3953 cmp word ptr [0x59d8], 1 */
    TR(0x0c328); if (RW(DS_, 0x59d8) == 0x1) goto L0c32b; /* 089d:3958 je 0xc32b */
    TR(0x0c32a); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:395a ret  */
L0c32b:
    TR(0x0c32b); CYC(30); CX = RW(DS_, 0x59d6); /* 089d:395b mov cx, word ptr [0x59d6] */
    TR(0x0c32f); BX = 0x0; /* 089d:395f mov bx, 0 */
L0c332:
    TR(0x0c332); CYC(40); /* 089d:3962 cmp word ptr [bx + 0x577e], 0 */
    TR(0x0c337); if (RW(DS_, (uint16_t)(BX + 0x577e)) == 0x0) goto L0c33c; /* 089d:3967 je 0xc33c */
    TR(0x0c339); CYC(23); PUSH(0x396c); goto L0c341; /* 089d:3969 call 0xc341 */
L0c33c:
    TR(0x0c33c); CYC(25); BX++; /* 089d:396c inc bx */
    TR(0x0c33d); BX++; /* 089d:396d inc bx */
    TR(0x0c33e); if (--CX) goto L0c332; /* 089d:396e loop 0xc332 */
    TR(0x0c340); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3970 ret  */

/* ---- f_089d_3971 */
L0c341:
    TR(0x0c341); CYC(23); PUSH(0x3974); goto L0c2cf; /* 089d:3971 call 0xc2cf */
L0c344:
    TR(0x0c344); CYC(111); AX = RW(DS_, 0x4a); /* 089d:3974 mov ax, word ptr [0x4a] */
    TR(0x0c347); AX = (uint16_t)(0u - AX); /* 089d:3977 neg ax */
    TR(0x0c349); AX += RW(DS_, (uint16_t)(BX + 0x5846)); /* 089d:3979 add ax, word ptr [bx + 0x5846] */
    TR(0x0c34d); WW(DS_, (uint16_t)(BX + 0x56b6), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x56b6)) + AX)); /* 089d:397d add word ptr [bx + 0x56b6], ax */
    TR(0x0c351); /* 089d:3981 cmp word ptr [bx + 0x56b6], 0 */
    TR(0x0c356); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x56b6)) >= (int16_t)0x0) goto L0c35e; /* 089d:3986 jge 0xc35e */
    TR(0x0c358); CYC(24); WW(DS_, (uint16_t)(BX + 0x56b6), 0x18ec); /* 089d:3988 mov word ptr [bx + 0x56b6], 0x18ec */
L0c35e:
    TR(0x0c35e); CYC(40); /* 089d:398e cmp word ptr [bx + 0x56b6], 0x18ec */
    TR(0x0c364); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x56b6)) <= (int16_t)0x18ec) goto L0c36c; /* 089d:3994 jle 0xc36c */
    TR(0x0c366); CYC(24); WW(DS_, (uint16_t)(BX + 0x56b6), 0x0); /* 089d:3996 mov word ptr [bx + 0x56b6], 0 */
L0c36c:
    TR(0x0c36c); CYC(40); /* 089d:399c cmp word ptr [bx + 0x56b6], 0 */
    TR(0x0c371); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x56b6)) < (int16_t)0x0) goto L0c3ad; /* 089d:39a1 jl 0xc3ad */
    TR(0x0c373); CYC(40); /* 089d:39a3 cmp word ptr [bx + 0x56b6], 0x123 */
    TR(0x0c379); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x56b6)) > (int16_t)0x123) goto L0c3ad; /* 089d:39a9 jg 0xc3ad */
    TR(0x0c37b); CYC(67); WW(DS_, (uint16_t)(BX + 0x5972), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x5972)) - 1)); /* 089d:39ab dec word ptr [bx + 0x5972] */
    TR(0x0c37f); /* 089d:39af cmp word ptr [bx + 0x5972], 0 */
    TR(0x0c384); if (RW(DS_, (uint16_t)(BX + 0x5972)) != 0x0) goto L0c3ad; /* 089d:39b4 jne 0xc3ad */
    TR(0x0c386); CYC(180); WW(DS_, (uint16_t)(BX + 0x5972), 0x14); /* 089d:39b6 mov word ptr [bx + 0x5972], 0x14 */
    TR(0x0c38c); AX = RW(DS_, (uint16_t)(BX + 0x56b6)); /* 089d:39bc mov ax, word ptr [bx + 0x56b6] */
    TR(0x0c390); AX += 0xe; /* 089d:39c0 add ax, 0xe */
    TR(0x0c393); WW(DS_, 0x5a76, AX); /* 089d:39c3 mov word ptr [0x5a76], ax */
    TR(0x0c396); AX = RW(DS_, (uint16_t)(BX + 0x58aa)); /* 089d:39c6 mov ax, word ptr [bx + 0x58aa] */
    TR(0x0c39a); AX += 0x7; /* 089d:39ca add ax, 7 */
    TR(0x0c39d); WW(DS_, 0x5a78, AX); /* 089d:39cd mov word ptr [0x5a78], ax */
    TR(0x0c3a0); AX = RW(DS_, (uint16_t)(BX + 0x5846)); /* 089d:39d0 mov ax, word ptr [bx + 0x5846] */
    TR(0x0c3a4); WW(DS_, 0x5a7c, AX); /* 089d:39d4 mov word ptr [0x5a7c], ax */
    TR(0x0c3a7); WW(DS_, 0x5a74, 0x1); /* 089d:39d7 mov word ptr [0x5a74], 1 */
L0c3ad:
    TR(0x0c3ad); CYC(86); AX = RW(DS_, (uint16_t)(BX + 0x590e)); /* 089d:39dd mov ax, word ptr [bx + 0x590e] */
    TR(0x0c3b1); WW(DS_, (uint16_t)(BX + 0x571a), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x571a)) + AX)); /* 089d:39e1 add word ptr [bx + 0x571a], ax */
    TR(0x0c3b5); /* 089d:39e5 cmp word ptr [bx + 0x571a], 0 */
    TR(0x0c3ba); if (RW(DS_, (uint16_t)(BX + 0x571a)) != 0x0) goto L0c3c2; /* 089d:39ea jne 0xc3c2 */
    TR(0x0c3bc); CYC(24); WW(DS_, (uint16_t)(BX + 0x590e), 0x1); /* 089d:39ec mov word ptr [bx + 0x590e], 1 */
L0c3c2:
    TR(0x0c3c2); CYC(40); /* 089d:39f2 cmp word ptr [bx + 0x571a], 0x19 */
    TR(0x0c3c7); if (RW(DS_, (uint16_t)(BX + 0x571a)) != 0x19) goto L0c3cf; /* 089d:39f7 jne 0xc3cf */
    TR(0x0c3c9); CYC(24); WW(DS_, (uint16_t)(BX + 0x590e), 0xffff); /* 089d:39f9 mov word ptr [bx + 0x590e], 0xffff */
L0c3cf:
    TR(0x0c3cf); CYC(23); PUSH(0x3a02); goto L0c2cf; /* 089d:39ff call 0xc2cf */
L0c3d2:
    TR(0x0c3d2); CYC(45); PUSH(CX); /* 089d:3a02 push cx */
    TR(0x0c3d3); CX = RW(DS_, 0x5062); /* 089d:3a03 mov cx, word ptr [0x5062] */
    TR(0x0c3d7); SI = 0x0; /* 089d:3a07 mov si, 0 */
L0c3da:
    TR(0x0c3da); CYC(40); /* 089d:3a0a cmp word ptr [si + 0x501e], 0 */
    TR(0x0c3df); if (RW(DS_, (uint16_t)(SI + 0x501e)) == 0x0) goto L0c441; /* 089d:3a0f je 0xc441 */
    TR(0x0c3e1); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x56b6)); /* 089d:3a11 mov ax, word ptr [bx + 0x56b6] */
    TR(0x0c3e5); /* 089d:3a15 cmp word ptr [si + 0x4ff6], ax */
    TR(0x0c3e9); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x4ff6)) < (int16_t)AX) goto L0c441; /* 089d:3a19 jl 0xc441 */
    TR(0x0c3eb); CYC(52); AX += 0x1c; /* 089d:3a1b add ax, 0x1c */
    TR(0x0c3ee); /* 089d:3a1e cmp word ptr [si + 0x4ff6], ax */
    TR(0x0c3f2); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x4ff6)) > (int16_t)AX) goto L0c441; /* 089d:3a22 jg 0xc441 */
    TR(0x0c3f4); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x58aa)); /* 089d:3a24 mov ax, word ptr [bx + 0x58aa] */
    TR(0x0c3f8); /* 089d:3a28 cmp word ptr [si + 0x500a], ax */
    TR(0x0c3fc); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) < (int16_t)AX) goto L0c441; /* 089d:3a2c jl 0xc441 */
    TR(0x0c3fe); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x58aa)); /* 089d:3a2e mov ax, word ptr [bx + 0x58aa] */
    TR(0x0c402); /* 089d:3a32 cmp word ptr [si + 0x500a], ax */
    TR(0x0c406); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) < (int16_t)AX) goto L0c441; /* 089d:3a36 jl 0xc441 */
    TR(0x0c408); CYC(52); AX += 0x9; /* 089d:3a38 add ax, 9 */
    TR(0x0c40b); /* 089d:3a3b cmp word ptr [si + 0x500a], ax */
    TR(0x0c40f); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) > (int16_t)AX) goto L0c441; /* 089d:3a3f jg 0xc441 */
    TR(0x0c411); CYC(166); WW(DS_, 0x50d6, 0x1); /* 089d:3a41 mov word ptr [0x50d6], 1 */
    TR(0x0c417); AX = RW(DS_, (uint16_t)(BX + 0x56b6)); /* 089d:3a47 mov ax, word ptr [bx + 0x56b6] */
    TR(0x0c41b); WW(DS_, 0x50d8, AX); /* 089d:3a4b mov word ptr [0x50d8], ax */
    TR(0x0c41e); AX = RW(DS_, (uint16_t)(BX + 0x58aa)); /* 089d:3a4e mov ax, word ptr [bx + 0x58aa] */
    TR(0x0c422); WW(DS_, 0x50da, AX); /* 089d:3a52 mov word ptr [0x50da], ax */
    TR(0x0c425); WW(DS_, (uint16_t)(SI + 0x501e), 0x0); /* 089d:3a55 mov word ptr [si + 0x501e], 0 */
    TR(0x0c42b); PUSH(BX); /* 089d:3a5b push bx */
    TR(0x0c42c); BX = SI; /* 089d:3a5c mov bx, si */
    TR(0x0c42e); PUSH(0x3a61); goto L0c6c3; /* 089d:3a5e call 0xc6c3 */
L0c431:
    TR(0x0c431); CYC(59); BX = POP(); /* 089d:3a61 pop bx */
    TR(0x0c432); WW(DS_, (uint16_t)(BX + 0x577e), 0x0); /* 089d:3a62 mov word ptr [bx + 0x577e], 0 */
    TR(0x0c438); PUSH(0x3a6b); goto L0c2cf; /* 089d:3a68 call 0xc2cf */
L0c43b:
    TR(0x0c43b); CYC(23); PUSH(0x3a6e); goto L0c447; /* 089d:3a6b call 0xc447 */
L0c43e:
    TR(0x0c43e); CYC(15); goto L0c445; /* 089d:3a6e jmp 0xc445 */
L0c441:
    TR(0x0c441); CYC(25); SI++; /* 089d:3a71 inc si */
    TR(0x0c442); SI++; /* 089d:3a72 inc si */
    TR(0x0c443); if (--CX) goto L0c3da; /* 089d:3a73 loop 0xc3da */
L0c445:
    TR(0x0c445); CYC(32); CX = POP(); /* 089d:3a75 pop cx */
    TR(0x0c446); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3a76 ret  */

/* ---- f_089d_3a77 */
L0c447:
    TR(0x0c447); CYC(220); WW(DS_, 0x5160, 0x1); /* 089d:3a77 mov word ptr [0x5160], 1 */
    TR(0x0c44d); AX = RW(DS_, (uint16_t)(BX + 0x56b6)); /* 089d:3a7d mov ax, word ptr [bx + 0x56b6] */
    TR(0x0c451); WW(DS_, 0x5162, AX); /* 089d:3a81 mov word ptr [0x5162], ax */
    TR(0x0c454); AX = RW(DS_, (uint16_t)(BX + 0x58aa)); /* 089d:3a84 mov ax, word ptr [bx + 0x58aa] */
    TR(0x0c458); AX -= 0x5; /* 089d:3a88 sub ax, 5 */
    TR(0x0c45b); WW(DS_, 0x5164, AX); /* 089d:3a8b mov word ptr [0x5164], ax */
    TR(0x0c45e); WW(DS_, 0x5166, 0x0); /* 089d:3a8e mov word ptr [0x5166], 0 */
    TR(0x0c464); AX = RW(DS_, 0x4a); /* 089d:3a94 mov ax, word ptr [0x4a] */
    TR(0x0c467); WW(DS_, 0x516a, AX); /* 089d:3a97 mov word ptr [0x516a], ax */
    TR(0x0c46a); AX = 0x19; /* 089d:3a9a mov ax, 0x19 */
    TR(0x0c46d); /* 089d:3a9d cmp word ptr [bx + 0x58aa], 0x4b */
    TR(0x0c472); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x58aa)) > (int16_t)0x4b) goto L0c47d; /* 089d:3aa2 jg 0xc47d */
    TR(0x0c474); CYC(36); AX = 0x32; /* 089d:3aa4 mov ax, 0x32 */
    TR(0x0c477); WW(DS_, 0x5166, 0x1); /* 089d:3aa7 mov word ptr [0x5166], 1 */
L0c47d:
    TR(0x0c47d); CYC(23); PUSH(0x3ab0); goto L0b829; /* 089d:3aad call 0xb829 */
L0c480:
    TR(0x0c480); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3ab0 ret  */

/* ---- f_089d_3ab1 */
L0c481:
    TR(0x0c481); CYC(30); CX = RW(DS_, 0x5a7e); /* 089d:3ab1 mov cx, word ptr [0x5a7e] */
    TR(0x0c485); BX = 0x0; /* 089d:3ab5 mov bx, 0 */
L0c488:
    TR(0x0c488); CYC(40); /* 089d:3ab8 cmp word ptr [bx + 0x5a06], 0 */
    TR(0x0c48d); if (RW(DS_, (uint16_t)(BX + 0x5a06)) == 0x0) goto L0c495; /* 089d:3abd je 0xc495 */
    TR(0x0c48f); CYC(23); PUSH(0x3ac2); goto L0c4f0; /* 089d:3abf call 0xc4f0 */
L0c492:
    TR(0x0c492); CYC(15); goto L0c4e5; /* 089d:3ac2 jmp 0xc4e5 */
L0c495:
    TR(0x0c495); CYC(40); /* 089d:3ac5 cmp word ptr [0x5a74], 0 */
    TR(0x0c49a); if (RW(DS_, 0x5a74) == 0x0) goto L0c4e5; /* 089d:3aca je 0xc4e5 */
    TR(0x0c49c); CYC(268); WW(DS_, 0x5a74, 0x0); /* 089d:3acc mov word ptr [0x5a74], 0 */
    TR(0x0c4a2); WW(DS_, (uint16_t)(BX + 0x5a06), 0x1); /* 089d:3ad2 mov word ptr [bx + 0x5a06], 1 */
    TR(0x0c4a8); AX = RW(DS_, 0x5a76); /* 089d:3ad8 mov ax, word ptr [0x5a76] */
    TR(0x0c4ab); WW(DS_, (uint16_t)(BX + 0x59da), AX); /* 089d:3adb mov word ptr [bx + 0x59da], ax */
    TR(0x0c4af); AX = RW(DS_, 0x5a78); /* 089d:3adf mov ax, word ptr [0x5a78] */
    TR(0x0c4b2); WW(DS_, (uint16_t)(BX + 0x59f0), AX); /* 089d:3ae2 mov word ptr [bx + 0x59f0], ax */
    TR(0x0c4b6); WW(DS_, (uint16_t)(BX + 0x5a32), 0x0); /* 089d:3ae6 mov word ptr [bx + 0x5a32], 0 */
    TR(0x0c4bc); AX = RW(DS_, 0x5a7c); /* 089d:3aec mov ax, word ptr [0x5a7c] */
    TR(0x0c4bf); WW(DS_, (uint16_t)(BX + 0x5a1c), AX); /* 089d:3aef mov word ptr [bx + 0x5a1c], ax */
    TR(0x0c4c3); WW(DS_, (uint16_t)(BX + 0x5a5e), 0x0); /* 089d:3af3 mov word ptr [bx + 0x5a5e], 0 */
    TR(0x0c4c9); WW(DS_, (uint16_t)(BX + 0x5a48), 0xffff); /* 089d:3af9 mov word ptr [bx + 0x5a48], 0xffff */
    TR(0x0c4cf); /* 089d:3aff cmp word ptr [0x5a7c], 0 */
    TR(0x0c4d4); if ((int16_t)RW(DS_, 0x5a7c) >= (int16_t)0x0) goto L0c4e2; /* 089d:3b04 jge 0xc4e2 */
    TR(0x0c4d6); CYC(48); WW(DS_, (uint16_t)(BX + 0x5a5e), 0x1); /* 089d:3b06 mov word ptr [bx + 0x5a5e], 1 */
    TR(0x0c4dc); WW(DS_, (uint16_t)(BX + 0x5a48), 0x1); /* 089d:3b0c mov word ptr [bx + 0x5a48], 1 */
L0c4e2:
    TR(0x0c4e2); CYC(23); PUSH(0x3b15); goto L0c5aa; /* 089d:3b12 call 0xc5aa */
L0c4e5:
    TR(0x0c4e5); CYC(25); BX++; /* 089d:3b15 inc bx */
    TR(0x0c4e6); BX++; /* 089d:3b16 inc bx */
    TR(0x0c4e7); if (--CX) goto L0c488; /* 089d:3b17 loop 0xc488 */
    TR(0x0c4e9); CYC(44); WW(DS_, 0x5a74, 0x0); /* 089d:3b19 mov word ptr [0x5a74], 0 */
    TR(0x0c4ef); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3b1f ret  */

/* ---- f_089d_3b20 */
L0c4f0:
    TR(0x0c4f0); CYC(23); PUSH(0x3b23); goto L0c5aa; /* 089d:3b20 call 0xc5aa */
L0c4f3:
    TR(0x0c4f3); CYC(165); AX = RW(DS_, 0x4a); /* 089d:3b23 mov ax, word ptr [0x4a] */
    TR(0x0c4f6); AX = (uint16_t)(0u - AX); /* 089d:3b26 neg ax */
    TR(0x0c4f8); AX += RW(DS_, (uint16_t)(BX + 0x5a1c)); /* 089d:3b28 add ax, word ptr [bx + 0x5a1c] */
    TR(0x0c4fc); WW(DS_, (uint16_t)(BX + 0x59da), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x59da)) + AX)); /* 089d:3b2c add word ptr [bx + 0x59da], ax */
    TR(0x0c500); AX = RW(DS_, (uint16_t)(BX + 0x5a32)); /* 089d:3b30 mov ax, word ptr [bx + 0x5a32] */
    TR(0x0c504); { uint16_t a_ = AX; unsigned n_ = 1 & 0x1f; AX = (uint16_t)((int16_t)a_ >> n_); } /* 089d:3b34 sar ax, 1 */
    TR(0x0c506); WW(DS_, (uint16_t)(BX + 0x59f0), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x59f0)) + AX)); /* 089d:3b36 add word ptr [bx + 0x59f0], ax */
    TR(0x0c50a); /* 089d:3b3a cmp word ptr [bx + 0x59f0], 0xb1 */
    TR(0x0c510); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x59f0)) < (int16_t)0xb1) goto L0c529; /* 089d:3b40 jl 0xc529 */
    TR(0x0c512); CYC(116); WW(DS_, (uint16_t)(BX + 0x5a06), 0x0); /* 089d:3b42 mov word ptr [bx + 0x5a06], 0 */
    TR(0x0c518); AX = RW(DS_, (uint16_t)(BX + 0x59da)); /* 089d:3b48 mov ax, word ptr [bx + 0x59da] */
    TR(0x0c51c); AX -= 0xa; /* 089d:3b4c sub ax, 0xa */
    TR(0x0c51f); WW(DS_, 0x5af0, AX); /* 089d:3b4f mov word ptr [0x5af0], ax */
    TR(0x0c522); WW(DS_, 0x5aee, 0x1); /* 089d:3b52 mov word ptr [0x5aee], 1 */
    TR(0x0c528); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3b58 ret  */
L0c529:
    TR(0x0c529); CYC(114); WW(DS_, (uint16_t)(BX + 0x5a32), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x5a32)) + 0x2)); /* 089d:3b59 add word ptr [bx + 0x5a32], 2 */
    TR(0x0c52e); AX = RW(DS_, (uint16_t)(BX + 0x5a48)); /* 089d:3b5e mov ax, word ptr [bx + 0x5a48] */
    TR(0x0c532); WW(DS_, (uint16_t)(BX + 0x5a1c), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x5a1c)) + AX)); /* 089d:3b62 add word ptr [bx + 0x5a1c], ax */
    TR(0x0c536); /* 089d:3b66 cmp word ptr [bx + 0x5a1c], 0 */
    TR(0x0c53b); if (RW(DS_, (uint16_t)(BX + 0x5a1c)) != 0x0) goto L0c549; /* 089d:3b6b jne 0xc549 */
    TR(0x0c53d); CYC(48); WW(DS_, (uint16_t)(BX + 0x5a1c), 0x0); /* 089d:3b6d mov word ptr [bx + 0x5a1c], 0 */
    TR(0x0c543); WW(DS_, (uint16_t)(BX + 0x5a48), 0x0); /* 089d:3b73 mov word ptr [bx + 0x5a48], 0 */
L0c549:
    TR(0x0c549); CYC(23); PUSH(0x3b7c); goto L0c5aa; /* 089d:3b79 call 0xc5aa */
L0c54c:
    TR(0x0c54c); CYC(40); /* 089d:3b7c cmp word ptr [0x4176], 1 */
    TR(0x0c551); if (RW(DS_, 0x4176) != 0x1) goto L0c5a9; /* 089d:3b81 jne 0xc5a9 */
    TR(0x0c553); CYC(40); /* 089d:3b83 cmp word ptr [bx + 0x5a06], 1 */
    TR(0x0c558); if (RW(DS_, (uint16_t)(BX + 0x5a06)) != 0x1) goto L0c5a9; /* 089d:3b88 jne 0xc5a9 */
    TR(0x0c55a); CYC(68); AX = RW(DS_, 0x4170); /* 089d:3b8a mov ax, word ptr [0x4170] */
    TR(0x0c55d); DX = RW(DS_, (uint16_t)(BX + 0x59da)); /* 089d:3b8d mov dx, word ptr [bx + 0x59da] */
    TR(0x0c561); AX += 0x14; /* 089d:3b91 add ax, 0x14 */
    TR(0x0c564); /* 089d:3b94 cmp ax, dx */
    TR(0x0c566); if ((int16_t)AX < (int16_t)DX) goto L0c5a9; /* 089d:3b96 jl 0xc5a9 */
    TR(0x0c568); CYC(44); AX -= 0x14; /* 089d:3b98 sub ax, 0x14 */
    TR(0x0c56b); DX += 0x4; /* 089d:3b9b add dx, 4 */
    TR(0x0c56e); /* 089d:3b9e cmp ax, dx */
    TR(0x0c570); if ((int16_t)AX > (int16_t)DX) goto L0c5a9; /* 089d:3ba0 jg 0xc5a9 */
    TR(0x0c572); CYC(68); AX = RW(DS_, 0x4172); /* 089d:3ba2 mov ax, word ptr [0x4172] */
    TR(0x0c575); DX = RW(DS_, (uint16_t)(BX + 0x59f0)); /* 089d:3ba5 mov dx, word ptr [bx + 0x59f0] */
    TR(0x0c579); AX += 0xe; /* 089d:3ba9 add ax, 0xe */
    TR(0x0c57c); /* 089d:3bac cmp ax, dx */
    TR(0x0c57e); if ((int16_t)AX < (int16_t)DX) goto L0c5a9; /* 089d:3bae jl 0xc5a9 */
    TR(0x0c580); CYC(44); AX -= 0xe; /* 089d:3bb0 sub ax, 0xe */
    TR(0x0c583); DX += 0x3; /* 089d:3bb3 add dx, 3 */
    TR(0x0c586); /* 089d:3bb6 cmp ax, dx */
    TR(0x0c588); if ((int16_t)AX > (int16_t)DX) goto L0c5a9; /* 089d:3bb8 jg 0xc5a9 */
    TR(0x0c58a); CYC(143); WW(DS_, 0x5360, 0x1); /* 089d:3bba mov word ptr [0x5360], 1 */
    TR(0x0c590); WW(DS_, 0x5aee, 0x1); /* 089d:3bc0 mov word ptr [0x5aee], 1 */
    TR(0x0c596); AX = RW(DS_, (uint16_t)(BX + 0x59da)); /* 089d:3bc6 mov ax, word ptr [bx + 0x59da] */
    TR(0x0c59a); AX -= 0xa; /* 089d:3bca sub ax, 0xa */
    TR(0x0c59d); WW(DS_, 0x5af0, AX); /* 089d:3bcd mov word ptr [0x5af0], ax */
    TR(0x0c5a0); WW(DS_, (uint16_t)(BX + 0x5a06), 0x0); /* 089d:3bd0 mov word ptr [bx + 0x5a06], 0 */
    TR(0x0c5a6); PUSH(0x3bd9); goto L0c5aa; /* 089d:3bd6 call 0xc5aa */
L0c5a9:
    TR(0x0c5a9); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3bd9 ret  */

/* ---- f_089d_3bda */
L0c5aa:
    TR(0x0c5aa); CYC(40); /* 089d:3bda cmp word ptr [bx + 0x59da], 0x13b */
    TR(0x0c5b0); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x59da)) > (int16_t)0x13b) goto L0c5f9; /* 089d:3be0 jg 0xc5f9 */
    TR(0x0c5b2); CYC(40); /* 089d:3be2 cmp word ptr [bx + 0x59da], 0 */
    TR(0x0c5b7); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x59da)) < (int16_t)0x0) goto L0c5f9; /* 089d:3be7 jl 0xc5f9 */
    TR(0x0c5b9); CYC(346); PUSH(BX); /* 089d:3be9 push bx */
    TR(0x0c5ba); PUSH(CX); /* 089d:3bea push cx */
    TR(0x0c5bb); PUSH(DX); /* 089d:3beb push dx */
    TR(0x0c5bc); PUSH(SI); /* 089d:3bec push si */
    TR(0x0c5bd); PUSH(DI); /* 089d:3bed push di */
    TR(0x0c5be); AX = RW(DS_, (uint16_t)(BX + 0x5a5e)); /* 089d:3bee mov ax, word ptr [bx + 0x5a5e] */
    TR(0x0c5c2); AX += AX; /* 089d:3bf2 add ax, ax */
    TR(0x0c5c4); DI = AX; /* 089d:3bf4 mov di, ax */
    TR(0x0c5c6); SI = RW(DS_, (uint16_t)(DI + 0x7af0)); /* 089d:3bf6 mov si, word ptr [di + 0x7af0] */
    TR(0x0c5ca); DL = RB(DS_, SI); /* 089d:3bfa mov dl, byte ptr [si] */
    TR(0x0c5cc); DH = DL; /* 089d:3bfc mov dh, dl */
    TR(0x0c5ce); SI++; /* 089d:3bfe inc si */
    TR(0x0c5cf); CH = RB(DS_, SI); /* 089d:3bff mov ch, byte ptr [si] */
    TR(0x0c5d1); SI++; /* 089d:3c01 inc si */
    TR(0x0c5d2); WW(DS_, 0x36, SI); /* 089d:3c02 mov word ptr [0x36], si */
    TR(0x0c5d6); AX = RW(DS_, (uint16_t)(BX + 0x59f0)); /* 089d:3c06 mov ax, word ptr [bx + 0x59f0] */
    TR(0x0c5da); WW(DS_, 0x2e, AX); /* 089d:3c0a mov word ptr [0x2e], ax */
    TR(0x0c5dd); BX = RW(DS_, (uint16_t)(BX + 0x59da)); /* 089d:3c0d mov bx, word ptr [bx + 0x59da] */
    TR(0x0c5e1); AX = RW(DS_, (uint16_t)(BX + 0x680e)); /* 089d:3c11 mov ax, word ptr [bx + 0x680e] */
    TR(0x0c5e5); AH = 0x0; /* 089d:3c15 mov ah, 0 */
    TR(0x0c5e7); WW(DS_, 0x2c, AX); /* 089d:3c17 mov word ptr [0x2c], ax */
    TR(0x0c5ea); AX = RW(DS_, (uint16_t)(BX + 0x695c)); /* 089d:3c1a mov ax, word ptr [bx + 0x695c] */
    TR(0x0c5ee); WW(DS_, 0x3a, AX); /* 089d:3c1e mov word ptr [0x3a], ax */
    TR(0x0c5f1); PUSH(0x3c24); goto L0ae25; /* 089d:3c21 call 0xae25 */
L0c5f4:
    TR(0x0c5f4); CYC(60); DI = POP(); /* 089d:3c24 pop di */
    TR(0x0c5f5); SI = POP(); /* 089d:3c25 pop si */
    TR(0x0c5f6); DX = POP(); /* 089d:3c26 pop dx */
    TR(0x0c5f7); CX = POP(); /* 089d:3c27 pop cx */
    TR(0x0c5f8); BX = POP(); /* 089d:3c28 pop bx */
L0c5f9:
    TR(0x0c5f9); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3c29 ret  */

/* ---- f_089d_3c2a */
L0c5fa:
    TR(0x0c5fa); CYC(40); /* 089d:3c2a cmp word ptr [bx + 0x5a80], 0x123 */
    TR(0x0c600); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x5a80)) > (int16_t)0x123) goto L0c64c; /* 089d:3c30 jg 0xc64c */
    TR(0x0c602); CYC(40); /* 089d:3c32 cmp word ptr [bx + 0x5a80], 0 */
    TR(0x0c607); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x5a80)) < (int16_t)0x0) goto L0c64c; /* 089d:3c37 jl 0xc64c */
    TR(0x0c609); CYC(356); AX = RW(DS_, (uint16_t)(BX + 0x5ac2)); /* 089d:3c39 mov ax, word ptr [bx + 0x5ac2] */
    TR(0x0c60d); AX >>= 1; /* 089d:3c3d shr ax, 1 */
    TR(0x0c60f); PUSH(BX); /* 089d:3c3f push bx */
    TR(0x0c610); PUSH(CX); /* 089d:3c40 push cx */
    TR(0x0c611); PUSH(DX); /* 089d:3c41 push dx */
    TR(0x0c612); PUSH(SI); /* 089d:3c42 push si */
    TR(0x0c613); PUSH(DI); /* 089d:3c43 push di */
    TR(0x0c614); AX = AX; /* 089d:3c44 mov ax, ax */
    TR(0x0c616); AX += AX; /* 089d:3c46 add ax, ax */
    TR(0x0c618); DI = AX; /* 089d:3c48 mov di, ax */
    TR(0x0c61a); SI = RW(DS_, (uint16_t)(DI + 0x7b04)); /* 089d:3c4a mov si, word ptr [di + 0x7b04] */
    TR(0x0c61e); DL = RB(DS_, SI); /* 089d:3c4e mov dl, byte ptr [si] */
    TR(0x0c620); DH = DL; /* 089d:3c50 mov dh, dl */
    TR(0x0c622); SI++; /* 089d:3c52 inc si */
    TR(0x0c623); CH = RB(DS_, SI); /* 089d:3c53 mov ch, byte ptr [si] */
    TR(0x0c625); SI++; /* 089d:3c55 inc si */
    TR(0x0c626); WW(DS_, 0x36, SI); /* 089d:3c56 mov word ptr [0x36], si */
    TR(0x0c62a); AX = 0xa0; /* 089d:3c5a mov ax, 0xa0 */
    TR(0x0c62d); WW(DS_, 0x2e, AX); /* 089d:3c5d mov word ptr [0x2e], ax */
    TR(0x0c630); BX = RW(DS_, (uint16_t)(BX + 0x5a80)); /* 089d:3c60 mov bx, word ptr [bx + 0x5a80] */
    TR(0x0c634); AX = RW(DS_, (uint16_t)(BX + 0x680e)); /* 089d:3c64 mov ax, word ptr [bx + 0x680e] */
    TR(0x0c638); AH = 0x0; /* 089d:3c68 mov ah, 0 */
    TR(0x0c63a); WW(DS_, 0x2c, AX); /* 089d:3c6a mov word ptr [0x2c], ax */
    TR(0x0c63d); AX = RW(DS_, (uint16_t)(BX + 0x695c)); /* 089d:3c6d mov ax, word ptr [bx + 0x695c] */
    TR(0x0c641); WW(DS_, 0x3a, AX); /* 089d:3c71 mov word ptr [0x3a], ax */
    TR(0x0c644); PUSH(0x3c77); goto L0ae25; /* 089d:3c74 call 0xae25 */
L0c647:
    TR(0x0c647); CYC(60); DI = POP(); /* 089d:3c77 pop di */
    TR(0x0c648); SI = POP(); /* 089d:3c78 pop si */
    TR(0x0c649); DX = POP(); /* 089d:3c79 pop dx */
    TR(0x0c64a); CX = POP(); /* 089d:3c7a pop cx */
    TR(0x0c64b); BX = POP(); /* 089d:3c7b pop bx */
L0c64c:
    TR(0x0c64c); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3c7c ret  */

/* ---- f_089d_3c7d */
L0c64d:
    TR(0x0c64d); CYC(30); CX = RW(DS_, 0x5af2); /* 089d:3c7d mov cx, word ptr [0x5af2] */
    TR(0x0c651); BX = 0x0; /* 089d:3c81 mov bx, 0 */
L0c654:
    TR(0x0c654); CYC(40); /* 089d:3c84 cmp word ptr [bx + 0x5aac], 0 */
    TR(0x0c659); if (RW(DS_, (uint16_t)(BX + 0x5aac)) == 0x0) goto L0c661; /* 089d:3c89 je 0xc661 */
    TR(0x0c65b); CYC(23); PUSH(0x3c8e); goto L0c695; /* 089d:3c8b call 0xc695 */
L0c65e:
    TR(0x0c65e); CYC(15); goto L0c68a; /* 089d:3c8e jmp 0xc68a */
L0c661:
    TR(0x0c661); CYC(40); /* 089d:3c91 cmp word ptr [0x5aee], 0 */
    TR(0x0c666); if (RW(DS_, 0x5aee) == 0x0) goto L0c68a; /* 089d:3c96 je 0xc68a */
    TR(0x0c668); CYC(155); WW(DS_, 0x5aee, 0x0); /* 089d:3c98 mov word ptr [0x5aee], 0 */
    TR(0x0c66e); WW(DS_, (uint16_t)(BX + 0x5aac), 0x1); /* 089d:3c9e mov word ptr [bx + 0x5aac], 1 */
    TR(0x0c674); AX = RW(DS_, 0x5af0); /* 089d:3ca4 mov ax, word ptr [0x5af0] */
    TR(0x0c677); WW(DS_, (uint16_t)(BX + 0x5a80), AX); /* 089d:3ca7 mov word ptr [bx + 0x5a80], ax */
    TR(0x0c67b); WW(DS_, (uint16_t)(BX + 0x5ac2), 0x0); /* 089d:3cab mov word ptr [bx + 0x5ac2], 0 */
    TR(0x0c681); WW(DS_, (uint16_t)(BX + 0x5ad8), 0x16); /* 089d:3cb1 mov word ptr [bx + 0x5ad8], 0x16 */
    TR(0x0c687); PUSH(0x3cba); goto L0c5fa; /* 089d:3cb7 call 0xc5fa */
L0c68a:
    TR(0x0c68a); CYC(25); BX++; /* 089d:3cba inc bx */
    TR(0x0c68b); BX++; /* 089d:3cbb inc bx */
    TR(0x0c68c); if (--CX) goto L0c654; /* 089d:3cbc loop 0xc654 */
    TR(0x0c68e); CYC(44); WW(DS_, 0x5aee, 0x0); /* 089d:3cbe mov word ptr [0x5aee], 0 */
    TR(0x0c694); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3cc4 ret  */

/* ---- f_089d_3cc5 */
L0c695:
    TR(0x0c695); CYC(23); PUSH(0x3cc8); goto L0c5fa; /* 089d:3cc5 call 0xc5fa */
L0c698:
    TR(0x0c698); CYC(121); AX = RW(DS_, 0x4a); /* 089d:3cc8 mov ax, word ptr [0x4a] */
    TR(0x0c69b); AX = (uint16_t)(0u - AX); /* 089d:3ccb neg ax */
    TR(0x0c69d); WW(DS_, (uint16_t)(BX + 0x5a80), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x5a80)) + AX)); /* 089d:3ccd add word ptr [bx + 0x5a80], ax */
    TR(0x0c6a1); WW(DS_, (uint16_t)(BX + 0x5ac2), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x5ac2)) + 1)); /* 089d:3cd1 inc word ptr [bx + 0x5ac2] */
    TR(0x0c6a5); /* 089d:3cd5 cmp word ptr [bx + 0x5ac2], 0x16 */
    TR(0x0c6aa); if (RW(DS_, (uint16_t)(BX + 0x5ac2)) != 0x16) goto L0c6b2; /* 089d:3cda jne 0xc6b2 */
    TR(0x0c6ac); CYC(24); WW(DS_, (uint16_t)(BX + 0x5ac2), 0x0); /* 089d:3cdc mov word ptr [bx + 0x5ac2], 0 */
L0c6b2:
    TR(0x0c6b2); CYC(39); { uint16_t a_ = RW(DS_, (uint16_t)(BX + 0x5ad8)), b_ = 1; unsigned r_ = (unsigned)a_ - 1;   WW(DS_, (uint16_t)(BX + 0x5ad8), (uint16_t)r_);   ZF = ((r_ & 0xffff) == 0); } /* 089d:3ce2 dec word ptr [bx + 0x5ad8] */
    TR(0x0c6b6); if (!ZF) goto L0c6bf; /* 089d:3ce6 jne 0xc6bf */
    TR(0x0c6b8); CYC(44); WW(DS_, (uint16_t)(BX + 0x5aac), 0x0); /* 089d:3ce8 mov word ptr [bx + 0x5aac], 0 */
    TR(0x0c6be); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3cee ret  */
L0c6bf:
    TR(0x0c6bf); CYC(23); PUSH(0x3cf2); goto L0c5fa; /* 089d:3cef call 0xc5fa */
L0c6c2:
    TR(0x0c6c2); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3cf2 ret  */

/* ---- f_089d_3cf3 */
L0c6c3:
    TR(0x0c6c3); CYC(40); /* 089d:3cf3 cmp word ptr [bx + 0x4ff6], 0x13b */
    TR(0x0c6c9); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x4ff6)) > (int16_t)0x13b) goto L0c711; /* 089d:3cf9 jg 0xc711 */
    TR(0x0c6cb); CYC(40); /* 089d:3cfb cmp word ptr [bx + 0x4ff6], 0 */
    TR(0x0c6d0); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x4ff6)) < (int16_t)0x0) goto L0c711; /* 089d:3d00 jl 0xc711 */
    TR(0x0c6d2); CYC(340); PUSH(BX); /* 089d:3d02 push bx */
    TR(0x0c6d3); PUSH(CX); /* 089d:3d03 push cx */
    TR(0x0c6d4); PUSH(DX); /* 089d:3d04 push dx */
    TR(0x0c6d5); PUSH(SI); /* 089d:3d05 push si */
    TR(0x0c6d6); PUSH(DI); /* 089d:3d06 push di */
    TR(0x0c6d7); AX = 0x0; /* 089d:3d07 mov ax, 0 */
    TR(0x0c6da); AX += AX; /* 089d:3d0a add ax, ax */
    TR(0x0c6dc); DI = AX; /* 089d:3d0c mov di, ax */
    TR(0x0c6de); SI = RW(DS_, (uint16_t)(DI + 0x8134)); /* 089d:3d0e mov si, word ptr [di - 0x7ecc] */
    TR(0x0c6e2); DL = RB(DS_, SI); /* 089d:3d12 mov dl, byte ptr [si] */
    TR(0x0c6e4); DH = DL; /* 089d:3d14 mov dh, dl */
    TR(0x0c6e6); SI++; /* 089d:3d16 inc si */
    TR(0x0c6e7); CH = RB(DS_, SI); /* 089d:3d17 mov ch, byte ptr [si] */
    TR(0x0c6e9); SI++; /* 089d:3d19 inc si */
    TR(0x0c6ea); WW(DS_, 0x36, SI); /* 089d:3d1a mov word ptr [0x36], si */
    TR(0x0c6ee); AX = RW(DS_, (uint16_t)(BX + 0x500a)); /* 089d:3d1e mov ax, word ptr [bx + 0x500a] */
    TR(0x0c6f2); WW(DS_, 0x2e, AX); /* 089d:3d22 mov word ptr [0x2e], ax */
    TR(0x0c6f5); BX = RW(DS_, (uint16_t)(BX + 0x4ff6)); /* 089d:3d25 mov bx, word ptr [bx + 0x4ff6] */
    TR(0x0c6f9); AX = RW(DS_, (uint16_t)(BX + 0x680e)); /* 089d:3d29 mov ax, word ptr [bx + 0x680e] */
    TR(0x0c6fd); AH = 0x0; /* 089d:3d2d mov ah, 0 */
    TR(0x0c6ff); WW(DS_, 0x2c, AX); /* 089d:3d2f mov word ptr [0x2c], ax */
    TR(0x0c702); AX = RW(DS_, (uint16_t)(BX + 0x695c)); /* 089d:3d32 mov ax, word ptr [bx + 0x695c] */
    TR(0x0c706); WW(DS_, 0x3a, AX); /* 089d:3d36 mov word ptr [0x3a], ax */
    TR(0x0c709); PUSH(0x3d3c); goto L0ae25; /* 089d:3d39 call 0xae25 */
L0c70c:
    TR(0x0c70c); CYC(60); DI = POP(); /* 089d:3d3c pop di */
    TR(0x0c70d); SI = POP(); /* 089d:3d3d pop si */
    TR(0x0c70e); DX = POP(); /* 089d:3d3e pop dx */
    TR(0x0c70f); CX = POP(); /* 089d:3d3f pop cx */
    TR(0x0c710); BX = POP(); /* 089d:3d40 pop bx */
L0c711:
    TR(0x0c711); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3d41 ret  */

/* ---- f_089d_3d42 */
L0c712:
    TR(0x0c712); CYC(40); /* 089d:3d42 cmp word ptr [0x5064], 1 */
    TR(0x0c717); if (RW(DS_, 0x5064) == 0x1) goto L0c71a; /* 089d:3d47 je 0xc71a */
    TR(0x0c719); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3d49 ret  */
L0c71a:
    TR(0x0c71a); CYC(30); CX = RW(DS_, 0x5062); /* 089d:3d4a mov cx, word ptr [0x5062] */
    TR(0x0c71e); BX = 0x0; /* 089d:3d4e mov bx, 0 */
L0c721:
    TR(0x0c721); CYC(40); /* 089d:3d51 cmp word ptr [bx + 0x501e], 2 */
    TR(0x0c726); if (RW(DS_, (uint16_t)(BX + 0x501e)) != 0x2) goto L0c72e; /* 089d:3d56 jne 0xc72e */
    TR(0x0c728); CYC(23); PUSH(0x3d5b); goto L0c77a; /* 089d:3d58 call 0xc77a */
L0c72b:
    TR(0x0c72b); CYC(15); goto L0c76f; /* 089d:3d5b jmp 0xc76f */
L0c72e:
    TR(0x0c72e); CYC(40); /* 089d:3d5e cmp word ptr [bx + 0x501e], 0 */
    TR(0x0c733); if (RW(DS_, (uint16_t)(BX + 0x501e)) != 0x0) goto L0c76f; /* 089d:3d63 jne 0xc76f */
    TR(0x0c735); CYC(40); /* 089d:3d65 cmp word ptr [0x5066], 0 */
    TR(0x0c73a); if (RW(DS_, 0x5066) == 0x0) goto L0c76f; /* 089d:3d6a je 0xc76f */
    TR(0x0c73c); CYC(239); WW(DS_, 0x5066, 0x0); /* 089d:3d6c mov word ptr [0x5066], 0 */
    TR(0x0c742); WW(DS_, (uint16_t)(BX + 0x501e), 0x2); /* 089d:3d72 mov word ptr [bx + 0x501e], 2 */
    TR(0x0c748); AX = RW(DS_, 0x4170); /* 089d:3d78 mov ax, word ptr [0x4170] */
    TR(0x0c74b); AX += 0x5; /* 089d:3d7b add ax, 5 */
    TR(0x0c74e); WW(DS_, (uint16_t)(BX + 0x4ff6), AX); /* 089d:3d7e mov word ptr [bx + 0x4ff6], ax */
    TR(0x0c752); AX = RW(DS_, 0x4172); /* 089d:3d82 mov ax, word ptr [0x4172] */
    TR(0x0c755); WW(DS_, (uint16_t)(BX + 0x500a), AX); /* 089d:3d85 mov word ptr [bx + 0x500a], ax */
    TR(0x0c759); AX = RW(DS_, 0x4a); /* 089d:3d89 mov ax, word ptr [0x4a] */
    TR(0x0c75c); AX <<= 1; /* 089d:3d8c shl ax, 1 */
    TR(0x0c75e); AX <<= 1; /* 089d:3d8e shl ax, 1 */
    TR(0x0c760); AX <<= 1; /* 089d:3d90 shl ax, 1 */
    TR(0x0c762); WW(DS_, (uint16_t)(BX + 0x5032), AX); /* 089d:3d92 mov word ptr [bx + 0x5032], ax */
    TR(0x0c766); WW(DS_, (uint16_t)(BX + 0x5046), 0xffea); /* 089d:3d96 mov word ptr [bx + 0x5046], 0xffea */
    TR(0x0c76c); PUSH(0x3d9f); goto L0c6c3; /* 089d:3d9c call 0xc6c3 */
L0c76f:
    TR(0x0c76f); CYC(25); BX++; /* 089d:3d9f inc bx */
    TR(0x0c770); BX++; /* 089d:3da0 inc bx */
    TR(0x0c771); if (--CX) goto L0c721; /* 089d:3da1 loop 0xc721 */
    TR(0x0c773); CYC(44); WW(DS_, 0x5066, 0x0); /* 089d:3da3 mov word ptr [0x5066], 0 */
    TR(0x0c779); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3da9 ret  */

/* ---- f_089d_3daa */
L0c77a:
    TR(0x0c77a); CYC(23); PUSH(0x3dad); goto L0c6c3; /* 089d:3daa call 0xc6c3 */
L0c77d:
    TR(0x0c77d); CYC(208); AX = RW(DS_, (uint16_t)(BX + 0x5032)); /* 089d:3dad mov ax, word ptr [bx + 0x5032] */
    TR(0x0c781); { uint16_t a_ = AX; unsigned n_ = 1 & 0x1f; AX = (uint16_t)((int16_t)a_ >> n_); } /* 089d:3db1 sar ax, 1 */
    TR(0x0c783); { uint16_t a_ = AX; unsigned n_ = 1 & 0x1f; AX = (uint16_t)((int16_t)a_ >> n_); } /* 089d:3db3 sar ax, 1 */
    TR(0x0c785); { uint16_t a_ = AX; unsigned n_ = 1 & 0x1f; AX = (uint16_t)((int16_t)a_ >> n_); } /* 089d:3db5 sar ax, 1 */
    TR(0x0c787); AX -= RW(DS_, 0x4a); /* 089d:3db7 sub ax, word ptr [0x4a] */
    TR(0x0c78b); WW(DS_, (uint16_t)(BX + 0x4ff6), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x4ff6)) + AX)); /* 089d:3dbb add word ptr [bx + 0x4ff6], ax */
    TR(0x0c78f); WW(DS_, (uint16_t)(BX + 0x5046), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x5046)) + 1)); /* 089d:3dbf inc word ptr [bx + 0x5046] */
    TR(0x0c793); AX = RW(DS_, (uint16_t)(BX + 0x5046)); /* 089d:3dc3 mov ax, word ptr [bx + 0x5046] */
    TR(0x0c797); { uint16_t a_ = AX; unsigned n_ = 1 & 0x1f; AX = (uint16_t)((int16_t)a_ >> n_); } /* 089d:3dc7 sar ax, 1 */
    TR(0x0c799); WW(DS_, (uint16_t)(BX + 0x500a), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x500a)) + AX)); /* 089d:3dc9 add word ptr [bx + 0x500a], ax */
    TR(0x0c79d); /* 089d:3dcd cmp word ptr [bx + 0x500a], 0xb0 */
    TR(0x0c7a3); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x500a)) <= (int16_t)0xb0) goto L0c7ac; /* 089d:3dd3 jle 0xc7ac */
    TR(0x0c7a5); CYC(44); WW(DS_, (uint16_t)(BX + 0x501e), 0x0); /* 089d:3dd5 mov word ptr [bx + 0x501e], 0 */
    TR(0x0c7ab); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3ddb ret  */
L0c7ac:
    TR(0x0c7ac); CYC(40); /* 089d:3ddc cmp word ptr [bx + 0x5032], 0 */
    TR(0x0c7b1); if (RW(DS_, (uint16_t)(BX + 0x5032)) == 0x0) goto L0c7b7; /* 089d:3de1 je 0xc7b7 */
    TR(0x0c7b3); CYC(27); WW(DS_, (uint16_t)(BX + 0x5032), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x5032)) - 1)); /* 089d:3de3 dec word ptr [bx + 0x5032] */
L0c7b7:
    TR(0x0c7b7); CYC(23); PUSH(0x3dea); goto L0c6c3; /* 089d:3de7 call 0xc6c3 */
L0c7ba:
    TR(0x0c7ba); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3dea ret  */

/* ---- f_089d_3deb */
L0c7bb:
    TR(0x0c7bb); CYC(40); /* 089d:3deb cmp word ptr [bx + 0x5af4], 0x137 */
    TR(0x0c7c1); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x5af4)) > (int16_t)0x137) goto L0c808; /* 089d:3df1 jg 0xc808 */
    TR(0x0c7c3); CYC(40); /* 089d:3df3 cmp word ptr [bx + 0x5af4], 0 */
    TR(0x0c7c8); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x5af4)) < (int16_t)0x0) goto L0c808; /* 089d:3df8 jl 0xc808 */
    TR(0x0c7ca); CYC(334); PUSH(BX); /* 089d:3dfa push bx */
    TR(0x0c7cb); PUSH(CX); /* 089d:3dfb push cx */
    TR(0x0c7cc); PUSH(DX); /* 089d:3dfc push dx */
    TR(0x0c7cd); PUSH(SI); /* 089d:3dfd push si */
    TR(0x0c7ce); PUSH(DI); /* 089d:3dfe push di */
    TR(0x0c7cf); AX = 0x0; /* 089d:3dff mov ax, 0 */
    TR(0x0c7d2); AX += AX; /* 089d:3e02 add ax, ax */
    TR(0x0c7d4); DI = AX; /* 089d:3e04 mov di, ax */
    TR(0x0c7d6); SI = RW(DS_, (uint16_t)(DI + 0x813c)); /* 089d:3e06 mov si, word ptr [di - 0x7ec4] */
    TR(0x0c7da); DL = RB(DS_, SI); /* 089d:3e0a mov dl, byte ptr [si] */
    TR(0x0c7dc); DH = DL; /* 089d:3e0c mov dh, dl */
    TR(0x0c7de); SI++; /* 089d:3e0e inc si */
    TR(0x0c7df); CH = RB(DS_, SI); /* 089d:3e0f mov ch, byte ptr [si] */
    TR(0x0c7e1); SI++; /* 089d:3e11 inc si */
    TR(0x0c7e2); WW(DS_, 0x36, SI); /* 089d:3e12 mov word ptr [0x36], si */
    TR(0x0c7e6); AX = 0xb1; /* 089d:3e16 mov ax, 0xb1 */
    TR(0x0c7e9); WW(DS_, 0x2e, AX); /* 089d:3e19 mov word ptr [0x2e], ax */
    TR(0x0c7ec); BX = RW(DS_, (uint16_t)(BX + 0x5af4)); /* 089d:3e1c mov bx, word ptr [bx + 0x5af4] */
    TR(0x0c7f0); AX = RW(DS_, (uint16_t)(BX + 0x680e)); /* 089d:3e20 mov ax, word ptr [bx + 0x680e] */
    TR(0x0c7f4); AH = 0x0; /* 089d:3e24 mov ah, 0 */
    TR(0x0c7f6); WW(DS_, 0x2c, AX); /* 089d:3e26 mov word ptr [0x2c], ax */
    TR(0x0c7f9); AX = RW(DS_, (uint16_t)(BX + 0x695c)); /* 089d:3e29 mov ax, word ptr [bx + 0x695c] */
    TR(0x0c7fd); WW(DS_, 0x3a, AX); /* 089d:3e2d mov word ptr [0x3a], ax */
    TR(0x0c800); PUSH(0x3e33); goto L0ae25; /* 089d:3e30 call 0xae25 */
L0c803:
    TR(0x0c803); CYC(60); DI = POP(); /* 089d:3e33 pop di */
    TR(0x0c804); SI = POP(); /* 089d:3e34 pop si */
    TR(0x0c805); DX = POP(); /* 089d:3e35 pop dx */
    TR(0x0c806); CX = POP(); /* 089d:3e36 pop cx */
    TR(0x0c807); BX = POP(); /* 089d:3e37 pop bx */
L0c808:
    TR(0x0c808); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3e38 ret  */

/* ---- f_089d_3e39 */
L0c809:
    TR(0x0c809); CYC(40); /* 089d:3e39 cmp word ptr [0x5c86], 1 */
    TR(0x0c80e); if (RW(DS_, 0x5c86) == 0x1) goto L0c811; /* 089d:3e3e je 0xc811 */
    TR(0x0c810); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3e40 ret  */
L0c811:
    TR(0x0c811); CYC(30); CX = RW(DS_, 0x5c84); /* 089d:3e41 mov cx, word ptr [0x5c84] */
    TR(0x0c815); BX = 0x0; /* 089d:3e45 mov bx, 0 */
L0c818:
    TR(0x0c818); CYC(40); /* 089d:3e48 cmp word ptr [bx + 0x5bbc], 0 */
    TR(0x0c81d); if (RW(DS_, (uint16_t)(BX + 0x5bbc)) == 0x0) goto L0c822; /* 089d:3e4d je 0xc822 */
    TR(0x0c81f); CYC(23); PUSH(0x3e52); goto L0c827; /* 089d:3e4f call 0xc827 */
L0c822:
    TR(0x0c822); CYC(25); BX++; /* 089d:3e52 inc bx */
    TR(0x0c823); BX++; /* 089d:3e53 inc bx */
    TR(0x0c824); if (--CX) goto L0c818; /* 089d:3e54 loop 0xc818 */
    TR(0x0c826); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3e56 ret  */

/* ---- f_089d_3e57 */
L0c827:
    TR(0x0c827); CYC(23); PUSH(0x3e5a); goto L0c7bb; /* 089d:3e57 call 0xc7bb */
L0c82a:
    TR(0x0c82a); CYC(94); AX = RW(DS_, 0x4a); /* 089d:3e5a mov ax, word ptr [0x4a] */
    TR(0x0c82d); AX = (uint16_t)(0u - AX); /* 089d:3e5d neg ax */
    TR(0x0c82f); WW(DS_, (uint16_t)(BX + 0x5af4), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x5af4)) + AX)); /* 089d:3e5f add word ptr [bx + 0x5af4], ax */
    TR(0x0c833); /* 089d:3e63 cmp word ptr [bx + 0x5af4], 0 */
    TR(0x0c838); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x5af4)) >= (int16_t)0x0) goto L0c840; /* 089d:3e68 jge 0xc840 */
    TR(0x0c83a); CYC(24); WW(DS_, (uint16_t)(BX + 0x5af4), 0x18ec); /* 089d:3e6a mov word ptr [bx + 0x5af4], 0x18ec */
L0c840:
    TR(0x0c840); CYC(23); PUSH(0x3e73); goto L0c7bb; /* 089d:3e70 call 0xc7bb */
L0c843:
    TR(0x0c843); CYC(45); PUSH(CX); /* 089d:3e73 push cx */
    TR(0x0c844); CX = RW(DS_, 0x5062); /* 089d:3e74 mov cx, word ptr [0x5062] */
    TR(0x0c848); SI = 0x0; /* 089d:3e78 mov si, 0 */
L0c84b:
    TR(0x0c84b); CYC(40); /* 089d:3e7b cmp word ptr [si + 0x501e], 0 */
    TR(0x0c850); if (RW(DS_, (uint16_t)(SI + 0x501e)) == 0x0) goto L0c8bc; /* 089d:3e80 je 0xc8bc */
    TR(0x0c852); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x5af4)); /* 089d:3e82 mov ax, word ptr [bx + 0x5af4] */
    TR(0x0c856); /* 089d:3e86 cmp word ptr [si + 0x4ff6], ax */
    TR(0x0c85a); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x4ff6)) < (int16_t)AX) goto L0c8bc; /* 089d:3e8a jl 0xc8bc */
    TR(0x0c85c); CYC(52); AX += 0x9; /* 089d:3e8c add ax, 9 */
    TR(0x0c85f); /* 089d:3e8f cmp word ptr [si + 0x4ff6], ax */
    TR(0x0c863); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x4ff6)) > (int16_t)AX) goto L0c8bc; /* 089d:3e93 jg 0xc8bc */
    TR(0x0c865); CYC(52); AX = 0xb0; /* 089d:3e95 mov ax, 0xb0 */
    TR(0x0c868); /* 089d:3e98 cmp word ptr [si + 0x500a], ax */
    TR(0x0c86c); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) < (int16_t)AX) goto L0c8bc; /* 089d:3e9c jl 0xc8bc */
    TR(0x0c86e); CYC(142); WW(DS_, 0x5aee, 0x1); /* 089d:3e9e mov word ptr [0x5aee], 1 */
    TR(0x0c874); AX = RW(DS_, (uint16_t)(BX + 0x5af4)); /* 089d:3ea4 mov ax, word ptr [bx + 0x5af4] */
    TR(0x0c878); AX -= 0xa; /* 089d:3ea8 sub ax, 0xa */
    TR(0x0c87b); WW(DS_, 0x5af0, AX); /* 089d:3eab mov word ptr [0x5af0], ax */
    TR(0x0c87e); WW(DS_, (uint16_t)(SI + 0x501e), 0x0); /* 089d:3eae mov word ptr [si + 0x501e], 0 */
    TR(0x0c884); PUSH(BX); /* 089d:3eb4 push bx */
    TR(0x0c885); BX = SI; /* 089d:3eb5 mov bx, si */
    TR(0x0c887); PUSH(0x3eba); goto L0b66e; /* 089d:3eb7 call 0xb66e */
L0c88a:
    TR(0x0c88a); CYC(59); BX = POP(); /* 089d:3eba pop bx */
    TR(0x0c88b); WW(DS_, (uint16_t)(BX + 0x5bbc), 0x0); /* 089d:3ebb mov word ptr [bx + 0x5bbc], 0 */
    TR(0x0c891); PUSH(0x3ec4); goto L0c7bb; /* 089d:3ec1 call 0xc7bb */
L0c894:
    TR(0x0c894); CYC(35); AX = 0x64; /* 089d:3ec4 mov ax, 0x64 */
    TR(0x0c897); PUSH(0x3eca); goto L0b829; /* 089d:3ec7 call 0xb829 */
L0c89a:
    TR(0x0c89a); CYC(147); WW(DS_, 0x5160, 0x1); /* 089d:3eca mov word ptr [0x5160], 1 */
    TR(0x0c8a0); AX = RW(DS_, (uint16_t)(BX + 0x5af4)); /* 089d:3ed0 mov ax, word ptr [bx + 0x5af4] */
    TR(0x0c8a4); WW(DS_, 0x5162, AX); /* 089d:3ed4 mov word ptr [0x5162], ax */
    TR(0x0c8a7); WW(DS_, 0x5164, 0xa5); /* 089d:3ed7 mov word ptr [0x5164], 0xa5 */
    TR(0x0c8ad); WW(DS_, 0x5166, 0x3); /* 089d:3edd mov word ptr [0x5166], 3 */
    TR(0x0c8b3); WW(DS_, 0x516a, 0x0); /* 089d:3ee3 mov word ptr [0x516a], 0 */
    TR(0x0c8b9); goto L0c8c0; /* 089d:3ee9 jmp 0xc8c0 */
L0c8bc:
    TR(0x0c8bc); CYC(25); SI++; /* 089d:3eec inc si */
    TR(0x0c8bd); SI++; /* 089d:3eed inc si */
    TR(0x0c8be); if (--CX) goto L0c84b; /* 089d:3eee loop 0xc84b */
L0c8c0:
    TR(0x0c8c0); CYC(52); CX = POP(); /* 089d:3ef0 pop cx */
    TR(0x0c8c1); /* 089d:3ef1 cmp word ptr [bx + 0x5c20], 1 */
    TR(0x0c8c6); if (RW(DS_, (uint16_t)(BX + 0x5c20)) == 0x1) goto L0c8e1; /* 089d:3ef6 je 0xc8e1 */
    TR(0x0c8c8); CYC(59); AX = RW(DS_, (uint16_t)(BX + 0x5af4)); /* 089d:3ef8 mov ax, word ptr [bx + 0x5af4] */
    TR(0x0c8cc); AX += 0x8; /* 089d:3efc add ax, 8 */
    TR(0x0c8cf); /* 089d:3eff cmp ax, word ptr [0x4170] */
    TR(0x0c8d3); if ((int16_t)AX > (int16_t)RW(DS_, 0x4170)) goto L0c8e1; /* 089d:3f03 jg 0xc8e1 */
    TR(0x0c8d5); CYC(59); WW(DS_, (uint16_t)(BX + 0x5c20), 0x1); /* 089d:3f05 mov word ptr [bx + 0x5c20], 1 */
    TR(0x0c8db); AX = 0xf; /* 089d:3f0b mov ax, 0xf */
    TR(0x0c8de); PUSH(0x3f11); goto L0b829; /* 089d:3f0e call 0xb829 */
L0c8e1:
    TR(0x0c8e1); CYC(40); /* 089d:3f11 cmp word ptr [0x4176], 1 */
    TR(0x0c8e6); if (RW(DS_, 0x4176) != 0x1) goto L0c92f; /* 089d:3f16 jne 0xc92f */
    TR(0x0c8e8); CYC(68); AX = RW(DS_, 0x4170); /* 089d:3f18 mov ax, word ptr [0x4170] */
    TR(0x0c8eb); DX = RW(DS_, (uint16_t)(BX + 0x5af4)); /* 089d:3f1b mov dx, word ptr [bx + 0x5af4] */
    TR(0x0c8ef); AX += 0x14; /* 089d:3f1f add ax, 0x14 */
    TR(0x0c8f2); /* 089d:3f22 cmp ax, dx */
    TR(0x0c8f4); if ((int16_t)AX < (int16_t)DX) goto L0c92f; /* 089d:3f24 jl 0xc92f */
    TR(0x0c8f6); CYC(44); AX -= 0x14; /* 089d:3f26 sub ax, 0x14 */
    TR(0x0c8f9); DX += 0x8; /* 089d:3f29 add dx, 8 */
    TR(0x0c8fc); /* 089d:3f2c cmp ax, dx */
    TR(0x0c8fe); if ((int16_t)AX > (int16_t)DX) goto L0c92f; /* 089d:3f2e jg 0xc92f */
    TR(0x0c900); CYC(62); AX = RW(DS_, 0x4172); /* 089d:3f30 mov ax, word ptr [0x4172] */
    TR(0x0c903); DX = 0xb2; /* 089d:3f33 mov dx, 0xb2 */
    TR(0x0c906); AX += 0xe; /* 089d:3f36 add ax, 0xe */
    TR(0x0c909); /* 089d:3f39 cmp ax, dx */
    TR(0x0c90b); if ((int16_t)AX < (int16_t)DX) goto L0c92f; /* 089d:3f3b jl 0xc92f */
    TR(0x0c90d); CYC(155); WW(DS_, 0x5360, 0x1); /* 089d:3f3d mov word ptr [0x5360], 1 */
    TR(0x0c913); WW(DS_, 0x50d6, 0x1); /* 089d:3f43 mov word ptr [0x50d6], 1 */
    TR(0x0c919); AX = RW(DS_, (uint16_t)(BX + 0x5af4)); /* 089d:3f49 mov ax, word ptr [bx + 0x5af4] */
    TR(0x0c91d); WW(DS_, 0x50d8, AX); /* 089d:3f4d mov word ptr [0x50d8], ax */
    TR(0x0c920); WW(DS_, 0x50da, 0xa1); /* 089d:3f50 mov word ptr [0x50da], 0xa1 */
    TR(0x0c926); WW(DS_, (uint16_t)(BX + 0x5bbc), 0x0); /* 089d:3f56 mov word ptr [bx + 0x5bbc], 0 */
    TR(0x0c92c); PUSH(0x3f5f); goto L0c7bb; /* 089d:3f5c call 0xc7bb */
L0c92f:
    TR(0x0c92f); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3f5f ret  */

/* ---- f_089d_3f60 */
L0c930:
    TR(0x0c930); CYC(40); /* 089d:3f60 cmp word ptr [bx + 0x5c88], 0x123 */
    TR(0x0c936); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x5c88)) > (int16_t)0x123) goto L0c981; /* 089d:3f66 jg 0xc981 */
    TR(0x0c938); CYC(40); /* 089d:3f68 cmp word ptr [bx + 0x5c88], 0 */
    TR(0x0c93d); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x5c88)) < (int16_t)0x0) goto L0c981; /* 089d:3f6d jl 0xc981 */
    TR(0x0c93f); CYC(354); AX = RW(DS_, (uint16_t)(BX + 0x5cec)); /* 089d:3f6f mov ax, word ptr [bx + 0x5cec] */
    TR(0x0c943); PUSH(BX); /* 089d:3f73 push bx */
    TR(0x0c944); PUSH(CX); /* 089d:3f74 push cx */
    TR(0x0c945); PUSH(DX); /* 089d:3f75 push dx */
    TR(0x0c946); PUSH(SI); /* 089d:3f76 push si */
    TR(0x0c947); PUSH(DI); /* 089d:3f77 push di */
    TR(0x0c948); AX = AX; /* 089d:3f78 mov ax, ax */
    TR(0x0c94a); AX += AX; /* 089d:3f7a add ax, ax */
    TR(0x0c94c); DI = AX; /* 089d:3f7c mov di, ax */
    TR(0x0c94e); SI = RW(DS_, (uint16_t)(DI + 0x8146)); /* 089d:3f7e mov si, word ptr [di - 0x7eba] */
    TR(0x0c952); DL = RB(DS_, SI); /* 089d:3f82 mov dl, byte ptr [si] */
    TR(0x0c954); DH = DL; /* 089d:3f84 mov dh, dl */
    TR(0x0c956); SI++; /* 089d:3f86 inc si */
    TR(0x0c957); CH = RB(DS_, SI); /* 089d:3f87 mov ch, byte ptr [si] */
    TR(0x0c959); SI++; /* 089d:3f89 inc si */
    TR(0x0c95a); WW(DS_, 0x36, SI); /* 089d:3f8a mov word ptr [0x36], si */
    TR(0x0c95e); AX = RW(DS_, (uint16_t)(BX + 0x5e7c)); /* 089d:3f8e mov ax, word ptr [bx + 0x5e7c] */
    TR(0x0c962); WW(DS_, 0x2e, AX); /* 089d:3f92 mov word ptr [0x2e], ax */
    TR(0x0c965); BX = RW(DS_, (uint16_t)(BX + 0x5c88)); /* 089d:3f95 mov bx, word ptr [bx + 0x5c88] */
    TR(0x0c969); AX = RW(DS_, (uint16_t)(BX + 0x680e)); /* 089d:3f99 mov ax, word ptr [bx + 0x680e] */
    TR(0x0c96d); AH = 0x0; /* 089d:3f9d mov ah, 0 */
    TR(0x0c96f); WW(DS_, 0x2c, AX); /* 089d:3f9f mov word ptr [0x2c], ax */
    TR(0x0c972); AX = RW(DS_, (uint16_t)(BX + 0x695c)); /* 089d:3fa2 mov ax, word ptr [bx + 0x695c] */
    TR(0x0c976); WW(DS_, 0x3a, AX); /* 089d:3fa6 mov word ptr [0x3a], ax */
    TR(0x0c979); PUSH(0x3fac); goto L0ae25; /* 089d:3fa9 call 0xae25 */
L0c97c:
    TR(0x0c97c); CYC(60); DI = POP(); /* 089d:3fac pop di */
    TR(0x0c97d); SI = POP(); /* 089d:3fad pop si */
    TR(0x0c97e); DX = POP(); /* 089d:3fae pop dx */
    TR(0x0c97f); CX = POP(); /* 089d:3faf pop cx */
    TR(0x0c980); BX = POP(); /* 089d:3fb0 pop bx */
L0c981:
    TR(0x0c981); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3fb1 ret  */

/* ---- f_089d_3fb2 */
L0c982:
    TR(0x0c982); CYC(40); /* 089d:3fb2 cmp word ptr [0x5f46], 1 */
    TR(0x0c987); if (RW(DS_, 0x5f46) == 0x1) goto L0c98a; /* 089d:3fb7 je 0xc98a */
    TR(0x0c989); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3fb9 ret  */
L0c98a:
    TR(0x0c98a); CYC(30); CX = RW(DS_, 0x5f44); /* 089d:3fba mov cx, word ptr [0x5f44] */
    TR(0x0c98e); BX = 0x0; /* 089d:3fbe mov bx, 0 */
L0c991:
    TR(0x0c991); CYC(40); /* 089d:3fc1 cmp word ptr [bx + 0x5d50], 0 */
    TR(0x0c996); if (RW(DS_, (uint16_t)(BX + 0x5d50)) == 0x0) goto L0c99b; /* 089d:3fc6 je 0xc99b */
    TR(0x0c998); CYC(23); PUSH(0x3fcb); goto L0c9a0; /* 089d:3fc8 call 0xc9a0 */
L0c99b:
    TR(0x0c99b); CYC(25); BX++; /* 089d:3fcb inc bx */
    TR(0x0c99c); BX++; /* 089d:3fcc inc bx */
    TR(0x0c99d); if (--CX) goto L0c991; /* 089d:3fcd loop 0xc991 */
    TR(0x0c99f); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:3fcf ret  */

/* ---- f_089d_3fd0 */
L0c9a0:
    TR(0x0c9a0); CYC(23); PUSH(0x3fd3); goto L0c930; /* 089d:3fd0 call 0xc930 */
L0c9a3:
    TR(0x0c9a3); CYC(111); AX = RW(DS_, 0x4a); /* 089d:3fd3 mov ax, word ptr [0x4a] */
    TR(0x0c9a6); AX = (uint16_t)(0u - AX); /* 089d:3fd6 neg ax */
    TR(0x0c9a8); AX += RW(DS_, (uint16_t)(BX + 0x5e18)); /* 089d:3fd8 add ax, word ptr [bx + 0x5e18] */
    TR(0x0c9ac); WW(DS_, (uint16_t)(BX + 0x5c88), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x5c88)) + AX)); /* 089d:3fdc add word ptr [bx + 0x5c88], ax */
    TR(0x0c9b0); /* 089d:3fe0 cmp word ptr [bx + 0x5c88], 0 */
    TR(0x0c9b5); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x5c88)) >= (int16_t)0x0) goto L0c9bd; /* 089d:3fe5 jge 0xc9bd */
    TR(0x0c9b7); CYC(24); WW(DS_, (uint16_t)(BX + 0x5c88), 0x18ec); /* 089d:3fe7 mov word ptr [bx + 0x5c88], 0x18ec */
L0c9bd:
    TR(0x0c9bd); CYC(67); WW(DS_, (uint16_t)(BX + 0x5cec), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x5cec)) + 1)); /* 089d:3fed inc word ptr [bx + 0x5cec] */
    TR(0x0c9c1); /* 089d:3ff1 cmp word ptr [bx + 0x5cec], 6 */
    TR(0x0c9c6); if (RW(DS_, (uint16_t)(BX + 0x5cec)) != 0x6) goto L0c9ce; /* 089d:3ff6 jne 0xc9ce */
    TR(0x0c9c8); CYC(24); WW(DS_, (uint16_t)(BX + 0x5cec), 0x0); /* 089d:3ff8 mov word ptr [bx + 0x5cec], 0 */
L0c9ce:
    TR(0x0c9ce); CYC(40); /* 089d:3ffe cmp word ptr [bx + 0x5c88], 0 */
    TR(0x0c9d3); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x5c88)) < (int16_t)0x0) goto L0ca0c; /* 089d:4003 jl 0xca0c */
    TR(0x0c9d5); CYC(40); /* 089d:4005 cmp word ptr [bx + 0x5c88], 0x123 */
    TR(0x0c9db); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x5c88)) > (int16_t)0x123) goto L0ca0c; /* 089d:400b jg 0xca0c */
    TR(0x0c9dd); CYC(67); WW(DS_, (uint16_t)(BX + 0x5ee0), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x5ee0)) - 1)); /* 089d:400d dec word ptr [bx + 0x5ee0] */
    TR(0x0c9e1); /* 089d:4011 cmp word ptr [bx + 0x5ee0], 0 */
    TR(0x0c9e6); if (RW(DS_, (uint16_t)(BX + 0x5ee0)) != 0x0) goto L0ca0c; /* 089d:4016 jne 0xca0c */
    TR(0x0c9e8); CYC(168); WW(DS_, (uint16_t)(BX + 0x5ee0), 0x14); /* 089d:4018 mov word ptr [bx + 0x5ee0], 0x14 */
    TR(0x0c9ee); AX = RW(DS_, (uint16_t)(BX + 0x5c88)); /* 089d:401e mov ax, word ptr [bx + 0x5c88] */
    TR(0x0c9f2); WW(DS_, 0x5a76, AX); /* 089d:4022 mov word ptr [0x5a76], ax */
    TR(0x0c9f5); AX = RW(DS_, (uint16_t)(BX + 0x5e7c)); /* 089d:4025 mov ax, word ptr [bx + 0x5e7c] */
    TR(0x0c9f9); AX += 0x9; /* 089d:4029 add ax, 9 */
    TR(0x0c9fc); WW(DS_, 0x5a78, AX); /* 089d:402c mov word ptr [0x5a78], ax */
    TR(0x0c9ff); AX = RW(DS_, (uint16_t)(BX + 0x5e18)); /* 089d:402f mov ax, word ptr [bx + 0x5e18] */
    TR(0x0ca03); WW(DS_, 0x5a7c, AX); /* 089d:4033 mov word ptr [0x5a7c], ax */
    TR(0x0ca06); WW(DS_, 0x5a74, 0x1); /* 089d:4036 mov word ptr [0x5a74], 1 */
L0ca0c:
    TR(0x0ca0c); CYC(23); PUSH(0x403f); goto L0c930; /* 089d:403c call 0xc930 */
L0ca0f:
    TR(0x0ca0f); CYC(45); PUSH(CX); /* 089d:403f push cx */
    TR(0x0ca10); CX = RW(DS_, 0x5062); /* 089d:4040 mov cx, word ptr [0x5062] */
    TR(0x0ca14); SI = 0x0; /* 089d:4044 mov si, 0 */
L0ca17:
    TR(0x0ca17); CYC(40); /* 089d:4047 cmp word ptr [si + 0x501e], 0 */
    TR(0x0ca1c); if (RW(DS_, (uint16_t)(SI + 0x501e)) == 0x0) goto L0ca81; /* 089d:404c je 0xca81 */
    TR(0x0ca1e); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x5c88)); /* 089d:404e mov ax, word ptr [bx + 0x5c88] */
    TR(0x0ca22); /* 089d:4052 cmp word ptr [si + 0x4ff6], ax */
    TR(0x0ca26); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x4ff6)) < (int16_t)AX) goto L0ca81; /* 089d:4056 jl 0xca81 */
    TR(0x0ca28); CYC(52); AX += 0x20; /* 089d:4058 add ax, 0x20 */
    TR(0x0ca2b); /* 089d:405b cmp word ptr [si + 0x4ff6], ax */
    TR(0x0ca2f); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x4ff6)) > (int16_t)AX) goto L0ca81; /* 089d:405f jg 0xca81 */
    TR(0x0ca31); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x5e7c)); /* 089d:4061 mov ax, word ptr [bx + 0x5e7c] */
    TR(0x0ca35); /* 089d:4065 cmp word ptr [si + 0x500a], ax */
    TR(0x0ca39); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) < (int16_t)AX) goto L0ca81; /* 089d:4069 jl 0xca81 */
    TR(0x0ca3b); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x5e7c)); /* 089d:406b mov ax, word ptr [bx + 0x5e7c] */
    TR(0x0ca3f); /* 089d:406f cmp word ptr [si + 0x500a], ax */
    TR(0x0ca43); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) < (int16_t)AX) goto L0ca81; /* 089d:4073 jl 0xca81 */
    TR(0x0ca45); CYC(52); AX += 0x9; /* 089d:4075 add ax, 9 */
    TR(0x0ca48); /* 089d:4078 cmp word ptr [si + 0x500a], ax */
    TR(0x0ca4c); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) > (int16_t)AX) goto L0ca81; /* 089d:407c jg 0xca81 */
    TR(0x0ca4e); CYC(166); WW(DS_, 0x50d6, 0x1); /* 089d:407e mov word ptr [0x50d6], 1 */
    TR(0x0ca54); AX = RW(DS_, (uint16_t)(BX + 0x5c88)); /* 089d:4084 mov ax, word ptr [bx + 0x5c88] */
    TR(0x0ca58); WW(DS_, 0x50d8, AX); /* 089d:4088 mov word ptr [0x50d8], ax */
    TR(0x0ca5b); AX = RW(DS_, (uint16_t)(BX + 0x5e7c)); /* 089d:408b mov ax, word ptr [bx + 0x5e7c] */
    TR(0x0ca5f); WW(DS_, 0x50da, AX); /* 089d:408f mov word ptr [0x50da], ax */
    TR(0x0ca62); WW(DS_, (uint16_t)(SI + 0x501e), 0x0); /* 089d:4092 mov word ptr [si + 0x501e], 0 */
    TR(0x0ca68); PUSH(BX); /* 089d:4098 push bx */
    TR(0x0ca69); BX = SI; /* 089d:4099 mov bx, si */
    TR(0x0ca6b); PUSH(0x409e); goto L0c6c3; /* 089d:409b call 0xc6c3 */
L0ca6e:
    TR(0x0ca6e); CYC(59); BX = POP(); /* 089d:409e pop bx */
    TR(0x0ca6f); WW(DS_, (uint16_t)(BX + 0x5d50), 0x0); /* 089d:409f mov word ptr [bx + 0x5d50], 0 */
    TR(0x0ca75); PUSH(0x40a8); goto L0c930; /* 089d:40a5 call 0xc930 */
L0ca78:
    TR(0x0ca78); CYC(35); AX = 0x14; /* 089d:40a8 mov ax, 0x14 */
    TR(0x0ca7b); PUSH(0x40ae); goto L0b829; /* 089d:40ab call 0xb829 */
L0ca7e:
    TR(0x0ca7e); CYC(15); goto L0ca85; /* 089d:40ae jmp 0xca85 */
L0ca81:
    TR(0x0ca81); CYC(25); SI++; /* 089d:40b1 inc si */
    TR(0x0ca82); SI++; /* 089d:40b2 inc si */
    TR(0x0ca83); if (--CX) goto L0ca17; /* 089d:40b3 loop 0xca17 */
L0ca85:
    TR(0x0ca85); CYC(52); CX = POP(); /* 089d:40b5 pop cx */
    TR(0x0ca86); /* 089d:40b6 cmp word ptr [0x4176], 1 */
    TR(0x0ca8b); if (RW(DS_, 0x4176) != 0x1) goto L0cae7; /* 089d:40bb jne 0xcae7 */
    TR(0x0ca8d); CYC(40); /* 089d:40bd cmp word ptr [bx + 0x5d50], 1 */
    TR(0x0ca92); if (RW(DS_, (uint16_t)(BX + 0x5d50)) != 0x1) goto L0cae7; /* 089d:40c2 jne 0xcae7 */
    TR(0x0ca94); CYC(68); AX = RW(DS_, 0x4170); /* 089d:40c4 mov ax, word ptr [0x4170] */
    TR(0x0ca97); DX = RW(DS_, (uint16_t)(BX + 0x5c88)); /* 089d:40c7 mov dx, word ptr [bx + 0x5c88] */
    TR(0x0ca9b); AX += 0x14; /* 089d:40cb add ax, 0x14 */
    TR(0x0ca9e); /* 089d:40ce cmp ax, dx */
    TR(0x0caa0); if ((int16_t)AX < (int16_t)DX) goto L0cae7; /* 089d:40d0 jl 0xcae7 */
    TR(0x0caa2); CYC(44); AX -= 0x14; /* 089d:40d2 sub ax, 0x14 */
    TR(0x0caa5); DX += 0x20; /* 089d:40d5 add dx, 0x20 */
    TR(0x0caa8); /* 089d:40d8 cmp ax, dx */
    TR(0x0caaa); if ((int16_t)AX > (int16_t)DX) goto L0cae7; /* 089d:40da jg 0xcae7 */
    TR(0x0caac); CYC(68); AX = RW(DS_, 0x4172); /* 089d:40dc mov ax, word ptr [0x4172] */
    TR(0x0caaf); DX = RW(DS_, (uint16_t)(BX + 0x5e7c)); /* 089d:40df mov dx, word ptr [bx + 0x5e7c] */
    TR(0x0cab3); AX += 0xe; /* 089d:40e3 add ax, 0xe */
    TR(0x0cab6); /* 089d:40e6 cmp ax, dx */
    TR(0x0cab8); if ((int16_t)AX < (int16_t)DX) goto L0cae7; /* 089d:40e8 jl 0xcae7 */
    TR(0x0caba); CYC(44); AX -= 0xe; /* 089d:40ea sub ax, 0xe */
    TR(0x0cabd); DX += 0x9; /* 089d:40ed add dx, 9 */
    TR(0x0cac0); /* 089d:40f0 cmp ax, dx */
    TR(0x0cac2); if ((int16_t)AX > (int16_t)DX) goto L0cae7; /* 089d:40f2 jg 0xcae7 */
    TR(0x0cac4); CYC(167); WW(DS_, 0x5360, 0x1); /* 089d:40f4 mov word ptr [0x5360], 1 */
    TR(0x0caca); WW(DS_, 0x50d6, 0x1); /* 089d:40fa mov word ptr [0x50d6], 1 */
    TR(0x0cad0); AX = RW(DS_, (uint16_t)(BX + 0x5c88)); /* 089d:4100 mov ax, word ptr [bx + 0x5c88] */
    TR(0x0cad4); WW(DS_, 0x50d8, AX); /* 089d:4104 mov word ptr [0x50d8], ax */
    TR(0x0cad7); AX = RW(DS_, (uint16_t)(BX + 0x5e7c)); /* 089d:4107 mov ax, word ptr [bx + 0x5e7c] */
    TR(0x0cadb); WW(DS_, 0x50da, AX); /* 089d:410b mov word ptr [0x50da], ax */
    TR(0x0cade); WW(DS_, (uint16_t)(BX + 0x5d50), 0x0); /* 089d:410e mov word ptr [bx + 0x5d50], 0 */
    TR(0x0cae4); PUSH(0x4117); goto L0c930; /* 089d:4114 call 0xc930 */
L0cae7:
    TR(0x0cae7); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:4117 ret  */

/* ---- f_089d_4118 */
L0cae8:
    TR(0x0cae8); CYC(40); /* 089d:4118 cmp word ptr [bx + 0x5f48], 0x113 */
    TR(0x0caee); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x5f48)) > (int16_t)0x113) goto L0cb36; /* 089d:411e jg 0xcb36 */
    TR(0x0caf0); CYC(40); /* 089d:4120 cmp word ptr [bx + 0x5f48], 0 */
    TR(0x0caf5); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x5f48)) < (int16_t)0x0) goto L0cb36; /* 089d:4125 jl 0xcb36 */
    TR(0x0caf7); CYC(340); PUSH(BX); /* 089d:4127 push bx */
    TR(0x0caf8); PUSH(CX); /* 089d:4128 push cx */
    TR(0x0caf9); PUSH(DX); /* 089d:4129 push dx */
    TR(0x0cafa); PUSH(SI); /* 089d:412a push si */
    TR(0x0cafb); PUSH(DI); /* 089d:412b push di */
    TR(0x0cafc); AX = 0x0; /* 089d:412c mov ax, 0 */
    TR(0x0caff); AX += AX; /* 089d:412f add ax, ax */
    TR(0x0cb01); DI = AX; /* 089d:4131 mov di, ax */
    TR(0x0cb03); SI = RW(DS_, (uint16_t)(DI + 0x82f3)); /* 089d:4133 mov si, word ptr [di - 0x7d0d] */
    TR(0x0cb07); DL = RB(DS_, SI); /* 089d:4137 mov dl, byte ptr [si] */
    TR(0x0cb09); DH = DL; /* 089d:4139 mov dh, dl */
    TR(0x0cb0b); SI++; /* 089d:413b inc si */
    TR(0x0cb0c); CH = RB(DS_, SI); /* 089d:413c mov ch, byte ptr [si] */
    TR(0x0cb0e); SI++; /* 089d:413e inc si */
    TR(0x0cb0f); WW(DS_, 0x36, SI); /* 089d:413f mov word ptr [0x36], si */
    TR(0x0cb13); AX = RW(DS_, (uint16_t)(BX + 0x5fac)); /* 089d:4143 mov ax, word ptr [bx + 0x5fac] */
    TR(0x0cb17); WW(DS_, 0x2e, AX); /* 089d:4147 mov word ptr [0x2e], ax */
    TR(0x0cb1a); BX = RW(DS_, (uint16_t)(BX + 0x5f48)); /* 089d:414a mov bx, word ptr [bx + 0x5f48] */
    TR(0x0cb1e); AX = RW(DS_, (uint16_t)(BX + 0x680e)); /* 089d:414e mov ax, word ptr [bx + 0x680e] */
    TR(0x0cb22); AH = 0x0; /* 089d:4152 mov ah, 0 */
    TR(0x0cb24); WW(DS_, 0x2c, AX); /* 089d:4154 mov word ptr [0x2c], ax */
    TR(0x0cb27); AX = RW(DS_, (uint16_t)(BX + 0x695c)); /* 089d:4157 mov ax, word ptr [bx + 0x695c] */
    TR(0x0cb2b); WW(DS_, 0x3a, AX); /* 089d:415b mov word ptr [0x3a], ax */
    TR(0x0cb2e); PUSH(0x4161); goto L0ae25; /* 089d:415e call 0xae25 */
L0cb31:
    TR(0x0cb31); CYC(60); DI = POP(); /* 089d:4161 pop di */
    TR(0x0cb32); SI = POP(); /* 089d:4162 pop si */
    TR(0x0cb33); DX = POP(); /* 089d:4163 pop dx */
    TR(0x0cb34); CX = POP(); /* 089d:4164 pop cx */
    TR(0x0cb35); BX = POP(); /* 089d:4165 pop bx */
L0cb36:
    TR(0x0cb36); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:4166 ret  */

/* ---- f_089d_4167 */
L0cb37:
    TR(0x0cb37); CYC(40); /* 089d:4167 cmp word ptr [0x5fea], 1 */
    TR(0x0cb3c); if (RW(DS_, 0x5fea) == 0x1) goto L0cb3f; /* 089d:416c je 0xcb3f */
    TR(0x0cb3e); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:416e ret  */
L0cb3f:
    TR(0x0cb3f); CYC(30); CX = RW(DS_, 0x5fe8); /* 089d:416f mov cx, word ptr [0x5fe8] */
    TR(0x0cb43); BX = 0x0; /* 089d:4173 mov bx, 0 */
L0cb46:
    TR(0x0cb46); CYC(40); /* 089d:4176 cmp word ptr [bx + 0x5f70], 0 */
    TR(0x0cb4b); if (RW(DS_, (uint16_t)(BX + 0x5f70)) == 0x0) goto L0cb50; /* 089d:417b je 0xcb50 */
    TR(0x0cb4d); CYC(23); PUSH(0x4180); goto L0cb55; /* 089d:417d call 0xcb55 */
L0cb50:
    TR(0x0cb50); CYC(25); BX++; /* 089d:4180 inc bx */
    TR(0x0cb51); BX++; /* 089d:4181 inc bx */
    TR(0x0cb52); if (--CX) goto L0cb46; /* 089d:4182 loop 0xcb46 */
    TR(0x0cb54); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:4184 ret  */

/* ---- f_089d_4185 */
L0cb55:
    TR(0x0cb55); CYC(23); PUSH(0x4188); goto L0cae8; /* 089d:4185 call 0xcae8 */
L0cb58:
    TR(0x0cb58); CYC(111); AX = RW(DS_, 0x4a); /* 089d:4188 mov ax, word ptr [0x4a] */
    TR(0x0cb5b); AX = (uint16_t)(0u - AX); /* 089d:418b neg ax */
    TR(0x0cb5d); AX += RW(DS_, (uint16_t)(BX + 0x5f98)); /* 089d:418d add ax, word ptr [bx + 0x5f98] */
    TR(0x0cb61); WW(DS_, (uint16_t)(BX + 0x5f48), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x5f48)) + AX)); /* 089d:4191 add word ptr [bx + 0x5f48], ax */
    TR(0x0cb65); /* 089d:4195 cmp word ptr [bx + 0x5f48], 0x18ec */
    TR(0x0cb6b); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x5f48)) < (int16_t)0x18ec) goto L0cb73; /* 089d:419b jl 0xcb73 */
    TR(0x0cb6d); CYC(24); WW(DS_, (uint16_t)(BX + 0x5f48), 0x0); /* 089d:419d mov word ptr [bx + 0x5f48], 0 */
L0cb73:
    TR(0x0cb73); CYC(23); PUSH(0x41a6); goto L0cae8; /* 089d:41a3 call 0xcae8 */
L0cb76:
    TR(0x0cb76); CYC(40); /* 089d:41a6 cmp word ptr [bx + 0x5f48], 0 */
    TR(0x0cb7b); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x5f48)) < (int16_t)0x0) goto L0cbc8; /* 089d:41ab jl 0xcbc8 */
    TR(0x0cb7d); CYC(40); /* 089d:41ad cmp word ptr [bx + 0x5f48], 0x113 */
    TR(0x0cb83); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x5f48)) > (int16_t)0x113) goto L0cbc8; /* 089d:41b3 jg 0xcbc8 */
    TR(0x0cb85); CYC(67); WW(DS_, (uint16_t)(BX + 0x5fc0), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x5fc0)) - 1)); /* 089d:41b5 dec word ptr [bx + 0x5fc0] */
    TR(0x0cb89); /* 089d:41b9 cmp word ptr [bx + 0x5fc0], 0 */
    TR(0x0cb8e); if (RW(DS_, (uint16_t)(BX + 0x5fc0)) != 0x0) goto L0cbc8; /* 089d:41be jne 0xcbc8 */
    TR(0x0cb90); CYC(180); WW(DS_, (uint16_t)(BX + 0x5fc0), 0x14); /* 089d:41c0 mov word ptr [bx + 0x5fc0], 0x14 */
    TR(0x0cb96); AX = RW(DS_, (uint16_t)(BX + 0x5f48)); /* 089d:41c6 mov ax, word ptr [bx + 0x5f48] */
    TR(0x0cb9a); AX += 0x19; /* 089d:41ca add ax, 0x19 */
    TR(0x0cb9d); WW(DS_, 0x5a76, AX); /* 089d:41cd mov word ptr [0x5a76], ax */
    TR(0x0cba0); AX = RW(DS_, (uint16_t)(BX + 0x5fac)); /* 089d:41d0 mov ax, word ptr [bx + 0x5fac] */
    TR(0x0cba4); AX += 0xe; /* 089d:41d4 add ax, 0xe */
    TR(0x0cba7); WW(DS_, 0x5a78, AX); /* 089d:41d7 mov word ptr [0x5a78], ax */
    TR(0x0cbaa); AX = RW(DS_, (uint16_t)(BX + 0x5f98)); /* 089d:41da mov ax, word ptr [bx + 0x5f98] */
    TR(0x0cbae); WW(DS_, 0x5a7c, AX); /* 089d:41de mov word ptr [0x5a7c], ax */
    TR(0x0cbb1); WW(DS_, 0x5a74, 0x1); /* 089d:41e1 mov word ptr [0x5a74], 1 */
L0cbb7:
    TR(0x0cbb7); CYC(23); PUSH(0x41ea); goto L0b412; /* 089d:41e7 call 0xb412 */
L0cbba:
    TR(0x0cbba); CYC(20); /* 089d:41ea cmp al, 0 */
    TR(0x0cbbc); if (AL == 0x0) goto L0cbb7; /* 089d:41ec je 0xcbb7 */
    TR(0x0cbbe); CYC(20); /* 089d:41ee cmp al, 0xa */
    TR(0x0cbc0); if (AL >= 0xa) goto L0cbb7; /* 089d:41f0 jae 0xcbb7 */
    TR(0x0cbc2); CYC(26); AH = 0x0; /* 089d:41f2 mov ah, 0 */
    TR(0x0cbc4); WW(DS_, (uint16_t)(BX + 0x5fc0), AX); /* 089d:41f4 mov word ptr [bx + 0x5fc0], ax */
L0cbc8:
    TR(0x0cbc8); CYC(67); WW(DS_, (uint16_t)(BX + 0x5fd4), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x5fd4)) - 1)); /* 089d:41f8 dec word ptr [bx + 0x5fd4] */
    TR(0x0cbcc); /* 089d:41fc cmp word ptr [bx + 0x5fd4], 0 */
    TR(0x0cbd1); if (RW(DS_, (uint16_t)(BX + 0x5fd4)) != 0x0) goto L0cbf7; /* 089d:4201 jne 0xcbf7 */
L0cbd3:
    TR(0x0cbd3); CYC(23); PUSH(0x4206); goto L0b412; /* 089d:4203 call 0xb412 */
L0cbd6:
    TR(0x0cbd6); CYC(20); /* 089d:4206 cmp al, 0 */
    TR(0x0cbd8); if (AL == 0x0) goto L0cbd3; /* 089d:4208 je 0xcbd3 */
    TR(0x0cbda); CYC(134); AH = 0x0; /* 089d:420a mov ah, 0 */
    TR(0x0cbdc); WW(DS_, (uint16_t)(BX + 0x5fd4), AX); /* 089d:420c mov word ptr [bx + 0x5fd4], ax */
    TR(0x0cbe0); AX = RW(DS_, (uint16_t)(BX + 0x5f48)); /* 089d:4210 mov ax, word ptr [bx + 0x5f48] */
    TR(0x0cbe4); WW(DS_, 0x6194, AX); /* 089d:4214 mov word ptr [0x6194], ax */
    TR(0x0cbe7); AX = RW(DS_, (uint16_t)(BX + 0x5fac)); /* 089d:4217 mov ax, word ptr [bx + 0x5fac] */
    TR(0x0cbeb); AX += 0xe; /* 089d:421b add ax, 0xe */
    TR(0x0cbee); WW(DS_, 0x6196, AX); /* 089d:421e mov word ptr [0x6196], ax */
    TR(0x0cbf1); WW(DS_, 0x6192, 0x1); /* 089d:4221 mov word ptr [0x6192], 1 */
L0cbf7:
    TR(0x0cbf7); CYC(45); PUSH(CX); /* 089d:4227 push cx */
    TR(0x0cbf8); CX = RW(DS_, 0x5062); /* 089d:4228 mov cx, word ptr [0x5062] */
    TR(0x0cbfc); SI = 0x0; /* 089d:422c mov si, 0 */
L0cbff:
    TR(0x0cbff); CYC(40); /* 089d:422f cmp word ptr [si + 0x501e], 0 */
    TR(0x0cc04); if (RW(DS_, (uint16_t)(SI + 0x501e)) == 0x0) goto L0cc69; /* 089d:4234 je 0xcc69 */
    TR(0x0cc06); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x5f48)); /* 089d:4236 mov ax, word ptr [bx + 0x5f48] */
    TR(0x0cc0a); /* 089d:423a cmp word ptr [si + 0x4ff6], ax */
    TR(0x0cc0e); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x4ff6)) < (int16_t)AX) goto L0cc69; /* 089d:423e jl 0xcc69 */
    TR(0x0cc10); CYC(52); AX += 0x2c; /* 089d:4240 add ax, 0x2c */
    TR(0x0cc13); /* 089d:4243 cmp word ptr [si + 0x4ff6], ax */
    TR(0x0cc17); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x4ff6)) > (int16_t)AX) goto L0cc69; /* 089d:4247 jg 0xcc69 */
    TR(0x0cc19); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x5fac)); /* 089d:4249 mov ax, word ptr [bx + 0x5fac] */
    TR(0x0cc1d); /* 089d:424d cmp word ptr [si + 0x500a], ax */
    TR(0x0cc21); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) < (int16_t)AX) goto L0cc69; /* 089d:4251 jl 0xcc69 */
    TR(0x0cc23); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x5fac)); /* 089d:4253 mov ax, word ptr [bx + 0x5fac] */
    TR(0x0cc27); /* 089d:4257 cmp word ptr [si + 0x500a], ax */
    TR(0x0cc2b); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) < (int16_t)AX) goto L0cc69; /* 089d:425b jl 0xcc69 */
    TR(0x0cc2d); CYC(52); AX += 0xe; /* 089d:425d add ax, 0xe */
    TR(0x0cc30); /* 089d:4260 cmp word ptr [si + 0x500a], ax */
    TR(0x0cc34); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) > (int16_t)AX) goto L0cc69; /* 089d:4264 jg 0xcc69 */
    TR(0x0cc36); CYC(166); WW(DS_, 0x50d6, 0x1); /* 089d:4266 mov word ptr [0x50d6], 1 */
    TR(0x0cc3c); AX = RW(DS_, (uint16_t)(BX + 0x5f48)); /* 089d:426c mov ax, word ptr [bx + 0x5f48] */
    TR(0x0cc40); WW(DS_, 0x50d8, AX); /* 089d:4270 mov word ptr [0x50d8], ax */
    TR(0x0cc43); AX = RW(DS_, (uint16_t)(BX + 0x5fac)); /* 089d:4273 mov ax, word ptr [bx + 0x5fac] */
    TR(0x0cc47); WW(DS_, 0x50da, AX); /* 089d:4277 mov word ptr [0x50da], ax */
    TR(0x0cc4a); WW(DS_, (uint16_t)(SI + 0x501e), 0x0); /* 089d:427a mov word ptr [si + 0x501e], 0 */
    TR(0x0cc50); PUSH(BX); /* 089d:4280 push bx */
    TR(0x0cc51); BX = SI; /* 089d:4281 mov bx, si */
    TR(0x0cc53); PUSH(0x4286); goto L0c6c3; /* 089d:4283 call 0xc6c3 */
L0cc56:
    TR(0x0cc56); CYC(59); BX = POP(); /* 089d:4286 pop bx */
    TR(0x0cc57); WW(DS_, (uint16_t)(BX + 0x5f70), 0x0); /* 089d:4287 mov word ptr [bx + 0x5f70], 0 */
    TR(0x0cc5d); PUSH(0x4290); goto L0cae8; /* 089d:428d call 0xcae8 */
L0cc60:
    TR(0x0cc60); CYC(35); AX = 0x14; /* 089d:4290 mov ax, 0x14 */
    TR(0x0cc63); PUSH(0x4296); goto L0b829; /* 089d:4293 call 0xb829 */
L0cc66:
    TR(0x0cc66); CYC(15); goto L0cc6d; /* 089d:4296 jmp 0xcc6d */
L0cc69:
    TR(0x0cc69); CYC(25); SI++; /* 089d:4299 inc si */
    TR(0x0cc6a); SI++; /* 089d:429a inc si */
    TR(0x0cc6b); if (--CX) goto L0cbff; /* 089d:429b loop 0xcbff */
L0cc6d:
    TR(0x0cc6d); CYC(52); CX = POP(); /* 089d:429d pop cx */
    TR(0x0cc6e); /* 089d:429e cmp word ptr [0x4176], 1 */
    TR(0x0cc73); if (RW(DS_, 0x4176) != 0x1) goto L0cccf; /* 089d:42a3 jne 0xcccf */
    TR(0x0cc75); CYC(40); /* 089d:42a5 cmp word ptr [bx + 0x5f70], 1 */
    TR(0x0cc7a); if (RW(DS_, (uint16_t)(BX + 0x5f70)) != 0x1) goto L0cccf; /* 089d:42aa jne 0xcccf */
    TR(0x0cc7c); CYC(68); AX = RW(DS_, 0x4170); /* 089d:42ac mov ax, word ptr [0x4170] */
    TR(0x0cc7f); DX = RW(DS_, (uint16_t)(BX + 0x5f48)); /* 089d:42af mov dx, word ptr [bx + 0x5f48] */
    TR(0x0cc83); AX += 0x14; /* 089d:42b3 add ax, 0x14 */
    TR(0x0cc86); /* 089d:42b6 cmp ax, dx */
    TR(0x0cc88); if ((int16_t)AX < (int16_t)DX) goto L0cccf; /* 089d:42b8 jl 0xcccf */
    TR(0x0cc8a); CYC(44); AX -= 0x14; /* 089d:42ba sub ax, 0x14 */
    TR(0x0cc8d); DX += 0x20; /* 089d:42bd add dx, 0x20 */
    TR(0x0cc90); /* 089d:42c0 cmp ax, dx */
    TR(0x0cc92); if ((int16_t)AX > (int16_t)DX) goto L0cccf; /* 089d:42c2 jg 0xcccf */
    TR(0x0cc94); CYC(68); AX = RW(DS_, 0x4172); /* 089d:42c4 mov ax, word ptr [0x4172] */
    TR(0x0cc97); DX = RW(DS_, (uint16_t)(BX + 0x5fac)); /* 089d:42c7 mov dx, word ptr [bx + 0x5fac] */
    TR(0x0cc9b); AX += 0xe; /* 089d:42cb add ax, 0xe */
    TR(0x0cc9e); /* 089d:42ce cmp ax, dx */
    TR(0x0cca0); if ((int16_t)AX < (int16_t)DX) goto L0cccf; /* 089d:42d0 jl 0xcccf */
    TR(0x0cca2); CYC(44); AX -= 0xe; /* 089d:42d2 sub ax, 0xe */
    TR(0x0cca5); DX += 0x9; /* 089d:42d5 add dx, 9 */
    TR(0x0cca8); /* 089d:42d8 cmp ax, dx */
    TR(0x0ccaa); if ((int16_t)AX > (int16_t)DX) goto L0cccf; /* 089d:42da jg 0xcccf */
    TR(0x0ccac); CYC(167); WW(DS_, 0x5360, 0x1); /* 089d:42dc mov word ptr [0x5360], 1 */
    TR(0x0ccb2); WW(DS_, 0x50d6, 0x1); /* 089d:42e2 mov word ptr [0x50d6], 1 */
    TR(0x0ccb8); AX = RW(DS_, (uint16_t)(BX + 0x5f48)); /* 089d:42e8 mov ax, word ptr [bx + 0x5f48] */
    TR(0x0ccbc); WW(DS_, 0x50d8, AX); /* 089d:42ec mov word ptr [0x50d8], ax */
    TR(0x0ccbf); AX = RW(DS_, (uint16_t)(BX + 0x5fac)); /* 089d:42ef mov ax, word ptr [bx + 0x5fac] */
    TR(0x0ccc3); WW(DS_, 0x50da, AX); /* 089d:42f3 mov word ptr [0x50da], ax */
    TR(0x0ccc6); WW(DS_, (uint16_t)(BX + 0x5f70), 0x0); /* 089d:42f6 mov word ptr [bx + 0x5f70], 0 */
    TR(0x0cccc); PUSH(0x42ff); goto L0cae8; /* 089d:42fc call 0xcae8 */
L0cccf:
    TR(0x0cccf); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:42ff ret  */

/* ---- f_089d_4300 */
L0ccd0:
    TR(0x0ccd0); CYC(40); /* 089d:4300 cmp word ptr [0x6190], 1 */
    TR(0x0ccd5); if (RW(DS_, 0x6190) == 0x1) goto L0ccd8; /* 089d:4305 je 0xccd8 */
    TR(0x0ccd7); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:4307 ret  */
L0ccd8:
    TR(0x0ccd8); CYC(30); CX = RW(DS_, 0x619c); /* 089d:4308 mov cx, word ptr [0x619c] */
    TR(0x0ccdc); BX = 0x0; /* 089d:430c mov bx, 0 */
L0ccdf:
    TR(0x0ccdf); CYC(40); /* 089d:430f cmp word ptr [bx + 0x6064], 0 */
    TR(0x0cce4); if (RW(DS_, (uint16_t)(BX + 0x6064)) == 0x0) goto L0ccec; /* 089d:4314 je 0xccec */
    TR(0x0cce6); CYC(23); PUSH(0x4319); goto L0cd38; /* 089d:4316 call 0xcd38 */
L0cce9:
    TR(0x0cce9); CYC(15); goto L0cd2d; /* 089d:4319 jmp 0xcd2d */
L0ccec:
    TR(0x0ccec); CYC(40); /* 089d:431c cmp word ptr [0x6192], 0 */
    TR(0x0ccf1); if (RW(DS_, 0x6192) == 0x0) goto L0cd2d; /* 089d:4321 je 0xcd2d */
    TR(0x0ccf3); CYC(179); WW(DS_, 0x6192, 0x0); /* 089d:4323 mov word ptr [0x6192], 0 */
    TR(0x0ccf9); WW(DS_, (uint16_t)(BX + 0x6064), 0x1); /* 089d:4329 mov word ptr [bx + 0x6064], 1 */
    TR(0x0ccff); AX = RW(DS_, 0x6194); /* 089d:432f mov ax, word ptr [0x6194] */
    TR(0x0cd02); WW(DS_, (uint16_t)(BX + 0x5fec), AX); /* 089d:4332 mov word ptr [bx + 0x5fec], ax */
    TR(0x0cd06); AX = RW(DS_, 0x6196); /* 089d:4336 mov ax, word ptr [0x6196] */
    TR(0x0cd09); WW(DS_, (uint16_t)(BX + 0x6028), AX); /* 089d:4339 mov word ptr [bx + 0x6028], ax */
    TR(0x0cd0d); WW(DS_, (uint16_t)(BX + 0x60dc), 0x1); /* 089d:433d mov word ptr [bx + 0x60dc], 1 */
    TR(0x0cd13); DX = 0xffff; /* 089d:4343 mov dx, 0xffff */
    TR(0x0cd16); PUSH(0x4349); goto L0b412; /* 089d:4346 call 0xb412 */
L0cd19:
    TR(0x0cd19); CYC(20); /* 089d:4349 cmp al, 0x80 */
    TR(0x0cd1b); if (AL >= 0x80) goto L0cd20; /* 089d:434b jae 0xcd20 */
    TR(0x0cd1d); CYC(12); DX = 0x1; /* 089d:434d mov dx, 1 */
L0cd20:
    TR(0x0cd20); CYC(65); WW(DS_, (uint16_t)(BX + 0x60a0), DX); /* 089d:4350 mov word ptr [bx + 0x60a0], dx */
    TR(0x0cd24); WW(DS_, (uint16_t)(BX + 0x6118), 0xd); /* 089d:4354 mov word ptr [bx + 0x6118], 0xd */
    TR(0x0cd2a); PUSH(0x435d); goto L0ceb2; /* 089d:435a call 0xceb2 */
L0cd2d:
    TR(0x0cd2d); CYC(25); BX++; /* 089d:435d inc bx */
    TR(0x0cd2e); BX++; /* 089d:435e inc bx */
    TR(0x0cd2f); if (--CX) goto L0ccdf; /* 089d:435f loop 0xccdf */
    TR(0x0cd31); CYC(44); WW(DS_, 0x6192, 0x0); /* 089d:4361 mov word ptr [0x6192], 0 */
    TR(0x0cd37); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:4367 ret  */

/* ---- f_089d_4368 */
L0cd38:
    TR(0x0cd38); CYC(23); PUSH(0x436b); goto L0ceb2; /* 089d:4368 call 0xceb2 */
L0cd3b:
    TR(0x0cd3b); CYC(67); WW(DS_, (uint16_t)(BX + 0x6154), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x6154)) + 1)); /* 089d:436b inc word ptr [bx + 0x6154] */
    TR(0x0cd3f); /* 089d:436f cmp word ptr [bx + 0x6154], 6 */
    TR(0x0cd44); if (RW(DS_, (uint16_t)(BX + 0x6154)) != 0x6) goto L0cd4c; /* 089d:4374 jne 0xcd4c */
    TR(0x0cd46); CYC(24); WW(DS_, (uint16_t)(BX + 0x6154), 0x0); /* 089d:4376 mov word ptr [bx + 0x6154], 0 */
L0cd4c:
    TR(0x0cd4c); CYC(76); AX = RW(DS_, (uint16_t)(BX + 0x6154)); /* 089d:437c mov ax, word ptr [bx + 0x6154] */
    TR(0x0cd50); WW(DS_, (uint16_t)(BX + 0x6118), AX); /* 089d:4380 mov word ptr [bx + 0x6118], ax */
    TR(0x0cd54); /* 089d:4384 cmp word ptr [bx + 0x60a0], 0 */
    TR(0x0cd59); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x60a0)) >= (int16_t)0x0) goto L0cd60; /* 089d:4389 jge 0xcd60 */
    TR(0x0cd5b); CYC(28); WW(DS_, (uint16_t)(BX + 0x6118), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x6118)) + 0x6)); /* 089d:438b add word ptr [bx + 0x6118], 6 */
L0cd60:
    TR(0x0cd60); CYC(40); /* 089d:4390 cmp word ptr [bx + 0x6028], 0xac */
    TR(0x0cd66); if (RW(DS_, (uint16_t)(BX + 0x6028)) == 0xac) goto L0cd6e; /* 089d:4396 je 0xcd6e */
    TR(0x0cd68); CYC(24); WW(DS_, (uint16_t)(BX + 0x6118), 0xd); /* 089d:4398 mov word ptr [bx + 0x6118], 0xd */
L0cd6e:
    TR(0x0cd6e); CYC(157); AX = RW(DS_, 0x4a); /* 089d:439e mov ax, word ptr [0x4a] */
    TR(0x0cd71); AX = (uint16_t)(0u - AX); /* 089d:43a1 neg ax */
    TR(0x0cd73); AX += RW(DS_, (uint16_t)(BX + 0x60a0)); /* 089d:43a3 add ax, word ptr [bx + 0x60a0] */
    TR(0x0cd77); WW(DS_, (uint16_t)(BX + 0x5fec), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x5fec)) + AX)); /* 089d:43a7 add word ptr [bx + 0x5fec], ax */
    TR(0x0cd7b); AX = RW(DS_, (uint16_t)(BX + 0x60dc)); /* 089d:43ab mov ax, word ptr [bx + 0x60dc] */
    TR(0x0cd7f); WW(DS_, (uint16_t)(BX + 0x6028), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x6028)) + AX)); /* 089d:43af add word ptr [bx + 0x6028], ax */
    TR(0x0cd83); /* 089d:43b3 cmp word ptr [bx + 0x6028], 0xac */
    TR(0x0cd89); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x6028)) < (int16_t)0xac) goto L0cd91; /* 089d:43b9 jl 0xcd91 */
    TR(0x0cd8b); CYC(24); WW(DS_, (uint16_t)(BX + 0x60dc), 0x0); /* 089d:43bb mov word ptr [bx + 0x60dc], 0 */
L0cd91:
    TR(0x0cd91); CYC(40); /* 089d:43c1 cmp word ptr [bx + 0x5fec], 0 */
    TR(0x0cd96); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x5fec)) >= (int16_t)0x0) goto L0cd9e; /* 089d:43c6 jge 0xcd9e */
    TR(0x0cd98); CYC(24); WW(DS_, (uint16_t)(BX + 0x5fec), 0x18eb); /* 089d:43c8 mov word ptr [bx + 0x5fec], 0x18eb */
L0cd9e:
    TR(0x0cd9e); CYC(40); /* 089d:43ce cmp word ptr [bx + 0x5fec], 0x18ec */
    TR(0x0cda4); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x5fec)) < (int16_t)0x18ec) goto L0cdac; /* 089d:43d4 jl 0xcdac */
    TR(0x0cda6); CYC(24); WW(DS_, (uint16_t)(BX + 0x5fec), 0x0); /* 089d:43d6 mov word ptr [bx + 0x5fec], 0 */
L0cdac:
    TR(0x0cdac); CYC(40); /* 089d:43dc cmp word ptr [bx + 0x5fec], 0 */
    TR(0x0cdb1); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x5fec)) < (int16_t)0x0) goto L0cde2; /* 089d:43e1 jl 0xcde2 */
    TR(0x0cdb3); CYC(40); /* 089d:43e3 cmp word ptr [bx + 0x5fec], 0x137 */
    TR(0x0cdb9); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x5fec)) > (int16_t)0x137) goto L0cde2; /* 089d:43e9 jg 0xcde2 */
    TR(0x0cdbb); CYC(82); WW(DS_, (uint16_t)(BX + 0x60a0), 0x1); /* 089d:43eb mov word ptr [bx + 0x60a0], 1 */
    TR(0x0cdc1); AX = RW(DS_, 0x4170); /* 089d:43f1 mov ax, word ptr [0x4170] */
    TR(0x0cdc4); /* 089d:43f4 cmp word ptr [bx + 0x5fec], ax */
    TR(0x0cdc8); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x5fec)) < (int16_t)AX) goto L0cdd0; /* 089d:43f8 jl 0xcdd0 */
    TR(0x0cdca); CYC(24); WW(DS_, (uint16_t)(BX + 0x60a0), 0xffff); /* 089d:43fa mov word ptr [bx + 0x60a0], 0xffff */
L0cdd0:
    TR(0x0cdd0); CYC(40); /* 089d:4400 cmp word ptr [bx + 0x5fec], ax */
    TR(0x0cdd4); if (RW(DS_, (uint16_t)(BX + 0x5fec)) != AX) goto L0cde2; /* 089d:4404 jne 0xcde2 */
    TR(0x0cdd6); CYC(48); WW(DS_, (uint16_t)(BX + 0x60a0), 0x0); /* 089d:4406 mov word ptr [bx + 0x60a0], 0 */
    TR(0x0cddc); WW(DS_, (uint16_t)(BX + 0x6118), 0xf); /* 089d:440c mov word ptr [bx + 0x6118], 0xf */
L0cde2:
    TR(0x0cde2); CYC(23); PUSH(0x4415); goto L0ceb2; /* 089d:4412 call 0xceb2 */
L0cde5:
    TR(0x0cde5); CYC(40); /* 089d:4415 cmp word ptr [0x4176], 1 */
    TR(0x0cdea); if (RW(DS_, 0x4176) != 0x1) goto L0ce29; /* 089d:441a jne 0xce29 */
    TR(0x0cdec); CYC(40); /* 089d:441c cmp word ptr [bx + 0x6064], 1 */
    TR(0x0cdf1); if (RW(DS_, (uint16_t)(BX + 0x6064)) != 0x1) goto L0ce29; /* 089d:4421 jne 0xce29 */
    TR(0x0cdf3); CYC(68); AX = RW(DS_, 0x4170); /* 089d:4423 mov ax, word ptr [0x4170] */
    TR(0x0cdf6); DX = RW(DS_, (uint16_t)(BX + 0x5fec)); /* 089d:4426 mov dx, word ptr [bx + 0x5fec] */
    TR(0x0cdfa); AX += 0x14; /* 089d:442a add ax, 0x14 */
    TR(0x0cdfd); /* 089d:442d cmp ax, dx */
    TR(0x0cdff); if ((int16_t)AX < (int16_t)DX) goto L0ce29; /* 089d:442f jl 0xce29 */
    TR(0x0ce01); CYC(44); AX -= 0x14; /* 089d:4431 sub ax, 0x14 */
    TR(0x0ce04); DX += 0x8; /* 089d:4434 add dx, 8 */
    TR(0x0ce07); /* 089d:4437 cmp ax, dx */
    TR(0x0ce09); if ((int16_t)AX > (int16_t)DX) goto L0ce29; /* 089d:4439 jg 0xce29 */
    TR(0x0ce0b); CYC(68); AX = RW(DS_, 0x4172); /* 089d:443b mov ax, word ptr [0x4172] */
    TR(0x0ce0e); DX = RW(DS_, (uint16_t)(BX + 0x6028)); /* 089d:443e mov dx, word ptr [bx + 0x6028] */
    TR(0x0ce12); AX += 0xe; /* 089d:4442 add ax, 0xe */
    TR(0x0ce15); /* 089d:4445 cmp ax, dx */
    TR(0x0ce17); if ((int16_t)AX < (int16_t)DX) goto L0ce29; /* 089d:4447 jl 0xce29 */
    TR(0x0ce19); CYC(44); AX -= 0xe; /* 089d:4449 sub ax, 0xe */
    TR(0x0ce1c); DX += 0x8; /* 089d:444c add dx, 8 */
    TR(0x0ce1f); /* 089d:444f cmp ax, dx */
    TR(0x0ce21); if ((int16_t)AX > (int16_t)DX) goto L0ce29; /* 089d:4451 jg 0xce29 */
    TR(0x0ce23); CYC(24); WW(DS_, 0x5360, 0x1); /* 089d:4453 mov word ptr [0x5360], 1 */
L0ce29:
    TR(0x0ce29); CYC(45); PUSH(CX); /* 089d:4459 push cx */
    TR(0x0ce2a); CX = RW(DS_, 0x5062); /* 089d:445a mov cx, word ptr [0x5062] */
    TR(0x0ce2e); SI = 0x0; /* 089d:445e mov si, 0 */
L0ce31:
    TR(0x0ce31); CYC(40); /* 089d:4461 cmp word ptr [si + 0x501e], 0 */
    TR(0x0ce36); if (RW(DS_, (uint16_t)(SI + 0x501e)) == 0x0) goto L0ceac; /* 089d:4466 je 0xceac */
    TR(0x0ce38); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x5fec)); /* 089d:4468 mov ax, word ptr [bx + 0x5fec] */
    TR(0x0ce3c); /* 089d:446c cmp word ptr [si + 0x4ff6], ax */
    TR(0x0ce40); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x4ff6)) < (int16_t)AX) goto L0ceac; /* 089d:4470 jl 0xceac */
    TR(0x0ce42); CYC(52); AX += 0x8; /* 089d:4472 add ax, 8 */
    TR(0x0ce45); /* 089d:4475 cmp word ptr [si + 0x4ff6], ax */
    TR(0x0ce49); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x4ff6)) > (int16_t)AX) goto L0ceac; /* 089d:4479 jg 0xceac */
    TR(0x0ce4b); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x6028)); /* 089d:447b mov ax, word ptr [bx + 0x6028] */
    TR(0x0ce4f); /* 089d:447f cmp word ptr [si + 0x500a], ax */
    TR(0x0ce53); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) < (int16_t)AX) goto L0ceac; /* 089d:4483 jl 0xceac */
    TR(0x0ce55); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x6028)); /* 089d:4485 mov ax, word ptr [bx + 0x6028] */
    TR(0x0ce59); /* 089d:4489 cmp word ptr [si + 0x500a], ax */
    TR(0x0ce5d); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) < (int16_t)AX) goto L0ceac; /* 089d:448d jl 0xceac */
    TR(0x0ce5f); CYC(52); AX += 0x8; /* 089d:448f add ax, 8 */
    TR(0x0ce62); /* 089d:4492 cmp word ptr [si + 0x500a], ax */
    TR(0x0ce66); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) > (int16_t)AX) goto L0ceac; /* 089d:4496 jg 0xceac */
    TR(0x0ce68); CYC(136); WW(DS_, 0x50d6, 0x1); /* 089d:4498 mov word ptr [0x50d6], 1 */
    TR(0x0ce6e); AX = RW(DS_, (uint16_t)(BX + 0x5fec)); /* 089d:449e mov ax, word ptr [bx + 0x5fec] */
    TR(0x0ce72); WW(DS_, 0x50d8, AX); /* 089d:44a2 mov word ptr [0x50d8], ax */
    TR(0x0ce75); AX = RW(DS_, (uint16_t)(BX + 0x6028)); /* 089d:44a5 mov ax, word ptr [bx + 0x6028] */
    TR(0x0ce79); WW(DS_, 0x50da, AX); /* 089d:44a9 mov word ptr [0x50da], ax */
    TR(0x0ce7c); /* 089d:44ac cmp word ptr [si + 0x501e], 1 */
    TR(0x0ce81); if (RW(DS_, (uint16_t)(SI + 0x501e)) != 0x1) goto L0ce8d; /* 089d:44b1 jne 0xce8d */
    TR(0x0ce83); CYC(46); PUSH(BX); /* 089d:44b3 push bx */
    TR(0x0ce84); BX = SI; /* 089d:44b4 mov bx, si */
    TR(0x0ce86); PUSH(0x44b9); goto L0b66e; /* 089d:44b6 call 0xb66e */
L0ce89:
    TR(0x0ce89); CYC(27); BX = POP(); /* 089d:44b9 pop bx */
    TR(0x0ce8a); goto L0ce94; /* 089d:44ba jmp 0xce94 */
L0ce8d:
    TR(0x0ce8d); CYC(46); PUSH(BX); /* 089d:44bd push bx */
    TR(0x0ce8e); BX = SI; /* 089d:44be mov bx, si */
    TR(0x0ce90); PUSH(0x44c3); goto L0c6c3; /* 089d:44c0 call 0xc6c3 */
L0ce93:
    TR(0x0ce93); CYC(12); BX = POP(); /* 089d:44c3 pop bx */
L0ce94:
    TR(0x0ce94); CYC(71); WW(DS_, (uint16_t)(SI + 0x501e), 0x0); /* 089d:44c4 mov word ptr [si + 0x501e], 0 */
    TR(0x0ce9a); WW(DS_, (uint16_t)(BX + 0x6064), 0x0); /* 089d:44ca mov word ptr [bx + 0x6064], 0 */
    TR(0x0cea0); PUSH(0x44d3); goto L0ceb2; /* 089d:44d0 call 0xceb2 */
L0cea3:
    TR(0x0cea3); CYC(35); AX = 0x14; /* 089d:44d3 mov ax, 0x14 */
    TR(0x0cea6); PUSH(0x44d9); goto L0b829; /* 089d:44d6 call 0xb829 */
L0cea9:
    TR(0x0cea9); CYC(15); goto L0ceb0; /* 089d:44d9 jmp 0xceb0 */
L0ceac:
    TR(0x0ceac); CYC(25); SI++; /* 089d:44dc inc si */
    TR(0x0cead); SI++; /* 089d:44dd inc si */
    TR(0x0ceae); if (--CX) goto L0ce31; /* 089d:44de loop 0xce31 */
L0ceb0:
    TR(0x0ceb0); CYC(32); CX = POP(); /* 089d:44e0 pop cx */
    TR(0x0ceb1); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:44e1 ret  */

/* ---- f_089d_44e2 */
L0ceb2:
    TR(0x0ceb2); CYC(40); /* 089d:44e2 cmp word ptr [bx + 0x5fec], 0x137 */
    TR(0x0ceb8); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x5fec)) > (int16_t)0x137) goto L0cf05; /* 089d:44e8 jg 0xcf05 */
    TR(0x0ceba); CYC(40); /* 089d:44ea cmp word ptr [bx + 0x5fec], 0 */
    TR(0x0cebf); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x5fec)) < (int16_t)0x0) goto L0cf05; /* 089d:44ef jl 0xcf05 */
    TR(0x0cec1); CYC(362); AX = RW(DS_, (uint16_t)(BX + 0x6118)); /* 089d:44f1 mov ax, word ptr [bx + 0x6118] */
    TR(0x0cec5); { uint16_t a_ = AX; unsigned n_ = 1 & 0x1f; AX = (uint16_t)((int16_t)a_ >> n_); } /* 089d:44f5 sar ax, 1 */
    TR(0x0cec7); PUSH(BX); /* 089d:44f7 push bx */
    TR(0x0cec8); PUSH(CX); /* 089d:44f8 push cx */
    TR(0x0cec9); PUSH(DX); /* 089d:44f9 push dx */
    TR(0x0ceca); PUSH(SI); /* 089d:44fa push si */
    TR(0x0cecb); PUSH(DI); /* 089d:44fb push di */
    TR(0x0cecc); AX = AX; /* 089d:44fc mov ax, ax */
    TR(0x0cece); AX += AX; /* 089d:44fe add ax, ax */
    TR(0x0ced0); DI = AX; /* 089d:4500 mov di, ax */
    TR(0x0ced2); SI = RW(DS_, (uint16_t)(DI + 0x8391)); /* 089d:4502 mov si, word ptr [di - 0x7c6f] */
    TR(0x0ced6); DL = RB(DS_, SI); /* 089d:4506 mov dl, byte ptr [si] */
    TR(0x0ced8); DH = DL; /* 089d:4508 mov dh, dl */
    TR(0x0ceda); SI++; /* 089d:450a inc si */
    TR(0x0cedb); CH = RB(DS_, SI); /* 089d:450b mov ch, byte ptr [si] */
    TR(0x0cedd); SI++; /* 089d:450d inc si */
    TR(0x0cede); WW(DS_, 0x36, SI); /* 089d:450e mov word ptr [0x36], si */
    TR(0x0cee2); AX = RW(DS_, (uint16_t)(BX + 0x6028)); /* 089d:4512 mov ax, word ptr [bx + 0x6028] */
    TR(0x0cee6); WW(DS_, 0x2e, AX); /* 089d:4516 mov word ptr [0x2e], ax */
    TR(0x0cee9); BX = RW(DS_, (uint16_t)(BX + 0x5fec)); /* 089d:4519 mov bx, word ptr [bx + 0x5fec] */
    TR(0x0ceed); AX = RW(DS_, (uint16_t)(BX + 0x680e)); /* 089d:451d mov ax, word ptr [bx + 0x680e] */
    TR(0x0cef1); AH = 0x0; /* 089d:4521 mov ah, 0 */
    TR(0x0cef3); WW(DS_, 0x2c, AX); /* 089d:4523 mov word ptr [0x2c], ax */
    TR(0x0cef6); AX = RW(DS_, (uint16_t)(BX + 0x695c)); /* 089d:4526 mov ax, word ptr [bx + 0x695c] */
    TR(0x0cefa); WW(DS_, 0x3a, AX); /* 089d:452a mov word ptr [0x3a], ax */
    TR(0x0cefd); PUSH(0x4530); goto L0ae25; /* 089d:452d call 0xae25 */
L0cf00:
    TR(0x0cf00); CYC(60); DI = POP(); /* 089d:4530 pop di */
    TR(0x0cf01); SI = POP(); /* 089d:4531 pop si */
    TR(0x0cf02); DX = POP(); /* 089d:4532 pop dx */
    TR(0x0cf03); CX = POP(); /* 089d:4533 pop cx */
    TR(0x0cf04); BX = POP(); /* 089d:4534 pop bx */
L0cf05:
    TR(0x0cf05); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:4535 ret  */

/* ---- f_089d_4536 */
L0cf06:
    TR(0x0cf06); CYC(40); /* 089d:4536 cmp word ptr [bx + 0x619e], 0x127 */
    TR(0x0cf0c); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x619e)) > (int16_t)0x127) goto L0cf59; /* 089d:453c jg 0xcf59 */
    TR(0x0cf0e); CYC(40); /* 089d:453e cmp word ptr [bx + 0x619e], 0 */
    TR(0x0cf13); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x619e)) < (int16_t)0x0) goto L0cf59; /* 089d:4543 jl 0xcf59 */
    TR(0x0cf15); CYC(362); AX = RW(DS_, (uint16_t)(BX + 0x61bc)); /* 089d:4545 mov ax, word ptr [bx + 0x61bc] */
    TR(0x0cf19); AX >>= 1; /* 089d:4549 shr ax, 1 */
    TR(0x0cf1b); PUSH(BX); /* 089d:454b push bx */
    TR(0x0cf1c); PUSH(CX); /* 089d:454c push cx */
    TR(0x0cf1d); PUSH(DX); /* 089d:454d push dx */
    TR(0x0cf1e); PUSH(SI); /* 089d:454e push si */
    TR(0x0cf1f); PUSH(DI); /* 089d:454f push di */
    TR(0x0cf20); AX = AX; /* 089d:4550 mov ax, ax */
    TR(0x0cf22); AX += AX; /* 089d:4552 add ax, ax */
    TR(0x0cf24); DI = AX; /* 089d:4554 mov di, ax */
    TR(0x0cf26); SI = RW(DS_, (uint16_t)(DI + 0x8431)); /* 089d:4556 mov si, word ptr [di - 0x7bcf] */
    TR(0x0cf2a); DL = RB(DS_, SI); /* 089d:455a mov dl, byte ptr [si] */
    TR(0x0cf2c); DH = DL; /* 089d:455c mov dh, dl */
    TR(0x0cf2e); SI++; /* 089d:455e inc si */
    TR(0x0cf2f); CH = RB(DS_, SI); /* 089d:455f mov ch, byte ptr [si] */
    TR(0x0cf31); SI++; /* 089d:4561 inc si */
    TR(0x0cf32); WW(DS_, 0x36, SI); /* 089d:4562 mov word ptr [0x36], si */
    TR(0x0cf36); AX = RW(DS_, (uint16_t)(BX + 0x6252)); /* 089d:4566 mov ax, word ptr [bx + 0x6252] */
    TR(0x0cf3a); WW(DS_, 0x2e, AX); /* 089d:456a mov word ptr [0x2e], ax */
    TR(0x0cf3d); BX = RW(DS_, (uint16_t)(BX + 0x619e)); /* 089d:456d mov bx, word ptr [bx + 0x619e] */
    TR(0x0cf41); AX = RW(DS_, (uint16_t)(BX + 0x680e)); /* 089d:4571 mov ax, word ptr [bx + 0x680e] */
    TR(0x0cf45); AH = 0x0; /* 089d:4575 mov ah, 0 */
    TR(0x0cf47); WW(DS_, 0x2c, AX); /* 089d:4577 mov word ptr [0x2c], ax */
    TR(0x0cf4a); AX = RW(DS_, (uint16_t)(BX + 0x695c)); /* 089d:457a mov ax, word ptr [bx + 0x695c] */
    TR(0x0cf4e); WW(DS_, 0x3a, AX); /* 089d:457e mov word ptr [0x3a], ax */
    TR(0x0cf51); PUSH(0x4584); goto L0ae25; /* 089d:4581 call 0xae25 */
L0cf54:
    TR(0x0cf54); CYC(60); DI = POP(); /* 089d:4584 pop di */
    TR(0x0cf55); SI = POP(); /* 089d:4585 pop si */
    TR(0x0cf56); DX = POP(); /* 089d:4586 pop dx */
    TR(0x0cf57); CX = POP(); /* 089d:4587 pop cx */
    TR(0x0cf58); BX = POP(); /* 089d:4588 pop bx */
L0cf59:
    TR(0x0cf59); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:4589 ret  */

/* ---- f_089d_458a */
L0cf5a:
    TR(0x0cf5a); CYC(40); /* 089d:458a cmp word ptr [0x6272], 1 */
    TR(0x0cf5f); if (RW(DS_, 0x6272) == 0x1) goto L0cf62; /* 089d:458f je 0xcf62 */
    TR(0x0cf61); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:4591 ret  */
L0cf62:
    TR(0x0cf62); CYC(30); CX = RW(DS_, 0x6270); /* 089d:4592 mov cx, word ptr [0x6270] */
    TR(0x0cf66); BX = 0x0; /* 089d:4596 mov bx, 0 */
L0cf69:
    TR(0x0cf69); CYC(40); /* 089d:4599 cmp word ptr [bx + 0x61da], 0 */
    TR(0x0cf6e); if (RW(DS_, (uint16_t)(BX + 0x61da)) == 0x0) goto L0cf73; /* 089d:459e je 0xcf73 */
    TR(0x0cf70); CYC(23); PUSH(0x45a3); goto L0cf78; /* 089d:45a0 call 0xcf78 */
L0cf73:
    TR(0x0cf73); CYC(25); BX++; /* 089d:45a3 inc bx */
    TR(0x0cf74); BX++; /* 089d:45a4 inc bx */
    TR(0x0cf75); if (--CX) goto L0cf69; /* 089d:45a5 loop 0xcf69 */
    TR(0x0cf77); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:45a7 ret  */

/* ---- f_089d_45a8 */
L0cf78:
    TR(0x0cf78); CYC(23); PUSH(0x45ab); goto L0cf06; /* 089d:45a8 call 0xcf06 */
L0cf7b:
    TR(0x0cf7b); CYC(157); AX = RW(DS_, 0x4a); /* 089d:45ab mov ax, word ptr [0x4a] */
    TR(0x0cf7e); AX = (uint16_t)(0u - AX); /* 089d:45ae neg ax */
    TR(0x0cf80); AX += RW(DS_, (uint16_t)(BX + 0x6216)); /* 089d:45b0 add ax, word ptr [bx + 0x6216] */
    TR(0x0cf84); WW(DS_, (uint16_t)(BX + 0x619e), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x619e)) + AX)); /* 089d:45b4 add word ptr [bx + 0x619e], ax */
    TR(0x0cf88); AX = RW(DS_, (uint16_t)(BX + 0x61f8)); /* 089d:45b8 mov ax, word ptr [bx + 0x61f8] */
    TR(0x0cf8c); WW(DS_, (uint16_t)(BX + 0x6252), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x6252)) + AX)); /* 089d:45bc add word ptr [bx + 0x6252], ax */
    TR(0x0cf90); /* 089d:45c0 cmp word ptr [bx + 0x619e], 0 */
    TR(0x0cf95); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x619e)) >= (int16_t)0x0) goto L0cf9d; /* 089d:45c5 jge 0xcf9d */
    TR(0x0cf97); CYC(24); WW(DS_, (uint16_t)(BX + 0x619e), 0x18ec); /* 089d:45c7 mov word ptr [bx + 0x619e], 0x18ec */
L0cf9d:
    TR(0x0cf9d); CYC(67); WW(DS_, (uint16_t)(BX + 0x61bc), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x61bc)) - 1)); /* 089d:45cd dec word ptr [bx + 0x61bc] */
    TR(0x0cfa1); /* 089d:45d1 cmp word ptr [bx + 0x61bc], -1 */
    TR(0x0cfa6); if (RW(DS_, (uint16_t)(BX + 0x61bc)) != 0xffff) goto L0cfae; /* 089d:45d6 jne 0xcfae */
    TR(0x0cfa8); CYC(24); WW(DS_, (uint16_t)(BX + 0x61bc), 0x7); /* 089d:45d8 mov word ptr [bx + 0x61bc], 7 */
L0cfae:
    TR(0x0cfae); CYC(94); AX = RW(DS_, (uint16_t)(BX + 0x6234)); /* 089d:45de mov ax, word ptr [bx + 0x6234] */
    TR(0x0cfb2); WW(DS_, (uint16_t)(BX + 0x6216), AX); /* 089d:45e2 mov word ptr [bx + 0x6216], ax */
    TR(0x0cfb6); AX = RW(DS_, 0x4170); /* 089d:45e6 mov ax, word ptr [0x4170] */
    TR(0x0cfb9); /* 089d:45e9 cmp word ptr [bx + 0x619e], ax */
    TR(0x0cfbd); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x619e)) < (int16_t)AX) goto L0cfc9; /* 089d:45ed jl 0xcfc9 */
    TR(0x0cfbf); CYC(44); AX = RW(DS_, (uint16_t)(BX + 0x6234)); /* 089d:45ef mov ax, word ptr [bx + 0x6234] */
    TR(0x0cfc3); AX = (uint16_t)(0u - AX); /* 089d:45f3 neg ax */
    TR(0x0cfc5); WW(DS_, (uint16_t)(BX + 0x6216), AX); /* 089d:45f5 mov word ptr [bx + 0x6216], ax */
L0cfc9:
    TR(0x0cfc9); CYC(40); /* 089d:45f9 cmp word ptr [bx + 0x6252], 0x19 */
    TR(0x0cfce); if (RW(DS_, (uint16_t)(BX + 0x6252)) != 0x19) goto L0cfd6; /* 089d:45fe jne 0xcfd6 */
    TR(0x0cfd0); CYC(24); WW(DS_, (uint16_t)(BX + 0x61f8), 0x1); /* 089d:4600 mov word ptr [bx + 0x61f8], 1 */
L0cfd6:
    TR(0x0cfd6); CYC(40); /* 089d:4606 cmp word ptr [bx + 0x6252], 0xa4 */
    TR(0x0cfdc); if (RW(DS_, (uint16_t)(BX + 0x6252)) != 0xa4) goto L0cfe4; /* 089d:460c jne 0xcfe4 */
    TR(0x0cfde); CYC(24); WW(DS_, (uint16_t)(BX + 0x61f8), 0xffff); /* 089d:460e mov word ptr [bx + 0x61f8], 0xffff */
L0cfe4:
    TR(0x0cfe4); CYC(68); AX = RW(DS_, 0x4170); /* 089d:4614 mov ax, word ptr [0x4170] */
    TR(0x0cfe7); DX = RW(DS_, (uint16_t)(BX + 0x619e)); /* 089d:4617 mov dx, word ptr [bx + 0x619e] */
    TR(0x0cfeb); AX += 0x14; /* 089d:461b add ax, 0x14 */
    TR(0x0cfee); /* 089d:461e cmp ax, dx */
    TR(0x0cff0); if ((int16_t)AX < (int16_t)DX) goto L0d00d; /* 089d:4620 jl 0xd00d */
    TR(0x0cff2); CYC(44); AX -= 0x14; /* 089d:4622 sub ax, 0x14 */
    TR(0x0cff5); DX += 0x18; /* 089d:4625 add dx, 0x18 */
    TR(0x0cff8); /* 089d:4628 cmp ax, dx */
    TR(0x0cffa); if ((int16_t)AX > (int16_t)DX) goto L0d00d; /* 089d:462a jg 0xd00d */
    TR(0x0cffc); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x6234)); /* 089d:462c mov ax, word ptr [bx + 0x6234] */
    TR(0x0d000); /* 089d:4630 cmp word ptr [0x4a], ax */
    TR(0x0d004); if ((int16_t)RW(DS_, 0x4a) > (int16_t)AX) goto L0d00d; /* 089d:4634 jg 0xd00d */
    TR(0x0d006); CYC(36); AX = RW(DS_, 0x4a); /* 089d:4636 mov ax, word ptr [0x4a] */
    TR(0x0d009); WW(DS_, (uint16_t)(BX + 0x6216), AX); /* 089d:4639 mov word ptr [bx + 0x6216], ax */
L0d00d:
    TR(0x0d00d); CYC(23); PUSH(0x4640); goto L0cf06; /* 089d:463d call 0xcf06 */
L0d010:
    TR(0x0d010); CYC(45); PUSH(CX); /* 089d:4640 push cx */
    TR(0x0d011); CX = RW(DS_, 0x5062); /* 089d:4641 mov cx, word ptr [0x5062] */
    TR(0x0d015); SI = 0x0; /* 089d:4645 mov si, 0 */
L0d018:
    TR(0x0d018); CYC(40); /* 089d:4648 cmp word ptr [si + 0x501e], 0 */
    TR(0x0d01d); if (RW(DS_, (uint16_t)(SI + 0x501e)) == 0x0) goto L0d055; /* 089d:464d je 0xd055 */
    TR(0x0d01f); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x619e)); /* 089d:464f mov ax, word ptr [bx + 0x619e] */
    TR(0x0d023); /* 089d:4653 cmp word ptr [si + 0x4ff6], ax */
    TR(0x0d027); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x4ff6)) < (int16_t)AX) goto L0d055; /* 089d:4657 jl 0xd055 */
    TR(0x0d029); CYC(52); AX += 0x18; /* 089d:4659 add ax, 0x18 */
    TR(0x0d02c); /* 089d:465c cmp word ptr [si + 0x4ff6], ax */
    TR(0x0d030); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x4ff6)) > (int16_t)AX) goto L0d055; /* 089d:4660 jg 0xd055 */
    TR(0x0d032); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x6252)); /* 089d:4662 mov ax, word ptr [bx + 0x6252] */
    TR(0x0d036); /* 089d:4666 cmp word ptr [si + 0x500a], ax */
    TR(0x0d03a); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) < (int16_t)AX) goto L0d055; /* 089d:466a jl 0xd055 */
    TR(0x0d03c); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x6252)); /* 089d:466c mov ax, word ptr [bx + 0x6252] */
    TR(0x0d040); /* 089d:4670 cmp word ptr [si + 0x500a], ax */
    TR(0x0d044); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) < (int16_t)AX) goto L0d055; /* 089d:4674 jl 0xd055 */
    TR(0x0d046); CYC(52); AX += 0x10; /* 089d:4676 add ax, 0x10 */
    TR(0x0d049); /* 089d:4679 cmp word ptr [si + 0x500a], ax */
    TR(0x0d04d); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) > (int16_t)AX) goto L0d055; /* 089d:467d jg 0xd055 */
    TR(0x0d04f); CYC(23); PUSH(0x4682); goto L0d09f; /* 089d:467f call 0xd09f */
L0d052:
    TR(0x0d052); CYC(15); goto L0d059; /* 089d:4682 jmp 0xd059 */
L0d055:
    TR(0x0d055); CYC(25); SI++; /* 089d:4685 inc si */
    TR(0x0d056); SI++; /* 089d:4686 inc si */
    TR(0x0d057); if (--CX) goto L0d018; /* 089d:4687 loop 0xd018 */
L0d059:
    TR(0x0d059); CYC(40); /* 089d:4689 cmp word ptr [0x4176], 1 */
    TR(0x0d05e); if (RW(DS_, 0x4176) != 0x1) goto L0d09d; /* 089d:468e jne 0xd09d */
    TR(0x0d060); CYC(40); /* 089d:4690 cmp word ptr [bx + 0x61da], 1 */
    TR(0x0d065); if (RW(DS_, (uint16_t)(BX + 0x61da)) != 0x1) goto L0d09d; /* 089d:4695 jne 0xd09d */
    TR(0x0d067); CYC(68); AX = RW(DS_, 0x4170); /* 089d:4697 mov ax, word ptr [0x4170] */
    TR(0x0d06a); DX = RW(DS_, (uint16_t)(BX + 0x619e)); /* 089d:469a mov dx, word ptr [bx + 0x619e] */
    TR(0x0d06e); AX += 0x14; /* 089d:469e add ax, 0x14 */
    TR(0x0d071); /* 089d:46a1 cmp ax, dx */
    TR(0x0d073); if ((int16_t)AX < (int16_t)DX) goto L0d09d; /* 089d:46a3 jl 0xd09d */
    TR(0x0d075); CYC(44); AX -= 0x14; /* 089d:46a5 sub ax, 0x14 */
    TR(0x0d078); DX += 0x18; /* 089d:46a8 add dx, 0x18 */
    TR(0x0d07b); /* 089d:46ab cmp ax, dx */
    TR(0x0d07d); if ((int16_t)AX > (int16_t)DX) goto L0d09d; /* 089d:46ad jg 0xd09d */
    TR(0x0d07f); CYC(68); AX = RW(DS_, 0x4172); /* 089d:46af mov ax, word ptr [0x4172] */
    TR(0x0d082); DX = RW(DS_, (uint16_t)(BX + 0x6252)); /* 089d:46b2 mov dx, word ptr [bx + 0x6252] */
    TR(0x0d086); AX += 0xe; /* 089d:46b6 add ax, 0xe */
    TR(0x0d089); /* 089d:46b9 cmp ax, dx */
    TR(0x0d08b); if ((int16_t)AX < (int16_t)DX) goto L0d09d; /* 089d:46bb jl 0xd09d */
    TR(0x0d08d); CYC(44); AX -= 0xe; /* 089d:46bd sub ax, 0xe */
    TR(0x0d090); DX += 0x10; /* 089d:46c0 add dx, 0x10 */
    TR(0x0d093); /* 089d:46c3 cmp ax, dx */
    TR(0x0d095); if ((int16_t)AX > (int16_t)DX) goto L0d09d; /* 089d:46c5 jg 0xd09d */
    TR(0x0d097); CYC(24); WW(DS_, 0x5360, 0x1); /* 089d:46c7 mov word ptr [0x5360], 1 */
L0d09d:
    TR(0x0d09d); CYC(32); CX = POP(); /* 089d:46cd pop cx */
    TR(0x0d09e); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:46ce ret  */

/* ---- f_089d_46cf */
L0d09f:
    TR(0x0d09f); CYC(196); WW(DS_, 0x50d6, 0x1); /* 089d:46cf mov word ptr [0x50d6], 1 */
    TR(0x0d0a5); WW(DS_, 0x62fa, 0x1); /* 089d:46d5 mov word ptr [0x62fa], 1 */
    TR(0x0d0ab); AX = RW(DS_, (uint16_t)(BX + 0x619e)); /* 089d:46db mov ax, word ptr [bx + 0x619e] */
    TR(0x0d0af); WW(DS_, 0x50d8, AX); /* 089d:46df mov word ptr [0x50d8], ax */
    TR(0x0d0b2); WW(DS_, 0x62fc, AX); /* 089d:46e2 mov word ptr [0x62fc], ax */
    TR(0x0d0b5); AX = RW(DS_, (uint16_t)(BX + 0x6252)); /* 089d:46e5 mov ax, word ptr [bx + 0x6252] */
    TR(0x0d0b9); WW(DS_, 0x50da, AX); /* 089d:46e9 mov word ptr [0x50da], ax */
    TR(0x0d0bc); WW(DS_, 0x62fe, AX); /* 089d:46ec mov word ptr [0x62fe], ax */
    TR(0x0d0bf); /* 089d:46ef cmp word ptr [si + 0x501e], 1 */
    TR(0x0d0c4); if (RW(DS_, (uint16_t)(SI + 0x501e)) != 0x1) goto L0d0d0; /* 089d:46f4 jne 0xd0d0 */
    TR(0x0d0c6); CYC(46); PUSH(BX); /* 089d:46f6 push bx */
    TR(0x0d0c7); BX = SI; /* 089d:46f7 mov bx, si */
    TR(0x0d0c9); PUSH(0x46fc); goto L0b66e; /* 089d:46f9 call 0xb66e */
L0d0cc:
    TR(0x0d0cc); CYC(27); BX = POP(); /* 089d:46fc pop bx */
    TR(0x0d0cd); goto L0d0d7; /* 089d:46fd jmp 0xd0d7 */
L0d0d0:
    TR(0x0d0d0); CYC(46); PUSH(BX); /* 089d:4700 push bx */
    TR(0x0d0d1); BX = SI; /* 089d:4701 mov bx, si */
    TR(0x0d0d3); PUSH(0x4706); goto L0c6c3; /* 089d:4703 call 0xc6c3 */
L0d0d6:
    TR(0x0d0d6); CYC(12); BX = POP(); /* 089d:4706 pop bx */
L0d0d7:
    TR(0x0d0d7); CYC(71); WW(DS_, (uint16_t)(SI + 0x501e), 0x0); /* 089d:4707 mov word ptr [si + 0x501e], 0 */
    TR(0x0d0dd); WW(DS_, (uint16_t)(BX + 0x61da), 0x0); /* 089d:470d mov word ptr [bx + 0x61da], 0 */
    TR(0x0d0e3); PUSH(0x4716); goto L0cf06; /* 089d:4713 call 0xcf06 */
L0d0e6:
    TR(0x0d0e6); CYC(35); AX = 0x14; /* 089d:4716 mov ax, 0x14 */
    TR(0x0d0e9); PUSH(0x471c); goto L0b829; /* 089d:4719 call 0xb829 */
L0d0ec:
    TR(0x0d0ec); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:471c ret  */

/* ---- f_089d_471d */
L0d0ed:
    TR(0x0d0ed); CYC(40); /* 089d:471d cmp word ptr [0x62f8], 1 */
    TR(0x0d0f2); if (RW(DS_, 0x62f8) == 0x1) goto L0d0f5; /* 089d:4722 je 0xd0f5 */
    TR(0x0d0f4); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:4724 ret  */
L0d0f5:
    TR(0x0d0f5); CYC(30); CX = RW(DS_, 0x6300); /* 089d:4725 mov cx, word ptr [0x6300] */
    TR(0x0d0f9); BX = 0x0; /* 089d:4729 mov bx, 0 */
L0d0fc:
    TR(0x0d0fc); CYC(40); /* 089d:472c cmp word ptr [bx + 0x62a0], 0 */
    TR(0x0d101); if (RW(DS_, (uint16_t)(BX + 0x62a0)) == 0x0) goto L0d109; /* 089d:4731 je 0xd109 */
    TR(0x0d103); CYC(23); PUSH(0x4736); goto L0d14b; /* 089d:4733 call 0xd14b */
L0d106:
    TR(0x0d106); CYC(15); goto L0d140; /* 089d:4736 jmp 0xd140 */
L0d109:
    TR(0x0d109); CYC(40); /* 089d:4739 cmp word ptr [0x62fa], 0 */
    TR(0x0d10e); if (RW(DS_, 0x62fa) == 0x0) goto L0d140; /* 089d:473e je 0xd140 */
    TR(0x0d110); CYC(227); WW(DS_, 0x62fa, 0x0); /* 089d:4740 mov word ptr [0x62fa], 0 */
    TR(0x0d116); WW(DS_, (uint16_t)(BX + 0x62a0), 0x1); /* 089d:4746 mov word ptr [bx + 0x62a0], 1 */
    TR(0x0d11c); AX = RW(DS_, 0x62fc); /* 089d:474c mov ax, word ptr [0x62fc] */
    TR(0x0d11f); WW(DS_, (uint16_t)(BX + 0x6274), AX); /* 089d:474f mov word ptr [bx + 0x6274], ax */
    TR(0x0d123); AX = RW(DS_, 0x62fe); /* 089d:4753 mov ax, word ptr [0x62fe] */
    TR(0x0d126); WW(DS_, (uint16_t)(BX + 0x628a), AX); /* 089d:4756 mov word ptr [bx + 0x628a], ax */
    TR(0x0d12a); WW(DS_, (uint16_t)(BX + 0x62cc), 0x0); /* 089d:475a mov word ptr [bx + 0x62cc], 0 */
    TR(0x0d130); WW(DS_, (uint16_t)(BX + 0x62e2), 0x1); /* 089d:4760 mov word ptr [bx + 0x62e2], 1 */
    TR(0x0d136); AX = RW(DS_, 0x4a); /* 089d:4766 mov ax, word ptr [0x4a] */
    TR(0x0d139); WW(DS_, (uint16_t)(BX + 0x62b6), AX); /* 089d:4769 mov word ptr [bx + 0x62b6], ax */
    TR(0x0d13d); PUSH(0x4770); goto L0d2b7; /* 089d:476d call 0xd2b7 */
L0d140:
    TR(0x0d140); CYC(25); BX++; /* 089d:4770 inc bx */
    TR(0x0d141); BX++; /* 089d:4771 inc bx */
    TR(0x0d142); if (--CX) goto L0d0fc; /* 089d:4772 loop 0xd0fc */
    TR(0x0d144); CYC(44); WW(DS_, 0x62fa, 0x0); /* 089d:4774 mov word ptr [0x62fa], 0 */
    TR(0x0d14a); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:477a ret  */

/* ---- f_089d_477b */
L0d14b:
    TR(0x0d14b); CYC(23); PUSH(0x477e); goto L0d2b7; /* 089d:477b call 0xd2b7 */
L0d14e:
    TR(0x0d14e); CYC(184); AX = RW(DS_, 0x4a); /* 089d:477e mov ax, word ptr [0x4a] */
    TR(0x0d151); AX = (uint16_t)(0u - AX); /* 089d:4781 neg ax */
    TR(0x0d153); AX += RW(DS_, (uint16_t)(BX + 0x62b6)); /* 089d:4783 add ax, word ptr [bx + 0x62b6] */
    TR(0x0d157); WW(DS_, (uint16_t)(BX + 0x6274), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x6274)) + AX)); /* 089d:4787 add word ptr [bx + 0x6274], ax */
    TR(0x0d15b); WW(DS_, (uint16_t)(BX + 0x628a), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x628a)) + 1)); /* 089d:478b inc word ptr [bx + 0x628a] */
    TR(0x0d15f); AX = RW(DS_, (uint16_t)(BX + 0x62e2)); /* 089d:478f mov ax, word ptr [bx + 0x62e2] */
    TR(0x0d163); WW(DS_, (uint16_t)(BX + 0x62cc), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x62cc)) + AX)); /* 089d:4793 add word ptr [bx + 0x62cc], ax */
    TR(0x0d167); /* 089d:4797 cmp word ptr [bx + 0x62cc], 8 */
    TR(0x0d16c); if (RW(DS_, (uint16_t)(BX + 0x62cc)) != 0x8) goto L0d17a; /* 089d:479c jne 0xd17a */
    TR(0x0d16e); CYC(48); WW(DS_, (uint16_t)(BX + 0x62e2), 0xffff); /* 089d:479e mov word ptr [bx + 0x62e2], 0xffff */
    TR(0x0d174); WW(DS_, (uint16_t)(BX + 0x62cc), 0x7); /* 089d:47a4 mov word ptr [bx + 0x62cc], 7 */
L0d17a:
    TR(0x0d17a); CYC(40); /* 089d:47aa cmp word ptr [bx + 0x62cc], -1 */
    TR(0x0d17f); if (RW(DS_, (uint16_t)(BX + 0x62cc)) != 0xffff) goto L0d18d; /* 089d:47af jne 0xd18d */
    TR(0x0d181); CYC(48); WW(DS_, (uint16_t)(BX + 0x62e2), 0x1); /* 089d:47b1 mov word ptr [bx + 0x62e2], 1 */
    TR(0x0d187); WW(DS_, (uint16_t)(BX + 0x62cc), 0x0); /* 089d:47b7 mov word ptr [bx + 0x62cc], 0 */
L0d18d:
    TR(0x0d18d); CYC(40); /* 089d:47bd cmp word ptr [bx + 0x6274], 0 */
    TR(0x0d192); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x6274)) >= (int16_t)0x0) goto L0d19a; /* 089d:47c2 jge 0xd19a */
    TR(0x0d194); CYC(24); WW(DS_, (uint16_t)(BX + 0x6274), 0x18eb); /* 089d:47c4 mov word ptr [bx + 0x6274], 0x18eb */
L0d19a:
    TR(0x0d19a); CYC(40); /* 089d:47ca cmp word ptr [bx + 0x6274], 0x18ec */
    TR(0x0d1a0); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x6274)) < (int16_t)0x18ec) goto L0d1a8; /* 089d:47d0 jl 0xd1a8 */
    TR(0x0d1a2); CYC(24); WW(DS_, (uint16_t)(BX + 0x6274), 0x0); /* 089d:47d2 mov word ptr [bx + 0x6274], 0 */
L0d1a8:
    TR(0x0d1a8); CYC(40); /* 089d:47d8 cmp word ptr [bx + 0x628a], 0xad */
    TR(0x0d1ae); if (RW(DS_, (uint16_t)(BX + 0x628a)) != 0xad) goto L0d1b7; /* 089d:47de jne 0xd1b7 */
    TR(0x0d1b0); CYC(44); WW(DS_, (uint16_t)(BX + 0x62a0), 0x0); /* 089d:47e0 mov word ptr [bx + 0x62a0], 0 */
    TR(0x0d1b6); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:47e6 ret  */
L0d1b7:
    TR(0x0d1b7); CYC(23); PUSH(0x47ea); goto L0d2b7; /* 089d:47e7 call 0xd2b7 */
L0d1ba:
    TR(0x0d1ba); CYC(40); /* 089d:47ea cmp word ptr [0x4176], 1 */
    TR(0x0d1bf); if (RW(DS_, 0x4176) != 0x1) goto L0d1fb; /* 089d:47ef jne 0xd1fb */
    TR(0x0d1c1); CYC(40); /* 089d:47f1 cmp word ptr [bx + 0x62a0], 1 */
    TR(0x0d1c6); if (RW(DS_, (uint16_t)(BX + 0x62a0)) != 0x1) goto L0d1fb; /* 089d:47f6 jne 0xd1fb */
    TR(0x0d1c8); CYC(68); AX = RW(DS_, 0x4170); /* 089d:47f8 mov ax, word ptr [0x4170] */
    TR(0x0d1cb); DX = RW(DS_, (uint16_t)(BX + 0x6274)); /* 089d:47fb mov dx, word ptr [bx + 0x6274] */
    TR(0x0d1cf); AX += 0x14; /* 089d:47ff add ax, 0x14 */
    TR(0x0d1d2); /* 089d:4802 cmp ax, dx */
    TR(0x0d1d4); if ((int16_t)AX < (int16_t)DX) goto L0d1fb; /* 089d:4804 jl 0xd1fb */
    TR(0x0d1d6); CYC(44); AX -= 0x14; /* 089d:4806 sub ax, 0x14 */
    TR(0x0d1d9); DX += 0x8; /* 089d:4809 add dx, 8 */
    TR(0x0d1dc); /* 089d:480c cmp ax, dx */
    TR(0x0d1de); if ((int16_t)AX > (int16_t)DX) goto L0d1fb; /* 089d:480e jg 0xd1fb */
    TR(0x0d1e0); CYC(68); AX = RW(DS_, 0x4172); /* 089d:4810 mov ax, word ptr [0x4172] */
    TR(0x0d1e3); DX = RW(DS_, (uint16_t)(BX + 0x628a)); /* 089d:4813 mov dx, word ptr [bx + 0x628a] */
    TR(0x0d1e7); AX += 0xe; /* 089d:4817 add ax, 0xe */
    TR(0x0d1ea); /* 089d:481a cmp ax, dx */
    TR(0x0d1ec); if ((int16_t)AX < (int16_t)DX) goto L0d1fb; /* 089d:481c jl 0xd1fb */
    TR(0x0d1ee); CYC(44); AX -= 0xe; /* 089d:481e sub ax, 0xe */
    TR(0x0d1f1); DX += 0x7; /* 089d:4821 add dx, 7 */
    TR(0x0d1f4); /* 089d:4824 cmp ax, dx */
    TR(0x0d1f6); if ((int16_t)AX > (int16_t)DX) goto L0d1fb; /* 089d:4826 jg 0xd1fb */
    TR(0x0d1f8); CYC(23); PUSH(0x482b); goto L0d284; /* 089d:4828 call 0xd284 */
L0d1fb:
    TR(0x0d1fb); CYC(45); PUSH(CX); /* 089d:482b push cx */
    TR(0x0d1fc); CX = RW(DS_, 0x5062); /* 089d:482c mov cx, word ptr [0x5062] */
    TR(0x0d200); SI = 0x0; /* 089d:4830 mov si, 0 */
L0d203:
    TR(0x0d203); CYC(40); /* 089d:4833 cmp word ptr [si + 0x501e], 0 */
    TR(0x0d208); if (RW(DS_, (uint16_t)(SI + 0x501e)) == 0x0) goto L0d27e; /* 089d:4838 je 0xd27e */
    TR(0x0d20a); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x6274)); /* 089d:483a mov ax, word ptr [bx + 0x6274] */
    TR(0x0d20e); /* 089d:483e cmp word ptr [si + 0x4ff6], ax */
    TR(0x0d212); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x4ff6)) < (int16_t)AX) goto L0d27e; /* 089d:4842 jl 0xd27e */
    TR(0x0d214); CYC(52); AX += 0x8; /* 089d:4844 add ax, 8 */
    TR(0x0d217); /* 089d:4847 cmp word ptr [si + 0x4ff6], ax */
    TR(0x0d21b); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x4ff6)) > (int16_t)AX) goto L0d27e; /* 089d:484b jg 0xd27e */
    TR(0x0d21d); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x628a)); /* 089d:484d mov ax, word ptr [bx + 0x628a] */
    TR(0x0d221); /* 089d:4851 cmp word ptr [si + 0x500a], ax */
    TR(0x0d225); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) < (int16_t)AX) goto L0d27e; /* 089d:4855 jl 0xd27e */
    TR(0x0d227); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x628a)); /* 089d:4857 mov ax, word ptr [bx + 0x628a] */
    TR(0x0d22b); /* 089d:485b cmp word ptr [si + 0x500a], ax */
    TR(0x0d22f); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) < (int16_t)AX) goto L0d27e; /* 089d:485f jl 0xd27e */
    TR(0x0d231); CYC(52); AX += 0x7; /* 089d:4861 add ax, 7 */
    TR(0x0d234); /* 089d:4864 cmp word ptr [si + 0x500a], ax */
    TR(0x0d238); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) > (int16_t)AX) goto L0d27e; /* 089d:4868 jg 0xd27e */
    TR(0x0d23a); CYC(136); WW(DS_, 0x50d6, 0x1); /* 089d:486a mov word ptr [0x50d6], 1 */
    TR(0x0d240); AX = RW(DS_, (uint16_t)(BX + 0x6274)); /* 089d:4870 mov ax, word ptr [bx + 0x6274] */
    TR(0x0d244); WW(DS_, 0x50d8, AX); /* 089d:4874 mov word ptr [0x50d8], ax */
    TR(0x0d247); AX = RW(DS_, (uint16_t)(BX + 0x628a)); /* 089d:4877 mov ax, word ptr [bx + 0x628a] */
    TR(0x0d24b); WW(DS_, 0x50da, AX); /* 089d:487b mov word ptr [0x50da], ax */
    TR(0x0d24e); /* 089d:487e cmp word ptr [si + 0x501e], 1 */
    TR(0x0d253); if (RW(DS_, (uint16_t)(SI + 0x501e)) != 0x1) goto L0d25f; /* 089d:4883 jne 0xd25f */
    TR(0x0d255); CYC(46); PUSH(BX); /* 089d:4885 push bx */
    TR(0x0d256); BX = SI; /* 089d:4886 mov bx, si */
    TR(0x0d258); PUSH(0x488b); goto L0b66e; /* 089d:4888 call 0xb66e */
L0d25b:
    TR(0x0d25b); CYC(27); BX = POP(); /* 089d:488b pop bx */
    TR(0x0d25c); goto L0d266; /* 089d:488c jmp 0xd266 */
L0d25f:
    TR(0x0d25f); CYC(46); PUSH(BX); /* 089d:488f push bx */
    TR(0x0d260); BX = SI; /* 089d:4890 mov bx, si */
    TR(0x0d262); PUSH(0x4895); goto L0c6c3; /* 089d:4892 call 0xc6c3 */
L0d265:
    TR(0x0d265); CYC(12); BX = POP(); /* 089d:4895 pop bx */
L0d266:
    TR(0x0d266); CYC(71); WW(DS_, (uint16_t)(SI + 0x501e), 0x0); /* 089d:4896 mov word ptr [si + 0x501e], 0 */
    TR(0x0d26c); WW(DS_, (uint16_t)(BX + 0x62a0), 0x0); /* 089d:489c mov word ptr [bx + 0x62a0], 0 */
    TR(0x0d272); PUSH(0x48a5); goto L0d2b7; /* 089d:48a2 call 0xd2b7 */
L0d275:
    TR(0x0d275); CYC(35); AX = 0x14; /* 089d:48a5 mov ax, 0x14 */
    TR(0x0d278); PUSH(0x48ab); goto L0b829; /* 089d:48a8 call 0xb829 */
L0d27b:
    TR(0x0d27b); CYC(15); goto L0d282; /* 089d:48ab jmp 0xd282 */
L0d27e:
    TR(0x0d27e); CYC(25); SI++; /* 089d:48ae inc si */
    TR(0x0d27f); SI++; /* 089d:48af inc si */
    TR(0x0d280); if (--CX) goto L0d203; /* 089d:48b0 loop 0xd203 */
L0d282:
    TR(0x0d282); CYC(32); CX = POP(); /* 089d:48b2 pop cx */
    TR(0x0d283); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:48b3 ret  */

/* ---- f_089d_48b4 */
L0d284:
    TR(0x0d284); CYC(203); WW(DS_, 0x5160, 0x1); /* 089d:48b4 mov word ptr [0x5160], 1 */
    TR(0x0d28a); AX = RW(DS_, (uint16_t)(BX + 0x6274)); /* 089d:48ba mov ax, word ptr [bx + 0x6274] */
    TR(0x0d28e); WW(DS_, 0x5162, AX); /* 089d:48be mov word ptr [0x5162], ax */
    TR(0x0d291); AX = RW(DS_, (uint16_t)(BX + 0x628a)); /* 089d:48c1 mov ax, word ptr [bx + 0x628a] */
    TR(0x0d295); AX -= 0x5; /* 089d:48c5 sub ax, 5 */
    TR(0x0d298); WW(DS_, 0x5164, AX); /* 089d:48c8 mov word ptr [0x5164], ax */
    TR(0x0d29b); WW(DS_, 0x5166, 0x0); /* 089d:48cb mov word ptr [0x5166], 0 */
    TR(0x0d2a1); AX = RW(DS_, 0x4a); /* 089d:48d1 mov ax, word ptr [0x4a] */
    TR(0x0d2a4); WW(DS_, 0x516a, AX); /* 089d:48d4 mov word ptr [0x516a], ax */
    TR(0x0d2a7); AX = 0x19; /* 089d:48d7 mov ax, 0x19 */
    TR(0x0d2aa); PUSH(0x48dd); goto L0b829; /* 089d:48da call 0xb829 */
L0d2ad:
    TR(0x0d2ad); CYC(47); WW(DS_, (uint16_t)(BX + 0x62a0), 0x0); /* 089d:48dd mov word ptr [bx + 0x62a0], 0 */
    TR(0x0d2b3); PUSH(0x48e6); goto L0d2b7; /* 089d:48e3 call 0xd2b7 */
L0d2b6:
    TR(0x0d2b6); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:48e6 ret  */

/* ---- f_089d_48e7 */
L0d2b7:
    TR(0x0d2b7); CYC(40); /* 089d:48e7 cmp word ptr [bx + 0x6274], 0x137 */
    TR(0x0d2bd); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x6274)) > (int16_t)0x137) goto L0d30a; /* 089d:48ed jg 0xd30a */
    TR(0x0d2bf); CYC(40); /* 089d:48ef cmp word ptr [bx + 0x6274], 0 */
    TR(0x0d2c4); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x6274)) < (int16_t)0x0) goto L0d30a; /* 089d:48f4 jl 0xd30a */
    TR(0x0d2c6); CYC(362); AX = RW(DS_, (uint16_t)(BX + 0x62cc)); /* 089d:48f6 mov ax, word ptr [bx + 0x62cc] */
    TR(0x0d2ca); { uint16_t a_ = AX; unsigned n_ = 1 & 0x1f; AX = (uint16_t)((int16_t)a_ >> n_); } /* 089d:48fa sar ax, 1 */
    TR(0x0d2cc); PUSH(BX); /* 089d:48fc push bx */
    TR(0x0d2cd); PUSH(CX); /* 089d:48fd push cx */
    TR(0x0d2ce); PUSH(DX); /* 089d:48fe push dx */
    TR(0x0d2cf); PUSH(SI); /* 089d:48ff push si */
    TR(0x0d2d0); PUSH(DI); /* 089d:4900 push di */
    TR(0x0d2d1); AX = AX; /* 089d:4901 mov ax, ax */
    TR(0x0d2d3); AX += AX; /* 089d:4903 add ax, ax */
    TR(0x0d2d5); DI = AX; /* 089d:4905 mov di, ax */
    TR(0x0d2d7); SI = RW(DS_, (uint16_t)(DI + 0x859d)); /* 089d:4907 mov si, word ptr [di - 0x7a63] */
    TR(0x0d2db); DL = RB(DS_, SI); /* 089d:490b mov dl, byte ptr [si] */
    TR(0x0d2dd); DH = DL; /* 089d:490d mov dh, dl */
    TR(0x0d2df); SI++; /* 089d:490f inc si */
    TR(0x0d2e0); CH = RB(DS_, SI); /* 089d:4910 mov ch, byte ptr [si] */
    TR(0x0d2e2); SI++; /* 089d:4912 inc si */
    TR(0x0d2e3); WW(DS_, 0x36, SI); /* 089d:4913 mov word ptr [0x36], si */
    TR(0x0d2e7); AX = RW(DS_, (uint16_t)(BX + 0x628a)); /* 089d:4917 mov ax, word ptr [bx + 0x628a] */
    TR(0x0d2eb); WW(DS_, 0x2e, AX); /* 089d:491b mov word ptr [0x2e], ax */
    TR(0x0d2ee); BX = RW(DS_, (uint16_t)(BX + 0x6274)); /* 089d:491e mov bx, word ptr [bx + 0x6274] */
    TR(0x0d2f2); AX = RW(DS_, (uint16_t)(BX + 0x680e)); /* 089d:4922 mov ax, word ptr [bx + 0x680e] */
    TR(0x0d2f6); AH = 0x0; /* 089d:4926 mov ah, 0 */
    TR(0x0d2f8); WW(DS_, 0x2c, AX); /* 089d:4928 mov word ptr [0x2c], ax */
    TR(0x0d2fb); AX = RW(DS_, (uint16_t)(BX + 0x695c)); /* 089d:492b mov ax, word ptr [bx + 0x695c] */
    TR(0x0d2ff); WW(DS_, 0x3a, AX); /* 089d:492f mov word ptr [0x3a], ax */
    TR(0x0d302); PUSH(0x4935); goto L0ae25; /* 089d:4932 call 0xae25 */
L0d305:
    TR(0x0d305); CYC(60); DI = POP(); /* 089d:4935 pop di */
    TR(0x0d306); SI = POP(); /* 089d:4936 pop si */
    TR(0x0d307); DX = POP(); /* 089d:4937 pop dx */
    TR(0x0d308); CX = POP(); /* 089d:4938 pop cx */
    TR(0x0d309); BX = POP(); /* 089d:4939 pop bx */
L0d30a:
    TR(0x0d30a); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:493a ret  */

/* ---- f_089d_493b */
L0d30b:
    TR(0x0d30b); CYC(40); /* 089d:493b cmp word ptr [0x6308], 1 */
    TR(0x0d310); if (RW(DS_, 0x6308) == 0x1) goto L0d313; /* 089d:4940 je 0xd313 */
    TR(0x0d312); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:4942 ret  */
L0d313:
    TR(0x0d313); CYC(40); /* 089d:4943 cmp word ptr [0x6306], 1 */
    TR(0x0d318); if (RW(DS_, 0x6306) == 0x1) goto L0d31b; /* 089d:4948 je 0xd31b */
    TR(0x0d31a); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:494a ret  */
L0d31b:
    TR(0x0d31b); CYC(23); PUSH(0x494e); goto L0d4a6; /* 089d:494b call 0xd4a6 */
L0d31e:
    TR(0x0d31e); CYC(184); AX = RW(DS_, 0x4a); /* 089d:494e mov ax, word ptr [0x4a] */
    TR(0x0d321); AX = (uint16_t)(0u - AX); /* 089d:4951 neg ax */
    TR(0x0d323); AX += RW(DS_, 0x630a); /* 089d:4953 add ax, word ptr [0x630a] */
    TR(0x0d327); WW(DS_, 0x6302, (uint16_t)(RW(DS_, 0x6302) + AX)); /* 089d:4957 add word ptr [0x6302], ax */
    TR(0x0d32b); AX = RW(DS_, 0x630c); /* 089d:495b mov ax, word ptr [0x630c] */
    TR(0x0d32e); WW(DS_, 0x6304, (uint16_t)(RW(DS_, 0x6304) + AX)); /* 089d:495e add word ptr [0x6304], ax */
    TR(0x0d332); WW(DS_, 0x630c, (uint16_t)(RW(DS_, 0x630c) + 1)); /* 089d:4962 inc word ptr [0x630c] */
    TR(0x0d336); /* 089d:4966 cmp word ptr [0x6304], 0x89 */
    TR(0x0d33c); if ((int16_t)RW(DS_, 0x6304) < (int16_t)0x89) goto L0d356; /* 089d:496c jl 0xd356 */
L0d33e:
    TR(0x0d33e); CYC(23); PUSH(0x4971); goto L0b412; /* 089d:496e call 0xb412 */
L0d341:
    TR(0x0d341); CYC(20); /* 089d:4971 cmp al, 0 */
    TR(0x0d343); if (AL == 0x0) goto L0d33e; /* 089d:4973 je 0xd33e */
    TR(0x0d345); CYC(20); /* 089d:4975 cmp al, 0xf */
    TR(0x0d347); if (AL >= 0xf) goto L0d33e; /* 089d:4977 jae 0xd33e */
    TR(0x0d349); CYC(58); AH = 0x0; /* 089d:4979 mov ah, 0 */
    TR(0x0d34b); AX = (uint16_t)(0u - AX); /* 089d:497b neg ax */
    TR(0x0d34d); WW(DS_, 0x630c, AX); /* 089d:497d mov word ptr [0x630c], ax */
    TR(0x0d350); WW(DS_, 0x6304, 0x89); /* 089d:4980 mov word ptr [0x6304], 0x89 */
L0d356:
    TR(0x0d356); CYC(40); /* 089d:4986 cmp word ptr [0x6302], 0 */
    TR(0x0d35b); if ((int16_t)RW(DS_, 0x6302) < (int16_t)0x0) goto L0d37a; /* 089d:498b jl 0xd37a */
    TR(0x0d35d); CYC(40); /* 089d:498d cmp word ptr [0x6302], 0x113 */
    TR(0x0d363); if ((int16_t)RW(DS_, 0x6302) > (int16_t)0x113) goto L0d37a; /* 089d:4993 jg 0xd37a */
    TR(0x0d365); CYC(82); WW(DS_, 0x630a, 0xfff8); /* 089d:4995 mov word ptr [0x630a], 0xfff8 */
    TR(0x0d36b); AX = RW(DS_, 0x4170); /* 089d:499b mov ax, word ptr [0x4170] */
    TR(0x0d36e); /* 089d:499e cmp word ptr [0x6302], ax */
    TR(0x0d372); if ((int16_t)RW(DS_, 0x6302) > (int16_t)AX) goto L0d37a; /* 089d:49a2 jg 0xd37a */
    TR(0x0d374); CYC(24); WW(DS_, 0x630a, 0x8); /* 089d:49a4 mov word ptr [0x630a], 8 */
L0d37a:
    TR(0x0d37a); CYC(23); PUSH(0x49ad); goto L0d4a6; /* 089d:49aa call 0xd4a6 */
L0d37d:
    TR(0x0d37d); CYC(67); WW(DS_, 0x6310, (uint16_t)(RW(DS_, 0x6310) - 1)); /* 089d:49ad dec word ptr [0x6310] */
    TR(0x0d381); /* 089d:49b1 cmp word ptr [0x6310], 0 */
    TR(0x0d386); if (RW(DS_, 0x6310) != 0x0) goto L0d3ad; /* 089d:49b6 jne 0xd3ad */
L0d388:
    TR(0x0d388); CYC(23); PUSH(0x49bb); goto L0b412; /* 089d:49b8 call 0xb412 */
L0d38b:
    TR(0x0d38b); CYC(20); /* 089d:49bb cmp al, 0 */
    TR(0x0d38d); if (AL == 0x0) goto L0d388; /* 089d:49bd je 0xd388 */
    TR(0x0d38f); CYC(20); /* 089d:49bf cmp al, 0x32 */
    TR(0x0d391); if (AL >= 0x32) goto L0d388; /* 089d:49c1 jae 0xd388 */
    TR(0x0d393); CYC(134); AH = 0x0; /* 089d:49c3 mov ah, 0 */
    TR(0x0d395); WW(DS_, 0x6310, AX); /* 089d:49c5 mov word ptr [0x6310], ax */
    TR(0x0d398); AX = RW(DS_, 0x6302); /* 089d:49c8 mov ax, word ptr [0x6302] */
    TR(0x0d39b); WW(DS_, 0x6194, AX); /* 089d:49cb mov word ptr [0x6194], ax */
    TR(0x0d39e); AX = RW(DS_, 0x6304); /* 089d:49ce mov ax, word ptr [0x6304] */
    TR(0x0d3a1); AX += 0xe; /* 089d:49d1 add ax, 0xe */
    TR(0x0d3a4); WW(DS_, 0x6196, AX); /* 089d:49d4 mov word ptr [0x6196], ax */
    TR(0x0d3a7); WW(DS_, 0x6192, 0x1); /* 089d:49d7 mov word ptr [0x6192], 1 */
L0d3ad:
    TR(0x0d3ad); CYC(45); PUSH(CX); /* 089d:49dd push cx */
    TR(0x0d3ae); CX = RW(DS_, 0x5062); /* 089d:49de mov cx, word ptr [0x5062] */
    TR(0x0d3b2); SI = 0x0; /* 089d:49e2 mov si, 0 */
L0d3b5:
    TR(0x0d3b5); CYC(40); /* 089d:49e5 cmp word ptr [si + 0x501e], 0 */
    TR(0x0d3ba); if (RW(DS_, (uint16_t)(SI + 0x501e)) == 0x0) goto L0d41b; /* 089d:49ea je 0xd41b */
    TR(0x0d3bc); CYC(58); AX = RW(DS_, 0x6302); /* 089d:49ec mov ax, word ptr [0x6302] */
    TR(0x0d3bf); /* 089d:49ef cmp word ptr [si + 0x4ff6], ax */
    TR(0x0d3c3); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x4ff6)) < (int16_t)AX) goto L0d41b; /* 089d:49f3 jl 0xd41b */
    TR(0x0d3c5); CYC(52); AX += 0x2c; /* 089d:49f5 add ax, 0x2c */
    TR(0x0d3c8); /* 089d:49f8 cmp word ptr [si + 0x4ff6], ax */
    TR(0x0d3cc); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x4ff6)) > (int16_t)AX) goto L0d41b; /* 089d:49fc jg 0xd41b */
    TR(0x0d3ce); CYC(58); AX = RW(DS_, 0x6304); /* 089d:49fe mov ax, word ptr [0x6304] */
    TR(0x0d3d1); /* 089d:4a01 cmp word ptr [si + 0x500a], ax */
    TR(0x0d3d5); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) < (int16_t)AX) goto L0d41b; /* 089d:4a05 jl 0xd41b */
    TR(0x0d3d7); CYC(58); AX = RW(DS_, 0x6304); /* 089d:4a07 mov ax, word ptr [0x6304] */
    TR(0x0d3da); /* 089d:4a0a cmp word ptr [si + 0x500a], ax */
    TR(0x0d3de); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) < (int16_t)AX) goto L0d41b; /* 089d:4a0e jl 0xd41b */
    TR(0x0d3e0); CYC(52); AX += 0x2b; /* 089d:4a10 add ax, 0x2b */
    TR(0x0d3e3); /* 089d:4a13 cmp word ptr [si + 0x500a], ax */
    TR(0x0d3e7); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) > (int16_t)AX) goto L0d41b; /* 089d:4a17 jg 0xd41b */
    TR(0x0d3e9); CYC(40); /* 089d:4a19 cmp word ptr [si + 0x501e], 1 */
    TR(0x0d3ee); if (RW(DS_, (uint16_t)(SI + 0x501e)) != 0x1) goto L0d3fa; /* 089d:4a1e jne 0xd3fa */
    TR(0x0d3f0); CYC(46); PUSH(BX); /* 089d:4a20 push bx */
    TR(0x0d3f1); BX = SI; /* 089d:4a21 mov bx, si */
    TR(0x0d3f3); PUSH(0x4a26); goto L0b66e; /* 089d:4a23 call 0xb66e */
L0d3f6:
    TR(0x0d3f6); CYC(27); BX = POP(); /* 089d:4a26 pop bx */
    TR(0x0d3f7); goto L0d401; /* 089d:4a27 jmp 0xd401 */
L0d3fa:
    TR(0x0d3fa); CYC(46); PUSH(BX); /* 089d:4a2a push bx */
    TR(0x0d3fb); BX = SI; /* 089d:4a2b mov bx, si */
    TR(0x0d3fd); PUSH(0x4a30); goto L0c6c3; /* 089d:4a2d call 0xc6c3 */
L0d400:
    TR(0x0d400); CYC(12); BX = POP(); /* 089d:4a30 pop bx */
L0d401:
    TR(0x0d401); CYC(115); WW(DS_, (uint16_t)(SI + 0x501e), 0x0); /* 089d:4a31 mov word ptr [si + 0x501e], 0 */
    TR(0x0d407); WW(DS_, 0x630c, 0xfffb); /* 089d:4a37 mov word ptr [0x630c], 0xfffb */
    TR(0x0d40d); WW(DS_, 0x630e, (uint16_t)(RW(DS_, 0x630e) - 1)); /* 089d:4a3d dec word ptr [0x630e] */
    TR(0x0d411); /* 089d:4a41 cmp word ptr [0x630e], 0 */
    TR(0x0d416); if (RW(DS_, 0x630e) != 0x0) goto L0d424; /* 089d:4a46 jne 0xd424 */
    TR(0x0d418); CYC(15); goto L0d468; /* 089d:4a48 jmp 0xd468 */
L0d41b:
    TR(0x0d41b); CYC(25); SI++; /* 089d:4a4b inc si */
    TR(0x0d41c); SI++; /* 089d:4a4c inc si */
    TR(0x0d41d); if (--CX) goto L0d422; /* 089d:4a4d loop 0xd422 */
    TR(0x0d41f); CYC(15); goto L0d424; /* 089d:4a4f jmp 0xd424 */
L0d422:
    TR(0x0d422); CYC(15); goto L0d3b5; /* 089d:4a52 jmp 0xd3b5 */
L0d424:
    TR(0x0d424); CYC(52); CX = POP(); /* 089d:4a54 pop cx */
    TR(0x0d425); { uint16_t a_ = RW(DS_, 0x4176), b_ = 0x1; unsigned r_ = (unsigned)a_ - b_;   ZF = ((r_ & 0xffff) == 0); } /* 089d:4a55 cmp word ptr [0x4176], 1 */
    TR(0x0d42a); if (!ZF) goto L0d467; /* 089d:4a5a jne 0xd467 */
    TR(0x0d42c); CYC(12); if (!ZF) goto L0d467; /* 089d:4a5c jne 0xd467 */
    TR(0x0d42e); CYC(80); AX = RW(DS_, 0x4170); /* 089d:4a5e mov ax, word ptr [0x4170] */
    TR(0x0d431); DX = RW(DS_, 0x6302); /* 089d:4a61 mov dx, word ptr [0x6302] */
    TR(0x0d435); DX += 0xc; /* 089d:4a65 add dx, 0xc */
    TR(0x0d438); AX += 0x14; /* 089d:4a68 add ax, 0x14 */
    TR(0x0d43b); /* 089d:4a6b cmp ax, dx */
    TR(0x0d43d); if ((int16_t)AX < (int16_t)DX) goto L0d467; /* 089d:4a6d jl 0xd467 */
    TR(0x0d43f); CYC(44); AX -= 0x14; /* 089d:4a6f sub ax, 0x14 */
    TR(0x0d442); DX += 0x10; /* 089d:4a72 add dx, 0x10 */
    TR(0x0d445); /* 089d:4a75 cmp ax, dx */
    TR(0x0d447); if ((int16_t)AX > (int16_t)DX) goto L0d467; /* 089d:4a77 jg 0xd467 */
    TR(0x0d449); CYC(68); AX = RW(DS_, 0x4172); /* 089d:4a79 mov ax, word ptr [0x4172] */
    TR(0x0d44c); DX = RW(DS_, 0x6304); /* 089d:4a7c mov dx, word ptr [0x6304] */
    TR(0x0d450); AX += 0xe; /* 089d:4a80 add ax, 0xe */
    TR(0x0d453); /* 089d:4a83 cmp ax, dx */
    TR(0x0d455); if ((int16_t)AX < (int16_t)DX) goto L0d467; /* 089d:4a85 jl 0xd467 */
    TR(0x0d457); CYC(44); AX -= 0xe; /* 089d:4a87 sub ax, 0xe */
    TR(0x0d45a); DX += 0x2b; /* 089d:4a8a add dx, 0x2b */
    TR(0x0d45d); /* 089d:4a8d cmp ax, dx */
    TR(0x0d45f); if ((int16_t)AX > (int16_t)DX) goto L0d467; /* 089d:4a8f jg 0xd467 */
    TR(0x0d461); CYC(24); WW(DS_, 0x5360, 0x1); /* 089d:4a91 mov word ptr [0x5360], 1 */
L0d467:
    TR(0x0d467); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:4a97 ret  */
L0d468:
    TR(0x0d468); CYC(12); CX = 0x4; /* 089d:4a98 mov cx, 4 */
L0d46b:
    TR(0x0d46b); CYC(71); WW(DS_, 0x68, 0x1f); /* 089d:4a9b mov word ptr [0x68], 0x1f */
    TR(0x0d471); WW(DS_, 0x6a, 0x2); /* 089d:4aa1 mov word ptr [0x6a], 2 */
    TR(0x0d477); PUSH(0x4aaa); goto L0b172; /* 089d:4aa7 call 0xb172 */
L0d47a:
    TR(0x0d47a); CYC(12); DX = 0x2710; /* 089d:4aaa mov dx, 0x2710 */
L0d47d:
    TR(0x0d47d); CYC(28); DX--; /* 089d:4aad dec dx */
    TR(0x0d47e); /* 089d:4aae cmp dx, 0 */
    TR(0x0d481); if (DX != 0x0) goto L0d47d; /* 089d:4ab1 jne 0xd47d */
    TR(0x0d483); CYC(71); WW(DS_, 0x68, 0x10); /* 089d:4ab3 mov word ptr [0x68], 0x10 */
    TR(0x0d489); WW(DS_, 0x6a, 0x2); /* 089d:4ab9 mov word ptr [0x6a], 2 */
    TR(0x0d48f); PUSH(0x4ac2); goto L0b172; /* 089d:4abf call 0xb172 */
L0d492:
    TR(0x0d492); CYC(17); if (--CX) goto L0d46b; /* 089d:4ac2 loop 0xd46b */
    TR(0x0d494); CYC(47); WW(DS_, 0x6306, 0x0); /* 089d:4ac4 mov word ptr [0x6306], 0 */
    TR(0x0d49a); PUSH(0x4acd); goto L0d4a6; /* 089d:4aca call 0xd4a6 */
L0d49d:
    TR(0x0d49d); CYC(35); AX = 0x3e8; /* 089d:4acd mov ax, 0x3e8 */
    TR(0x0d4a0); PUSH(0x4ad3); goto L0b829; /* 089d:4ad0 call 0xb829 */
L0d4a3:
    TR(0x0d4a3); CYC(15); goto L0d424; /* 089d:4ad3 jmp 0xd424 */

/* ---- f_089d_4ad6 */
L0d4a6:
    TR(0x0d4a6); CYC(40); /* 089d:4ad6 cmp word ptr [0x6302], 0x113 */
    TR(0x0d4ac); if ((int16_t)RW(DS_, 0x6302) > (int16_t)0x113) goto L0d4f3; /* 089d:4adc jg 0xd4f3 */
    TR(0x0d4ae); CYC(40); /* 089d:4ade cmp word ptr [0x6302], 0 */
    TR(0x0d4b3); if ((int16_t)RW(DS_, 0x6302) < (int16_t)0x0) goto L0d4f3; /* 089d:4ae3 jl 0xd4f3 */
    TR(0x0d4b5); CYC(340); PUSH(BX); /* 089d:4ae5 push bx */
    TR(0x0d4b6); PUSH(CX); /* 089d:4ae6 push cx */
    TR(0x0d4b7); PUSH(DX); /* 089d:4ae7 push dx */
    TR(0x0d4b8); PUSH(SI); /* 089d:4ae8 push si */
    TR(0x0d4b9); PUSH(DI); /* 089d:4ae9 push di */
    TR(0x0d4ba); AX = 0x0; /* 089d:4aea mov ax, 0 */
    TR(0x0d4bd); AX += AX; /* 089d:4aed add ax, ax */
    TR(0x0d4bf); DI = AX; /* 089d:4aef mov di, ax */
    TR(0x0d4c1); SI = RW(DS_, (uint16_t)(DI + 0x85d9)); /* 089d:4af1 mov si, word ptr [di - 0x7a27] */
    TR(0x0d4c5); DL = RB(DS_, SI); /* 089d:4af5 mov dl, byte ptr [si] */
    TR(0x0d4c7); DH = DL; /* 089d:4af7 mov dh, dl */
    TR(0x0d4c9); SI++; /* 089d:4af9 inc si */
    TR(0x0d4ca); CH = RB(DS_, SI); /* 089d:4afa mov ch, byte ptr [si] */
    TR(0x0d4cc); SI++; /* 089d:4afc inc si */
    TR(0x0d4cd); WW(DS_, 0x36, SI); /* 089d:4afd mov word ptr [0x36], si */
    TR(0x0d4d1); AX = RW(DS_, 0x6304); /* 089d:4b01 mov ax, word ptr [0x6304] */
    TR(0x0d4d4); WW(DS_, 0x2e, AX); /* 089d:4b04 mov word ptr [0x2e], ax */
    TR(0x0d4d7); BX = RW(DS_, 0x6302); /* 089d:4b07 mov bx, word ptr [0x6302] */
    TR(0x0d4db); AX = RW(DS_, (uint16_t)(BX + 0x680e)); /* 089d:4b0b mov ax, word ptr [bx + 0x680e] */
    TR(0x0d4df); AH = 0x0; /* 089d:4b0f mov ah, 0 */
    TR(0x0d4e1); WW(DS_, 0x2c, AX); /* 089d:4b11 mov word ptr [0x2c], ax */
    TR(0x0d4e4); AX = RW(DS_, (uint16_t)(BX + 0x695c)); /* 089d:4b14 mov ax, word ptr [bx + 0x695c] */
    TR(0x0d4e8); WW(DS_, 0x3a, AX); /* 089d:4b18 mov word ptr [0x3a], ax */
    TR(0x0d4eb); PUSH(0x4b1e); goto L0ae25; /* 089d:4b1b call 0xae25 */
L0d4ee:
    TR(0x0d4ee); CYC(60); DI = POP(); /* 089d:4b1e pop di */
    TR(0x0d4ef); SI = POP(); /* 089d:4b1f pop si */
    TR(0x0d4f0); DX = POP(); /* 089d:4b20 pop dx */
    TR(0x0d4f1); CX = POP(); /* 089d:4b21 pop cx */
    TR(0x0d4f2); BX = POP(); /* 089d:4b22 pop bx */
L0d4f3:
    TR(0x0d4f3); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:4b23 ret  */

/* ---- f_089d_4b24 */
L0d4f4:
    TR(0x0d4f4); CYC(40); /* 089d:4b24 cmp word ptr [bx + 0x63be], 0x137 */
    TR(0x0d4fa); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x63be)) > (int16_t)0x137) goto L0d545; /* 089d:4b2a jg 0xd545 */
    TR(0x0d4fc); CYC(40); /* 089d:4b2c cmp word ptr [bx + 0x63be], 0 */
    TR(0x0d501); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x63be)) < (int16_t)0x0) goto L0d545; /* 089d:4b31 jl 0xd545 */
    TR(0x0d503); CYC(354); AX = RW(DS_, (uint16_t)(BX + 0x6422)); /* 089d:4b33 mov ax, word ptr [bx + 0x6422] */
    TR(0x0d507); PUSH(BX); /* 089d:4b37 push bx */
    TR(0x0d508); PUSH(CX); /* 089d:4b38 push cx */
    TR(0x0d509); PUSH(DX); /* 089d:4b39 push dx */
    TR(0x0d50a); PUSH(SI); /* 089d:4b3a push si */
    TR(0x0d50b); PUSH(DI); /* 089d:4b3b push di */
    TR(0x0d50c); AX = AX; /* 089d:4b3c mov ax, ax */
    TR(0x0d50e); AX += AX; /* 089d:4b3e add ax, ax */
    TR(0x0d510); DI = AX; /* 089d:4b40 mov di, ax */
    TR(0x0d512); SI = RW(DS_, (uint16_t)(DI + 0x87b6)); /* 089d:4b42 mov si, word ptr [di - 0x784a] */
    TR(0x0d516); DL = RB(DS_, SI); /* 089d:4b46 mov dl, byte ptr [si] */
    TR(0x0d518); DH = DL; /* 089d:4b48 mov dh, dl */
    TR(0x0d51a); SI++; /* 089d:4b4a inc si */
    TR(0x0d51b); CH = RB(DS_, SI); /* 089d:4b4b mov ch, byte ptr [si] */
    TR(0x0d51d); SI++; /* 089d:4b4d inc si */
    TR(0x0d51e); WW(DS_, 0x36, SI); /* 089d:4b4e mov word ptr [0x36], si */
    TR(0x0d522); AX = RW(DS_, (uint16_t)(BX + 0x65b2)); /* 089d:4b52 mov ax, word ptr [bx + 0x65b2] */
    TR(0x0d526); WW(DS_, 0x2e, AX); /* 089d:4b56 mov word ptr [0x2e], ax */
    TR(0x0d529); BX = RW(DS_, (uint16_t)(BX + 0x63be)); /* 089d:4b59 mov bx, word ptr [bx + 0x63be] */
    TR(0x0d52d); AX = RW(DS_, (uint16_t)(BX + 0x680e)); /* 089d:4b5d mov ax, word ptr [bx + 0x680e] */
    TR(0x0d531); AH = 0x0; /* 089d:4b61 mov ah, 0 */
    TR(0x0d533); WW(DS_, 0x2c, AX); /* 089d:4b63 mov word ptr [0x2c], ax */
    TR(0x0d536); AX = RW(DS_, (uint16_t)(BX + 0x695c)); /* 089d:4b66 mov ax, word ptr [bx + 0x695c] */
    TR(0x0d53a); WW(DS_, 0x3a, AX); /* 089d:4b6a mov word ptr [0x3a], ax */
    TR(0x0d53d); PUSH(0x4b70); goto L0ae25; /* 089d:4b6d call 0xae25 */
L0d540:
    TR(0x0d540); CYC(60); DI = POP(); /* 089d:4b70 pop di */
    TR(0x0d541); SI = POP(); /* 089d:4b71 pop si */
    TR(0x0d542); DX = POP(); /* 089d:4b72 pop dx */
    TR(0x0d543); CX = POP(); /* 089d:4b73 pop cx */
    TR(0x0d544); BX = POP(); /* 089d:4b74 pop bx */
L0d545:
    TR(0x0d545); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:4b75 ret  */

/* ---- f_089d_4b76 */
L0d546:
    TR(0x0d546); CYC(40); /* 089d:4b76 cmp word ptr [0x667c], 1 */
    TR(0x0d54b); if (RW(DS_, 0x667c) == 0x1) goto L0d54e; /* 089d:4b7b je 0xd54e */
    TR(0x0d54d); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:4b7d ret  */
L0d54e:
    TR(0x0d54e); CYC(30); CX = RW(DS_, 0x667a); /* 089d:4b7e mov cx, word ptr [0x667a] */
    TR(0x0d552); BX = 0x0; /* 089d:4b82 mov bx, 0 */
L0d555:
    TR(0x0d555); CYC(40); /* 089d:4b85 cmp word ptr [bx + 0x6486], 0 */
    TR(0x0d55a); if (RW(DS_, (uint16_t)(BX + 0x6486)) == 0x0) goto L0d55f; /* 089d:4b8a je 0xd55f */
    TR(0x0d55c); CYC(23); PUSH(0x4b8f); goto L0d564; /* 089d:4b8c call 0xd564 */
L0d55f:
    TR(0x0d55f); CYC(25); BX++; /* 089d:4b8f inc bx */
    TR(0x0d560); BX++; /* 089d:4b90 inc bx */
    TR(0x0d561); if (--CX) goto L0d555; /* 089d:4b91 loop 0xd555 */
    TR(0x0d563); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:4b93 ret  */

/* ---- f_089d_4b94 */
L0d564:
    TR(0x0d564); CYC(23); PUSH(0x4b97); goto L0d4f4; /* 089d:4b94 call 0xd4f4 */
L0d567:
    TR(0x0d567); CYC(157); AX = RW(DS_, 0x4a); /* 089d:4b97 mov ax, word ptr [0x4a] */
    TR(0x0d56a); AX = (uint16_t)(0u - AX); /* 089d:4b9a neg ax */
    TR(0x0d56c); AX += RW(DS_, (uint16_t)(BX + 0x654e)); /* 089d:4b9c add ax, word ptr [bx + 0x654e] */
    TR(0x0d570); WW(DS_, (uint16_t)(BX + 0x63be), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x63be)) + AX)); /* 089d:4ba0 add word ptr [bx + 0x63be], ax */
    TR(0x0d574); AX = RW(DS_, (uint16_t)(BX + 0x64ea)); /* 089d:4ba4 mov ax, word ptr [bx + 0x64ea] */
    TR(0x0d578); WW(DS_, (uint16_t)(BX + 0x65b2), (uint16_t)(RW(DS_, (uint16_t)(BX + 0x65b2)) + AX)); /* 089d:4ba8 add word ptr [bx + 0x65b2], ax */
    TR(0x0d57c); /* 089d:4bac cmp word ptr [bx + 0x63be], 0 */
    TR(0x0d581); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x63be)) >= (int16_t)0x0) goto L0d589; /* 089d:4bb1 jge 0xd589 */
    TR(0x0d583); CYC(24); WW(DS_, (uint16_t)(BX + 0x63be), 0x18ec); /* 089d:4bb3 mov word ptr [bx + 0x63be], 0x18ec */
L0d589:
    TR(0x0d589); CYC(40); /* 089d:4bb9 cmp word ptr [bx + 0x63be], 0x18ec */
    TR(0x0d58f); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x63be)) <= (int16_t)0x18ec) goto L0d597; /* 089d:4bbf jle 0xd597 */
    TR(0x0d591); CYC(24); WW(DS_, (uint16_t)(BX + 0x63be), 0x0); /* 089d:4bc1 mov word ptr [bx + 0x63be], 0 */
L0d597:
    TR(0x0d597); CYC(40); /* 089d:4bc7 cmp word ptr [bx + 0x65b2], 0x14 */
    TR(0x0d59c); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x65b2)) > (int16_t)0x14) goto L0d5a4; /* 089d:4bcc jg 0xd5a4 */
    TR(0x0d59e); CYC(24); WW(DS_, (uint16_t)(BX + 0x64ea), 0x1); /* 089d:4bce mov word ptr [bx + 0x64ea], 1 */
L0d5a4:
    TR(0x0d5a4); CYC(40); /* 089d:4bd4 cmp word ptr [bx + 0x65b2], 0xb0 */
    TR(0x0d5aa); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x65b2)) < (int16_t)0xb0) goto L0d5b2; /* 089d:4bda jl 0xd5b2 */
    TR(0x0d5ac); CYC(24); WW(DS_, (uint16_t)(BX + 0x64ea), 0xffff); /* 089d:4bdc mov word ptr [bx + 0x64ea], 0xffff */
L0d5b2:
    TR(0x0d5b2); CYC(23); PUSH(0x4be5); goto L0b412; /* 089d:4be2 call 0xb412 */
L0d5b5:
    TR(0x0d5b5); CYC(20); /* 089d:4be5 cmp al, 5 */
    TR(0x0d5b7); if (AL >= 0x5) goto L0d5bd; /* 089d:4be7 jae 0xd5bd */
    TR(0x0d5b9); CYC(24); WW(DS_, (uint16_t)(BX + 0x64ea), (uint16_t)(0u - RW(DS_, (uint16_t)(BX + 0x64ea)))); /* 089d:4be9 neg word ptr [bx + 0x64ea] */
L0d5bd:
    TR(0x0d5bd); CYC(20); /* 089d:4bed cmp al, 0xa */
    TR(0x0d5bf); if (AL >= 0xa) goto L0d5d8; /* 089d:4bef jae 0xd5d8 */
    TR(0x0d5c1); CYC(88); WW(DS_, (uint16_t)(BX + 0x654e), (uint16_t)(0u - RW(DS_, (uint16_t)(BX + 0x654e)))); /* 089d:4bf1 neg word ptr [bx + 0x654e] */
    TR(0x0d5c5); WW(DS_, (uint16_t)(BX + 0x6422), 0x0); /* 089d:4bf5 mov word ptr [bx + 0x6422], 0 */
    TR(0x0d5cb); /* 089d:4bfb cmp word ptr [bx + 0x654e], 0 */
    TR(0x0d5d0); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x654e)) >= (int16_t)0x0) goto L0d5d8; /* 089d:4c00 jge 0xd5d8 */
    TR(0x0d5d2); CYC(24); WW(DS_, (uint16_t)(BX + 0x6422), 0x1); /* 089d:4c02 mov word ptr [bx + 0x6422], 1 */
L0d5d8:
    TR(0x0d5d8); CYC(23); PUSH(0x4c0b); goto L0d4f4; /* 089d:4c08 call 0xd4f4 */
L0d5db:
    TR(0x0d5db); CYC(45); PUSH(CX); /* 089d:4c0b push cx */
    TR(0x0d5dc); CX = RW(DS_, 0x5062); /* 089d:4c0c mov cx, word ptr [0x5062] */
    TR(0x0d5e0); SI = 0x0; /* 089d:4c10 mov si, 0 */
L0d5e3:
    TR(0x0d5e3); CYC(40); /* 089d:4c13 cmp word ptr [si + 0x501e], 0 */
    TR(0x0d5e8); if (RW(DS_, (uint16_t)(SI + 0x501e)) == 0x0) goto L0d65b; /* 089d:4c18 je 0xd65b */
    TR(0x0d5ea); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x63be)); /* 089d:4c1a mov ax, word ptr [bx + 0x63be] */
    TR(0x0d5ee); /* 089d:4c1e cmp word ptr [si + 0x4ff6], ax */
    TR(0x0d5f2); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x4ff6)) < (int16_t)AX) goto L0d65b; /* 089d:4c22 jl 0xd65b */
    TR(0x0d5f4); CYC(52); AX += 0x10; /* 089d:4c24 add ax, 0x10 */
    TR(0x0d5f7); /* 089d:4c27 cmp word ptr [si + 0x4ff6], ax */
    TR(0x0d5fb); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x4ff6)) > (int16_t)AX) goto L0d65b; /* 089d:4c2b jg 0xd65b */
    TR(0x0d5fd); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x65b2)); /* 089d:4c2d mov ax, word ptr [bx + 0x65b2] */
    TR(0x0d601); /* 089d:4c31 cmp word ptr [si + 0x500a], ax */
    TR(0x0d605); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) < (int16_t)AX) goto L0d65b; /* 089d:4c35 jl 0xd65b */
    TR(0x0d607); CYC(58); AX = RW(DS_, (uint16_t)(BX + 0x65b2)); /* 089d:4c37 mov ax, word ptr [bx + 0x65b2] */
    TR(0x0d60b); /* 089d:4c3b cmp word ptr [si + 0x500a], ax */
    TR(0x0d60f); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) < (int16_t)AX) goto L0d65b; /* 089d:4c3f jl 0xd65b */
    TR(0x0d611); CYC(52); AX += 0x5; /* 089d:4c41 add ax, 5 */
    TR(0x0d614); /* 089d:4c44 cmp word ptr [si + 0x500a], ax */
    TR(0x0d618); if ((int16_t)RW(DS_, (uint16_t)(SI + 0x500a)) > (int16_t)AX) goto L0d65b; /* 089d:4c48 jg 0xd65b */
    TR(0x0d61a); CYC(136); WW(DS_, 0x50d6, 0x1); /* 089d:4c4a mov word ptr [0x50d6], 1 */
    TR(0x0d620); AX = RW(DS_, (uint16_t)(BX + 0x63be)); /* 089d:4c50 mov ax, word ptr [bx + 0x63be] */
    TR(0x0d624); WW(DS_, 0x50d8, AX); /* 089d:4c54 mov word ptr [0x50d8], ax */
    TR(0x0d627); AX = RW(DS_, (uint16_t)(BX + 0x65b2)); /* 089d:4c57 mov ax, word ptr [bx + 0x65b2] */
    TR(0x0d62b); WW(DS_, 0x50da, AX); /* 089d:4c5b mov word ptr [0x50da], ax */
    TR(0x0d62e); /* 089d:4c5e cmp word ptr [si + 0x501e], 1 */
    TR(0x0d633); if (RW(DS_, (uint16_t)(SI + 0x501e)) != 0x1) goto L0d63f; /* 089d:4c63 jne 0xd63f */
    TR(0x0d635); CYC(46); PUSH(BX); /* 089d:4c65 push bx */
    TR(0x0d636); BX = SI; /* 089d:4c66 mov bx, si */
    TR(0x0d638); PUSH(0x4c6b); goto L0b66e; /* 089d:4c68 call 0xb66e */
L0d63b:
    TR(0x0d63b); CYC(27); BX = POP(); /* 089d:4c6b pop bx */
    TR(0x0d63c); goto L0d646; /* 089d:4c6c jmp 0xd646 */
L0d63f:
    TR(0x0d63f); CYC(46); PUSH(BX); /* 089d:4c6f push bx */
    TR(0x0d640); BX = SI; /* 089d:4c70 mov bx, si */
    TR(0x0d642); PUSH(0x4c75); goto L0c6c3; /* 089d:4c72 call 0xc6c3 */
L0d645:
    TR(0x0d645); CYC(12); BX = POP(); /* 089d:4c75 pop bx */
L0d646:
    TR(0x0d646); CYC(71); WW(DS_, (uint16_t)(SI + 0x501e), 0x0); /* 089d:4c76 mov word ptr [si + 0x501e], 0 */
    TR(0x0d64c); WW(DS_, (uint16_t)(BX + 0x6486), 0x0); /* 089d:4c7c mov word ptr [bx + 0x6486], 0 */
    TR(0x0d652); PUSH(0x4c85); goto L0d4f4; /* 089d:4c82 call 0xd4f4 */
L0d655:
    TR(0x0d655); CYC(23); PUSH(0x4c88); goto L0d6c8; /* 089d:4c85 call 0xd6c8 */
L0d658:
    TR(0x0d658); CYC(15); goto L0d665; /* 089d:4c88 jmp 0xd665 */
L0d65b:
    TR(0x0d65b); CYC(25); SI++; /* 089d:4c8b inc si */
    TR(0x0d65c); SI++; /* 089d:4c8c inc si */
    TR(0x0d65d); if (--CX) goto L0d662; /* 089d:4c8d loop 0xd662 */
    TR(0x0d65f); CYC(15); goto L0d665; /* 089d:4c8f jmp 0xd665 */
L0d662:
    TR(0x0d662); CYC(15); goto L0d5e3; /* 089d:4c92 jmp 0xd5e3 */
L0d665:
    TR(0x0d665); CYC(52); CX = POP(); /* 089d:4c95 pop cx */
    TR(0x0d666); /* 089d:4c96 cmp word ptr [0x4176], 1 */
    TR(0x0d66b); if (RW(DS_, 0x4176) != 0x1) goto L0d6c7; /* 089d:4c9b jne 0xd6c7 */
    TR(0x0d66d); CYC(40); /* 089d:4c9d cmp word ptr [bx + 0x6486], 1 */
    TR(0x0d672); if (RW(DS_, (uint16_t)(BX + 0x6486)) != 0x1) goto L0d6c7; /* 089d:4ca2 jne 0xd6c7 */
    TR(0x0d674); CYC(68); AX = RW(DS_, 0x4170); /* 089d:4ca4 mov ax, word ptr [0x4170] */
    TR(0x0d677); DX = RW(DS_, (uint16_t)(BX + 0x63be)); /* 089d:4ca7 mov dx, word ptr [bx + 0x63be] */
    TR(0x0d67b); AX += 0x14; /* 089d:4cab add ax, 0x14 */
    TR(0x0d67e); /* 089d:4cae cmp ax, dx */
    TR(0x0d680); if ((int16_t)AX < (int16_t)DX) goto L0d6c7; /* 089d:4cb0 jl 0xd6c7 */
    TR(0x0d682); CYC(44); AX -= 0x14; /* 089d:4cb2 sub ax, 0x14 */
    TR(0x0d685); DX += 0x8; /* 089d:4cb5 add dx, 8 */
    TR(0x0d688); /* 089d:4cb8 cmp ax, dx */
    TR(0x0d68a); if ((int16_t)AX > (int16_t)DX) goto L0d6c7; /* 089d:4cba jg 0xd6c7 */
    TR(0x0d68c); CYC(68); AX = RW(DS_, 0x4172); /* 089d:4cbc mov ax, word ptr [0x4172] */
    TR(0x0d68f); DX = RW(DS_, (uint16_t)(BX + 0x65b2)); /* 089d:4cbf mov dx, word ptr [bx + 0x65b2] */
    TR(0x0d693); AX += 0xe; /* 089d:4cc3 add ax, 0xe */
    TR(0x0d696); /* 089d:4cc6 cmp ax, dx */
    TR(0x0d698); if ((int16_t)AX < (int16_t)DX) goto L0d6c7; /* 089d:4cc8 jl 0xd6c7 */
    TR(0x0d69a); CYC(44); AX -= 0xe; /* 089d:4cca sub ax, 0xe */
    TR(0x0d69d); DX += 0x4; /* 089d:4ccd add dx, 4 */
    TR(0x0d6a0); /* 089d:4cd0 cmp ax, dx */
    TR(0x0d6a2); if ((int16_t)AX > (int16_t)DX) goto L0d6c7; /* 089d:4cd2 jg 0xd6c7 */
    TR(0x0d6a4); CYC(167); WW(DS_, 0x5360, 0x1); /* 089d:4cd4 mov word ptr [0x5360], 1 */
    TR(0x0d6aa); WW(DS_, 0x50d6, 0x1); /* 089d:4cda mov word ptr [0x50d6], 1 */
    TR(0x0d6b0); AX = RW(DS_, (uint16_t)(BX + 0x63be)); /* 089d:4ce0 mov ax, word ptr [bx + 0x63be] */
    TR(0x0d6b4); WW(DS_, 0x50d8, AX); /* 089d:4ce4 mov word ptr [0x50d8], ax */
    TR(0x0d6b7); AX = RW(DS_, (uint16_t)(BX + 0x65b2)); /* 089d:4ce7 mov ax, word ptr [bx + 0x65b2] */
    TR(0x0d6bb); WW(DS_, 0x50da, AX); /* 089d:4ceb mov word ptr [0x50da], ax */
    TR(0x0d6be); WW(DS_, (uint16_t)(BX + 0x6486), 0x0); /* 089d:4cee mov word ptr [bx + 0x6486], 0 */
    TR(0x0d6c4); PUSH(0x4cf7); goto L0d4f4; /* 089d:4cf4 call 0xd4f4 */
L0d6c7:
    TR(0x0d6c7); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:4cf7 ret  */

/* ---- f_089d_4cf8 */
L0d6c8:
    TR(0x0d6c8); CYC(220); WW(DS_, 0x5160, 0x1); /* 089d:4cf8 mov word ptr [0x5160], 1 */
    TR(0x0d6ce); AX = RW(DS_, (uint16_t)(BX + 0x63be)); /* 089d:4cfe mov ax, word ptr [bx + 0x63be] */
    TR(0x0d6d2); WW(DS_, 0x5162, AX); /* 089d:4d02 mov word ptr [0x5162], ax */
    TR(0x0d6d5); AX = RW(DS_, (uint16_t)(BX + 0x65b2)); /* 089d:4d05 mov ax, word ptr [bx + 0x65b2] */
    TR(0x0d6d9); AX -= 0x5; /* 089d:4d09 sub ax, 5 */
    TR(0x0d6dc); WW(DS_, 0x5164, AX); /* 089d:4d0c mov word ptr [0x5164], ax */
    TR(0x0d6df); WW(DS_, 0x5166, 0x0); /* 089d:4d0f mov word ptr [0x5166], 0 */
    TR(0x0d6e5); AX = RW(DS_, 0x4a); /* 089d:4d15 mov ax, word ptr [0x4a] */
    TR(0x0d6e8); WW(DS_, 0x516a, AX); /* 089d:4d18 mov word ptr [0x516a], ax */
    TR(0x0d6eb); AX = 0x19; /* 089d:4d1b mov ax, 0x19 */
    TR(0x0d6ee); /* 089d:4d1e cmp word ptr [bx + 0x65b2], 0x4b */
    TR(0x0d6f3); if ((int16_t)RW(DS_, (uint16_t)(BX + 0x65b2)) > (int16_t)0x4b) goto L0d6fe; /* 089d:4d23 jg 0xd6fe */
    TR(0x0d6f5); CYC(36); AX = 0x32; /* 089d:4d25 mov ax, 0x32 */
    TR(0x0d6f8); WW(DS_, 0x5166, 0x1); /* 089d:4d28 mov word ptr [0x5166], 1 */
L0d6fe:
    TR(0x0d6fe); CYC(23); PUSH(0x4d31); goto L0b829; /* 089d:4d2e call 0xb829 */
L0d701:
    TR(0x0d701); CYC(20); { uint16_t o_ = POP(); jkey = 0x089d0 + o_; goto dispatch; } /* 089d:4d31 ret  */

dispatch:
    {
        static void *const dtab[0x4d32] = {
            [0x0] = &&L089d0,
            [0x13] = &&L089e3,
            [0x16] = &&L089e6,
            [0x34] = &&L08a04,
            [0x37] = &&L08a07,
            [0x3a] = &&L08a0a,
            [0x3d] = &&L08a0d,
            [0x40] = &&L08a10,
            [0x47] = &&L08a17,
            [0x4a] = &&L08a1a,
            [0x53] = &&L08a23,
            [0x62] = &&L08a32,
            [0x6b] = &&L08a3b,
            [0x72] = &&L08a42,
            [0x82] = &&L08a52,
            [0xa9] = &&L08a79,
            [0xc4] = &&L08a94,
            [0xd6] = &&L08aa6,
            [0xf0] = &&L08ac0,
            [0xf9] = &&L08ac9,
            [0xfa] = &&L08aca,
            [0x101] = &&L08ad1,
            [0x11b] = &&L08aeb,
            [0x12d] = &&L08afd,
            [0x130] = &&L08b00,
            [0x133] = &&L08b03,
            [0x13a] = &&L08b0a,
            [0x154] = &&L08b24,
            [0x15a] = &&L08b2a,
            [0x15d] = &&L08b2d,
            [0x160] = &&L08b30,
            [0x163] = &&L08b33,
            [0x166] = &&L08b36,
            [0x169] = &&L08b39,
            [0x16c] = &&L08b3c,
            [0x16f] = &&L08b3f,
            [0x172] = &&L08b42,
            [0x175] = &&L08b45,
            [0x178] = &&L08b48,
            [0x17b] = &&L08b4b,
            [0x17e] = &&L08b4e,
            [0x181] = &&L08b51,
            [0x184] = &&L08b54,
            [0x187] = &&L08b57,
            [0x18a] = &&L08b5a,
            [0x18d] = &&L08b5d,
            [0x190] = &&L08b60,
            [0x193] = &&L08b63,
            [0x194] = &&L08b64,
            [0x19e] = &&L08b6e,
            [0x1aa] = &&L08b7a,
            [0x1b5] = &&L08b85,
            [0x1ba] = &&L08b8a,
            [0x1c4] = &&L08b94,
            [0x1d0] = &&L08ba0,
            [0x1de] = &&L08bae,
            [0x1f7] = &&L08bc7,
            [0x1fc] = &&L08bcc,
            [0x217] = &&L08be7,
            [0x218] = &&L08be8,
            [0x222] = &&L08bf2,
            [0x22e] = &&L08bfe,
            [0x23c] = &&L08c0c,
            [0x259] = &&L08c29,
            [0x25e] = &&L08c2e,
            [0x271] = &&L08c41,
            [0x284] = &&L08c54,
            [0x28e] = &&L08c5e,
            [0x29a] = &&L08c6a,
            [0x2a8] = &&L08c78,
            [0x2c5] = &&L08c95,
            [0x2ca] = &&L08c9a,
            [0x2e9] = &&L08cb9,
            [0x2f3] = &&L08cc3,
            [0x2ff] = &&L08ccf,
            [0x319] = &&L08ce9,
            [0x326] = &&L08cf6,
            [0x339] = &&L08d09,
            [0x33e] = &&L08d0e,
            [0x345] = &&L08d15,
            [0x34f] = &&L08d1f,
            [0x35b] = &&L08d2b,
            [0x36f] = &&L08d3f,
            [0x37f] = &&L08d4f,
            [0x390] = &&L08d60,
            [0x3a7] = &&L08d77,
            [0x3c0] = &&L08d90,
            [0x3d3] = &&L08da3,
            [0x3dd] = &&L08dad,
            [0x3e9] = &&L08db9,
            [0x3f7] = &&L08dc7,
            [0x410] = &&L08de0,
            [0x415] = &&L08de5,
            [0x41f] = &&L08def,
            [0x42b] = &&L08dfb,
            [0x43f] = &&L08e0f,
            [0x44f] = &&L08e1f,
            [0x468] = &&L08e38,
            [0x46d] = &&L08e3d,
            [0x477] = &&L08e47,
            [0x483] = &&L08e53,
            [0x497] = &&L08e67,
            [0x4a7] = &&L08e77,
            [0x4be] = &&L08e8e,
            [0x4cb] = &&L08e9b,
            [0x4d0] = &&L08ea0,
            [0x4e9] = &&L08eb9,
            [0x4f3] = &&L08ec3,
            [0x4ff] = &&L08ecf,
            [0x50d] = &&L08edd,
            [0x523] = &&L08ef3,
            [0x530] = &&L08f00,
            [0x547] = &&L08f17,
            [0x54c] = &&L08f1c,
            [0x565] = &&L08f35,
            [0x568] = &&L08f38,
            [0x574] = &&L08f44,
            [0x581] = &&L08f51,
            [0x596] = &&L08f66,
            [0x5a5] = &&L08f75,
            [0x5af] = &&L08f7f,
            [0x5bd] = &&L08f8d,
            [0x5c9] = &&L08f99,
            [0x5dd] = &&L08fad,
            [0x5f9] = &&L08fc9,
            [0x620] = &&L08ff0,
            [0x626] = &&L08ff6,
            [0x633] = &&L09003,
            [0x636] = &&L09006,
            [0x651] = &&L09021,
            [0x654] = &&L09024,
            [0x664] = &&L09034,
            [0x667] = &&L09037,
            [0x66a] = &&L0903a,
            [0x66d] = &&L0903d,
            [0x670] = &&L09040,
            [0x673] = &&L09043,
            [0x676] = &&L09046,
            [0x679] = &&L09049,
            [0x67c] = &&L0904c,
            [0x67f] = &&L0904f,
            [0x682] = &&L09052,
            [0x685] = &&L09055,
            [0x688] = &&L09058,
            [0x68b] = &&L0905b,
            [0x68e] = &&L0905e,
            [0x691] = &&L09061,
            [0x694] = &&L09064,
            [0x697] = &&L09067,
            [0x69a] = &&L0906a,
            [0x69d] = &&L0906d,
            [0x6a0] = &&L09070,
            [0x6a3] = &&L09073,
            [0x6a6] = &&L09076,
            [0x6a9] = &&L09079,
            [0x6ac] = &&L0907c,
            [0x6af] = &&L0907f,
            [0x6c0] = &&L09090,
            [0x6c3] = &&L09093,
            [0x6ca] = &&L0909a,
            [0x6da] = &&L090aa,
            [0x6f7] = &&L090c7,
            [0x70e] = &&L090de,
            [0x72b] = &&L090fb,
            [0x73b] = &&L0910b,
            [0x762] = &&L09132,
            [0x774] = &&L09144,
            [0x785] = &&L09155,
            [0x78e] = &&L0915e,
            [0x791] = &&L09161,
            [0x794] = &&L09164,
            [0x7a2] = &&L09172,
            [0x2455] = &&L0ae25,
            [0x2460] = &&L0ae30,
            [0x24b0] = &&L0ae80,
            [0x24bb] = &&L0ae8b,
            [0x24fa] = &&L0aeca,
            [0x2505] = &&L0aed5,
            [0x2544] = &&L0af14,
            [0x257d] = &&L0af4d,
            [0x2583] = &&L0af53,
            [0x2589] = &&L0af59,
            [0x25a8] = &&L0af78,
            [0x25c8] = &&L0af98,
            [0x25e7] = &&L0afb7,
            [0x2607] = &&L0afd7,
            [0x262d] = &&L0affd,
            [0x2637] = &&L0b007,
            [0x2661] = &&L0b031,
            [0x266c] = &&L0b03c,
            [0x2681] = &&L0b051,
            [0x2684] = &&L0b054,
            [0x26b3] = &&L0b083,
            [0x26d9] = &&L0b0a9,
            [0x26ee] = &&L0b0be,
            [0x2701] = &&L0b0d1,
            [0x2714] = &&L0b0e4,
            [0x2719] = &&L0b0e9,
            [0x271b] = &&L0b0eb,
            [0x274e] = &&L0b11e,
            [0x2759] = &&L0b129,
            [0x2785] = &&L0b155,
            [0x2790] = &&L0b160,
            [0x2793] = &&L0b163,
            [0x27a2] = &&L0b172,
            [0x28aa] = &&L0b27a,
            [0x28af] = &&L0b27f,
            [0x28e8] = &&L0b2b8,
            [0x28ee] = &&L0b2be,
            [0x290f] = &&L0b2df,
            [0x2910] = &&L0b2e0,
            [0x291b] = &&L0b2eb,
            [0x2955] = &&L0b325,
            [0x2969] = &&L0b339,
            [0x296c] = &&L0b33c,
            [0x2986] = &&L0b356,
            [0x2987] = &&L0b357,
            [0x29a3] = &&L0b373,
            [0x29c7] = &&L0b397,
            [0x29f7] = &&L0b3c7,
            [0x2a07] = &&L0b3d7,
            [0x2a42] = &&L0b412,
            [0x2a62] = &&L0b432,
            [0x2aaa] = &&L0b47a,
            [0x2ab0] = &&L0b480,
            [0x2aba] = &&L0b48a,
            [0x2ad3] = &&L0b4a3,
            [0x2ad8] = &&L0b4a8,
            [0x2b22] = &&L0b4f2,
            [0x2b6b] = &&L0b53b,
            [0x2b71] = &&L0b541,
            [0x2b8a] = &&L0b55a,
            [0x2b8f] = &&L0b55f,
            [0x2b92] = &&L0b562,
            [0x2bab] = &&L0b57b,
            [0x2bf5] = &&L0b5c5,
            [0x2bff] = &&L0b5cf,
            [0x2c05] = &&L0b5d5,
            [0x2c2d] = &&L0b5fd,
            [0x2c9d] = &&L0b66d,
            [0x2c9e] = &&L0b66e,
            [0x2ce7] = &&L0b6b7,
            [0x2ced] = &&L0b6bd,
            [0x2d06] = &&L0b6d6,
            [0x2d4a] = &&L0b71a,
            [0x2d55] = &&L0b725,
            [0x2d58] = &&L0b728,
            [0x2d87] = &&L0b757,
            [0x2d88] = &&L0b758,
            [0x2dd6] = &&L0b7a6,
            [0x2ddc] = &&L0b7ac,
            [0x2ded] = &&L0b7bd,
            [0x2e20] = &&L0b7f0,
            [0x2e2b] = &&L0b7fb,
            [0x2e2e] = &&L0b7fe,
            [0x2e58] = &&L0b828,
            [0x2e59] = &&L0b829,
            [0x2e68] = &&L0b838,
            [0x2e82] = &&L0b852,
            [0x2eaa] = &&L0b87a,
            [0x2edb] = &&L0b8ab,
            [0x2edf] = &&L0b8af,
            [0x2ef0] = &&L0b8c0,
            [0x2f2b] = &&L0b8fb,
            [0x2f36] = &&L0b906,
            [0x2f39] = &&L0b909,
            [0x2f55] = &&L0b925,
            [0x2f56] = &&L0b926,
            [0x2fa2] = &&L0b972,
            [0x2fa8] = &&L0b978,
            [0x2fd2] = &&L0b9a2,
            [0x2fdc] = &&L0b9ac,
            [0x2ff0] = &&L0b9c0,
            [0x3014] = &&L0b9e4,
            [0x3021] = &&L0b9f1,
            [0x302f] = &&L0b9ff,
            [0x305e] = &&L0ba2e,
            [0x3061] = &&L0ba31,
            [0x3062] = &&L0ba32,
            [0x3065] = &&L0ba35,
            [0x3096] = &&L0ba66,
            [0x3097] = &&L0ba67,
            [0x30ea] = &&L0baba,
            [0x30f0] = &&L0bac0,
            [0x3103] = &&L0bad3,
            [0x311a] = &&L0baea,
            [0x3129] = &&L0baf9,
            [0x314d] = &&L0bb1d,
            [0x32b5] = &&L0bc85,
            [0x32c4] = &&L0bc94,
            [0x32ec] = &&L0bcbc,
            [0x3317] = &&L0bce7,
            [0x3342] = &&L0bd12,
            [0x3366] = &&L0bd36,
            [0x3370] = &&L0bd40,
            [0x337e] = &&L0bd4e,
            [0x337f] = &&L0bd4f,
            [0x3398] = &&L0bd68,
            [0x339d] = &&L0bd6d,
            [0x33a0] = &&L0bd70,
            [0x33ca] = &&L0bd9a,
            [0x3414] = &&L0bde4,
            [0x341e] = &&L0bdee,
            [0x3424] = &&L0bdf4,
            [0x345e] = &&L0be2e,
            [0x34d3] = &&L0bea3,
            [0x34d4] = &&L0bea4,
            [0x351c] = &&L0beec,
            [0x3522] = &&L0bef2,
            [0x353b] = &&L0bf0b,
            [0x3540] = &&L0bf10,
            [0x3543] = &&L0bf13,
            [0x356d] = &&L0bf3d,
            [0x35b7] = &&L0bf87,
            [0x35c1] = &&L0bf91,
            [0x35c7] = &&L0bf97,
            [0x3601] = &&L0bfd1,
            [0x3676] = &&L0c046,
            [0x3677] = &&L0c047,
            [0x36bf] = &&L0c08f,
            [0x36c5] = &&L0c095,
            [0x36d4] = &&L0c0a4,
            [0x36d7] = &&L0c0a7,
            [0x36da] = &&L0c0aa,
            [0x36dd] = &&L0c0ad,
            [0x36de] = &&L0c0ae,
            [0x372c] = &&L0c0fc,
            [0x3732] = &&L0c102,
            [0x374b] = &&L0c11b,
            [0x3750] = &&L0c120,
            [0x3753] = &&L0c123,
            [0x3780] = &&L0c150,
            [0x37aa] = &&L0c17a,
            [0x380a] = &&L0c1da,
            [0x3814] = &&L0c1e4,
            [0x3824] = &&L0c1f4,
            [0x382a] = &&L0c1fa,
            [0x3893] = &&L0c263,
            [0x3894] = &&L0c264,
            [0x3897] = &&L0c267,
            [0x38b0] = &&L0c280,
            [0x38b1] = &&L0c281,
            [0x38f9] = &&L0c2c9,
            [0x38ff] = &&L0c2cf,
            [0x394d] = &&L0c31d,
            [0x3953] = &&L0c323,
            [0x396c] = &&L0c33c,
            [0x3971] = &&L0c341,
            [0x3974] = &&L0c344,
            [0x3a02] = &&L0c3d2,
            [0x3a61] = &&L0c431,
            [0x3a6b] = &&L0c43b,
            [0x3a6e] = &&L0c43e,
            [0x3a77] = &&L0c447,
            [0x3ab0] = &&L0c480,
            [0x3ab1] = &&L0c481,
            [0x3ac2] = &&L0c492,
            [0x3b15] = &&L0c4e5,
            [0x3b20] = &&L0c4f0,
            [0x3b23] = &&L0c4f3,
            [0x3b7c] = &&L0c54c,
            [0x3bd9] = &&L0c5a9,
            [0x3bda] = &&L0c5aa,
            [0x3c24] = &&L0c5f4,
            [0x3c2a] = &&L0c5fa,
            [0x3c77] = &&L0c647,
            [0x3c7d] = &&L0c64d,
            [0x3c8e] = &&L0c65e,
            [0x3cba] = &&L0c68a,
            [0x3cc5] = &&L0c695,
            [0x3cc8] = &&L0c698,
            [0x3cf2] = &&L0c6c2,
            [0x3cf3] = &&L0c6c3,
            [0x3d3c] = &&L0c70c,
            [0x3d42] = &&L0c712,
            [0x3d5b] = &&L0c72b,
            [0x3d9f] = &&L0c76f,
            [0x3daa] = &&L0c77a,
            [0x3dad] = &&L0c77d,
            [0x3dea] = &&L0c7ba,
            [0x3deb] = &&L0c7bb,
            [0x3e33] = &&L0c803,
            [0x3e39] = &&L0c809,
            [0x3e52] = &&L0c822,
            [0x3e57] = &&L0c827,
            [0x3e5a] = &&L0c82a,
            [0x3e73] = &&L0c843,
            [0x3eba] = &&L0c88a,
            [0x3ec4] = &&L0c894,
            [0x3eca] = &&L0c89a,
            [0x3f11] = &&L0c8e1,
            [0x3f5f] = &&L0c92f,
            [0x3f60] = &&L0c930,
            [0x3fac] = &&L0c97c,
            [0x3fb2] = &&L0c982,
            [0x3fcb] = &&L0c99b,
            [0x3fd0] = &&L0c9a0,
            [0x3fd3] = &&L0c9a3,
            [0x403f] = &&L0ca0f,
            [0x409e] = &&L0ca6e,
            [0x40a8] = &&L0ca78,
            [0x40ae] = &&L0ca7e,
            [0x4117] = &&L0cae7,
            [0x4118] = &&L0cae8,
            [0x4161] = &&L0cb31,
            [0x4167] = &&L0cb37,
            [0x4180] = &&L0cb50,
            [0x4185] = &&L0cb55,
            [0x4188] = &&L0cb58,
            [0x41a6] = &&L0cb76,
            [0x41ea] = &&L0cbba,
            [0x4206] = &&L0cbd6,
            [0x4286] = &&L0cc56,
            [0x4290] = &&L0cc60,
            [0x4296] = &&L0cc66,
            [0x42ff] = &&L0cccf,
            [0x4300] = &&L0ccd0,
            [0x4319] = &&L0cce9,
            [0x4349] = &&L0cd19,
            [0x435d] = &&L0cd2d,
            [0x4368] = &&L0cd38,
            [0x436b] = &&L0cd3b,
            [0x4415] = &&L0cde5,
            [0x44b9] = &&L0ce89,
            [0x44c3] = &&L0ce93,
            [0x44d3] = &&L0cea3,
            [0x44d9] = &&L0cea9,
            [0x44e2] = &&L0ceb2,
            [0x4530] = &&L0cf00,
            [0x4536] = &&L0cf06,
            [0x4584] = &&L0cf54,
            [0x458a] = &&L0cf5a,
            [0x45a3] = &&L0cf73,
            [0x45a8] = &&L0cf78,
            [0x45ab] = &&L0cf7b,
            [0x4640] = &&L0d010,
            [0x4682] = &&L0d052,
            [0x46cf] = &&L0d09f,
            [0x46fc] = &&L0d0cc,
            [0x4706] = &&L0d0d6,
            [0x4716] = &&L0d0e6,
            [0x471c] = &&L0d0ec,
            [0x471d] = &&L0d0ed,
            [0x4736] = &&L0d106,
            [0x4770] = &&L0d140,
            [0x477b] = &&L0d14b,
            [0x477e] = &&L0d14e,
            [0x47ea] = &&L0d1ba,
            [0x482b] = &&L0d1fb,
            [0x488b] = &&L0d25b,
            [0x4895] = &&L0d265,
            [0x48a5] = &&L0d275,
            [0x48ab] = &&L0d27b,
            [0x48b4] = &&L0d284,
            [0x48dd] = &&L0d2ad,
            [0x48e6] = &&L0d2b6,
            [0x48e7] = &&L0d2b7,
            [0x4935] = &&L0d305,
            [0x493b] = &&L0d30b,
            [0x494e] = &&L0d31e,
            [0x4971] = &&L0d341,
            [0x49ad] = &&L0d37d,
            [0x49bb] = &&L0d38b,
            [0x4a26] = &&L0d3f6,
            [0x4a30] = &&L0d400,
            [0x4aaa] = &&L0d47a,
            [0x4ac2] = &&L0d492,
            [0x4acd] = &&L0d49d,
            [0x4ad3] = &&L0d4a3,
            [0x4ad6] = &&L0d4a6,
            [0x4b1e] = &&L0d4ee,
            [0x4b24] = &&L0d4f4,
            [0x4b70] = &&L0d540,
            [0x4b76] = &&L0d546,
            [0x4b8f] = &&L0d55f,
            [0x4b94] = &&L0d564,
            [0x4b97] = &&L0d567,
            [0x4be5] = &&L0d5b5,
            [0x4c0b] = &&L0d5db,
            [0x4c6b] = &&L0d63b,
            [0x4c75] = &&L0d645,
            [0x4c85] = &&L0d655,
            [0x4c88] = &&L0d658,
            [0x4cf7] = &&L0d6c7,
            [0x4cf8] = &&L0d6c8,
            [0x4d31] = &&L0d701,
        };
        uint32_t i_ = jkey - 0x89d0u;
        if (i_ < 0x4d32u && dtab[i_])
            goto *dtab[i_];
    }
    switch (jkey) {
    case 0x089d0: goto L089d0;
    case 0x089e3: goto L089e3;
    case 0x089e6: goto L089e6;
    case 0x08a04: goto L08a04;
    case 0x08a07: goto L08a07;
    case 0x08a0a: goto L08a0a;
    case 0x08a0d: goto L08a0d;
    case 0x08a10: goto L08a10;
    case 0x08a17: goto L08a17;
    case 0x08a1a: goto L08a1a;
    case 0x08a23: goto L08a23;
    case 0x08a32: goto L08a32;
    case 0x08a3b: goto L08a3b;
    case 0x08a42: goto L08a42;
    case 0x08a52: goto L08a52;
    case 0x08a79: goto L08a79;
    case 0x08a94: goto L08a94;
    case 0x08aa6: goto L08aa6;
    case 0x08ac0: goto L08ac0;
    case 0x08ac9: goto L08ac9;
    case 0x08aca: goto L08aca;
    case 0x08ad1: goto L08ad1;
    case 0x08aeb: goto L08aeb;
    case 0x08afd: goto L08afd;
    case 0x08b00: goto L08b00;
    case 0x08b03: goto L08b03;
    case 0x08b0a: goto L08b0a;
    case 0x08b24: goto L08b24;
    case 0x08b2a: goto L08b2a;
    case 0x08b2d: goto L08b2d;
    case 0x08b30: goto L08b30;
    case 0x08b33: goto L08b33;
    case 0x08b36: goto L08b36;
    case 0x08b39: goto L08b39;
    case 0x08b3c: goto L08b3c;
    case 0x08b3f: goto L08b3f;
    case 0x08b42: goto L08b42;
    case 0x08b45: goto L08b45;
    case 0x08b48: goto L08b48;
    case 0x08b4b: goto L08b4b;
    case 0x08b4e: goto L08b4e;
    case 0x08b51: goto L08b51;
    case 0x08b54: goto L08b54;
    case 0x08b57: goto L08b57;
    case 0x08b5a: goto L08b5a;
    case 0x08b5d: goto L08b5d;
    case 0x08b60: goto L08b60;
    case 0x08b63: goto L08b63;
    case 0x08b64: goto L08b64;
    case 0x08b6e: goto L08b6e;
    case 0x08b7a: goto L08b7a;
    case 0x08b85: goto L08b85;
    case 0x08b8a: goto L08b8a;
    case 0x08b94: goto L08b94;
    case 0x08ba0: goto L08ba0;
    case 0x08bae: goto L08bae;
    case 0x08bc7: goto L08bc7;
    case 0x08bcc: goto L08bcc;
    case 0x08be7: goto L08be7;
    case 0x08be8: goto L08be8;
    case 0x08bf2: goto L08bf2;
    case 0x08bfe: goto L08bfe;
    case 0x08c0c: goto L08c0c;
    case 0x08c29: goto L08c29;
    case 0x08c2e: goto L08c2e;
    case 0x08c41: goto L08c41;
    case 0x08c54: goto L08c54;
    case 0x08c5e: goto L08c5e;
    case 0x08c6a: goto L08c6a;
    case 0x08c78: goto L08c78;
    case 0x08c95: goto L08c95;
    case 0x08c9a: goto L08c9a;
    case 0x08cb9: goto L08cb9;
    case 0x08cc3: goto L08cc3;
    case 0x08ccf: goto L08ccf;
    case 0x08ce9: goto L08ce9;
    case 0x08cf6: goto L08cf6;
    case 0x08d09: goto L08d09;
    case 0x08d0e: goto L08d0e;
    case 0x08d15: goto L08d15;
    case 0x08d1f: goto L08d1f;
    case 0x08d2b: goto L08d2b;
    case 0x08d3f: goto L08d3f;
    case 0x08d4f: goto L08d4f;
    case 0x08d60: goto L08d60;
    case 0x08d77: goto L08d77;
    case 0x08d90: goto L08d90;
    case 0x08da3: goto L08da3;
    case 0x08dad: goto L08dad;
    case 0x08db9: goto L08db9;
    case 0x08dc7: goto L08dc7;
    case 0x08de0: goto L08de0;
    case 0x08de5: goto L08de5;
    case 0x08def: goto L08def;
    case 0x08dfb: goto L08dfb;
    case 0x08e0f: goto L08e0f;
    case 0x08e1f: goto L08e1f;
    case 0x08e38: goto L08e38;
    case 0x08e3d: goto L08e3d;
    case 0x08e47: goto L08e47;
    case 0x08e53: goto L08e53;
    case 0x08e67: goto L08e67;
    case 0x08e77: goto L08e77;
    case 0x08e8e: goto L08e8e;
    case 0x08e9b: goto L08e9b;
    case 0x08ea0: goto L08ea0;
    case 0x08eb9: goto L08eb9;
    case 0x08ec3: goto L08ec3;
    case 0x08ecf: goto L08ecf;
    case 0x08edd: goto L08edd;
    case 0x08ef3: goto L08ef3;
    case 0x08f00: goto L08f00;
    case 0x08f17: goto L08f17;
    case 0x08f1c: goto L08f1c;
    case 0x08f35: goto L08f35;
    case 0x08f38: goto L08f38;
    case 0x08f44: goto L08f44;
    case 0x08f51: goto L08f51;
    case 0x08f66: goto L08f66;
    case 0x08f75: goto L08f75;
    case 0x08f7f: goto L08f7f;
    case 0x08f8d: goto L08f8d;
    case 0x08f99: goto L08f99;
    case 0x08fad: goto L08fad;
    case 0x08fc9: goto L08fc9;
    case 0x08ff0: goto L08ff0;
    case 0x08ff6: goto L08ff6;
    case 0x09003: goto L09003;
    case 0x09006: goto L09006;
    case 0x09021: goto L09021;
    case 0x09024: goto L09024;
    case 0x09034: goto L09034;
    case 0x09037: goto L09037;
    case 0x0903a: goto L0903a;
    case 0x0903d: goto L0903d;
    case 0x09040: goto L09040;
    case 0x09043: goto L09043;
    case 0x09046: goto L09046;
    case 0x09049: goto L09049;
    case 0x0904c: goto L0904c;
    case 0x0904f: goto L0904f;
    case 0x09052: goto L09052;
    case 0x09055: goto L09055;
    case 0x09058: goto L09058;
    case 0x0905b: goto L0905b;
    case 0x0905e: goto L0905e;
    case 0x09061: goto L09061;
    case 0x09064: goto L09064;
    case 0x09067: goto L09067;
    case 0x0906a: goto L0906a;
    case 0x0906d: goto L0906d;
    case 0x09070: goto L09070;
    case 0x09073: goto L09073;
    case 0x09076: goto L09076;
    case 0x09079: goto L09079;
    case 0x0907c: goto L0907c;
    case 0x0907f: goto L0907f;
    case 0x09090: goto L09090;
    case 0x09093: goto L09093;
    case 0x0909a: goto L0909a;
    case 0x090aa: goto L090aa;
    case 0x090c7: goto L090c7;
    case 0x090de: goto L090de;
    case 0x090fb: goto L090fb;
    case 0x0910b: goto L0910b;
    case 0x09132: goto L09132;
    case 0x09144: goto L09144;
    case 0x09155: goto L09155;
    case 0x0915e: goto L0915e;
    case 0x09161: goto L09161;
    case 0x09164: goto L09164;
    case 0x09172: goto L09172;
    case 0x0ae25: goto L0ae25;
    case 0x0ae30: goto L0ae30;
    case 0x0ae80: goto L0ae80;
    case 0x0ae8b: goto L0ae8b;
    case 0x0aeca: goto L0aeca;
    case 0x0aed5: goto L0aed5;
    case 0x0af14: goto L0af14;
    case 0x0af4d: goto L0af4d;
    case 0x0af53: goto L0af53;
    case 0x0af59: goto L0af59;
    case 0x0af78: goto L0af78;
    case 0x0af98: goto L0af98;
    case 0x0afb7: goto L0afb7;
    case 0x0afd7: goto L0afd7;
    case 0x0affd: goto L0affd;
    case 0x0b007: goto L0b007;
    case 0x0b031: goto L0b031;
    case 0x0b03c: goto L0b03c;
    case 0x0b051: goto L0b051;
    case 0x0b054: goto L0b054;
    case 0x0b083: goto L0b083;
    case 0x0b0a9: goto L0b0a9;
    case 0x0b0be: goto L0b0be;
    case 0x0b0d1: goto L0b0d1;
    case 0x0b0e4: goto L0b0e4;
    case 0x0b0e9: goto L0b0e9;
    case 0x0b0eb: goto L0b0eb;
    case 0x0b11e: goto L0b11e;
    case 0x0b129: goto L0b129;
    case 0x0b155: goto L0b155;
    case 0x0b160: goto L0b160;
    case 0x0b163: goto L0b163;
    case 0x0b172: goto L0b172;
    case 0x0b27a: goto L0b27a;
    case 0x0b27f: goto L0b27f;
    case 0x0b2b8: goto L0b2b8;
    case 0x0b2be: goto L0b2be;
    case 0x0b2df: goto L0b2df;
    case 0x0b2e0: goto L0b2e0;
    case 0x0b2eb: goto L0b2eb;
    case 0x0b325: goto L0b325;
    case 0x0b339: goto L0b339;
    case 0x0b33c: goto L0b33c;
    case 0x0b356: goto L0b356;
    case 0x0b357: goto L0b357;
    case 0x0b373: goto L0b373;
    case 0x0b397: goto L0b397;
    case 0x0b3c7: goto L0b3c7;
    case 0x0b3d7: goto L0b3d7;
    case 0x0b412: goto L0b412;
    case 0x0b432: goto L0b432;
    case 0x0b47a: goto L0b47a;
    case 0x0b480: goto L0b480;
    case 0x0b48a: goto L0b48a;
    case 0x0b4a3: goto L0b4a3;
    case 0x0b4a8: goto L0b4a8;
    case 0x0b4f2: goto L0b4f2;
    case 0x0b53b: goto L0b53b;
    case 0x0b541: goto L0b541;
    case 0x0b55a: goto L0b55a;
    case 0x0b55f: goto L0b55f;
    case 0x0b562: goto L0b562;
    case 0x0b57b: goto L0b57b;
    case 0x0b5c5: goto L0b5c5;
    case 0x0b5cf: goto L0b5cf;
    case 0x0b5d5: goto L0b5d5;
    case 0x0b5fd: goto L0b5fd;
    case 0x0b66d: goto L0b66d;
    case 0x0b66e: goto L0b66e;
    case 0x0b6b7: goto L0b6b7;
    case 0x0b6bd: goto L0b6bd;
    case 0x0b6d6: goto L0b6d6;
    case 0x0b71a: goto L0b71a;
    case 0x0b725: goto L0b725;
    case 0x0b728: goto L0b728;
    case 0x0b757: goto L0b757;
    case 0x0b758: goto L0b758;
    case 0x0b7a6: goto L0b7a6;
    case 0x0b7ac: goto L0b7ac;
    case 0x0b7bd: goto L0b7bd;
    case 0x0b7f0: goto L0b7f0;
    case 0x0b7fb: goto L0b7fb;
    case 0x0b7fe: goto L0b7fe;
    case 0x0b828: goto L0b828;
    case 0x0b829: goto L0b829;
    case 0x0b838: goto L0b838;
    case 0x0b852: goto L0b852;
    case 0x0b87a: goto L0b87a;
    case 0x0b8ab: goto L0b8ab;
    case 0x0b8af: goto L0b8af;
    case 0x0b8c0: goto L0b8c0;
    case 0x0b8fb: goto L0b8fb;
    case 0x0b906: goto L0b906;
    case 0x0b909: goto L0b909;
    case 0x0b925: goto L0b925;
    case 0x0b926: goto L0b926;
    case 0x0b972: goto L0b972;
    case 0x0b978: goto L0b978;
    case 0x0b9a2: goto L0b9a2;
    case 0x0b9ac: goto L0b9ac;
    case 0x0b9c0: goto L0b9c0;
    case 0x0b9e4: goto L0b9e4;
    case 0x0b9f1: goto L0b9f1;
    case 0x0b9ff: goto L0b9ff;
    case 0x0ba2e: goto L0ba2e;
    case 0x0ba31: goto L0ba31;
    case 0x0ba32: goto L0ba32;
    case 0x0ba35: goto L0ba35;
    case 0x0ba66: goto L0ba66;
    case 0x0ba67: goto L0ba67;
    case 0x0baba: goto L0baba;
    case 0x0bac0: goto L0bac0;
    case 0x0bad3: goto L0bad3;
    case 0x0baea: goto L0baea;
    case 0x0baf9: goto L0baf9;
    case 0x0bb1d: goto L0bb1d;
    case 0x0bc85: goto L0bc85;
    case 0x0bc94: goto L0bc94;
    case 0x0bcbc: goto L0bcbc;
    case 0x0bce7: goto L0bce7;
    case 0x0bd12: goto L0bd12;
    case 0x0bd36: goto L0bd36;
    case 0x0bd40: goto L0bd40;
    case 0x0bd4e: goto L0bd4e;
    case 0x0bd4f: goto L0bd4f;
    case 0x0bd68: goto L0bd68;
    case 0x0bd6d: goto L0bd6d;
    case 0x0bd70: goto L0bd70;
    case 0x0bd9a: goto L0bd9a;
    case 0x0bde4: goto L0bde4;
    case 0x0bdee: goto L0bdee;
    case 0x0bdf4: goto L0bdf4;
    case 0x0be2e: goto L0be2e;
    case 0x0bea3: goto L0bea3;
    case 0x0bea4: goto L0bea4;
    case 0x0beec: goto L0beec;
    case 0x0bef2: goto L0bef2;
    case 0x0bf0b: goto L0bf0b;
    case 0x0bf10: goto L0bf10;
    case 0x0bf13: goto L0bf13;
    case 0x0bf3d: goto L0bf3d;
    case 0x0bf87: goto L0bf87;
    case 0x0bf91: goto L0bf91;
    case 0x0bf97: goto L0bf97;
    case 0x0bfd1: goto L0bfd1;
    case 0x0c046: goto L0c046;
    case 0x0c047: goto L0c047;
    case 0x0c08f: goto L0c08f;
    case 0x0c095: goto L0c095;
    case 0x0c0a4: goto L0c0a4;
    case 0x0c0a7: goto L0c0a7;
    case 0x0c0aa: goto L0c0aa;
    case 0x0c0ad: goto L0c0ad;
    case 0x0c0ae: goto L0c0ae;
    case 0x0c0fc: goto L0c0fc;
    case 0x0c102: goto L0c102;
    case 0x0c11b: goto L0c11b;
    case 0x0c120: goto L0c120;
    case 0x0c123: goto L0c123;
    case 0x0c150: goto L0c150;
    case 0x0c17a: goto L0c17a;
    case 0x0c1da: goto L0c1da;
    case 0x0c1e4: goto L0c1e4;
    case 0x0c1f4: goto L0c1f4;
    case 0x0c1fa: goto L0c1fa;
    case 0x0c263: goto L0c263;
    case 0x0c264: goto L0c264;
    case 0x0c267: goto L0c267;
    case 0x0c280: goto L0c280;
    case 0x0c281: goto L0c281;
    case 0x0c2c9: goto L0c2c9;
    case 0x0c2cf: goto L0c2cf;
    case 0x0c31d: goto L0c31d;
    case 0x0c323: goto L0c323;
    case 0x0c33c: goto L0c33c;
    case 0x0c341: goto L0c341;
    case 0x0c344: goto L0c344;
    case 0x0c3d2: goto L0c3d2;
    case 0x0c431: goto L0c431;
    case 0x0c43b: goto L0c43b;
    case 0x0c43e: goto L0c43e;
    case 0x0c447: goto L0c447;
    case 0x0c480: goto L0c480;
    case 0x0c481: goto L0c481;
    case 0x0c492: goto L0c492;
    case 0x0c4e5: goto L0c4e5;
    case 0x0c4f0: goto L0c4f0;
    case 0x0c4f3: goto L0c4f3;
    case 0x0c54c: goto L0c54c;
    case 0x0c5a9: goto L0c5a9;
    case 0x0c5aa: goto L0c5aa;
    case 0x0c5f4: goto L0c5f4;
    case 0x0c5fa: goto L0c5fa;
    case 0x0c647: goto L0c647;
    case 0x0c64d: goto L0c64d;
    case 0x0c65e: goto L0c65e;
    case 0x0c68a: goto L0c68a;
    case 0x0c695: goto L0c695;
    case 0x0c698: goto L0c698;
    case 0x0c6c2: goto L0c6c2;
    case 0x0c6c3: goto L0c6c3;
    case 0x0c70c: goto L0c70c;
    case 0x0c712: goto L0c712;
    case 0x0c72b: goto L0c72b;
    case 0x0c76f: goto L0c76f;
    case 0x0c77a: goto L0c77a;
    case 0x0c77d: goto L0c77d;
    case 0x0c7ba: goto L0c7ba;
    case 0x0c7bb: goto L0c7bb;
    case 0x0c803: goto L0c803;
    case 0x0c809: goto L0c809;
    case 0x0c822: goto L0c822;
    case 0x0c827: goto L0c827;
    case 0x0c82a: goto L0c82a;
    case 0x0c843: goto L0c843;
    case 0x0c88a: goto L0c88a;
    case 0x0c894: goto L0c894;
    case 0x0c89a: goto L0c89a;
    case 0x0c8e1: goto L0c8e1;
    case 0x0c92f: goto L0c92f;
    case 0x0c930: goto L0c930;
    case 0x0c97c: goto L0c97c;
    case 0x0c982: goto L0c982;
    case 0x0c99b: goto L0c99b;
    case 0x0c9a0: goto L0c9a0;
    case 0x0c9a3: goto L0c9a3;
    case 0x0ca0f: goto L0ca0f;
    case 0x0ca6e: goto L0ca6e;
    case 0x0ca78: goto L0ca78;
    case 0x0ca7e: goto L0ca7e;
    case 0x0cae7: goto L0cae7;
    case 0x0cae8: goto L0cae8;
    case 0x0cb31: goto L0cb31;
    case 0x0cb37: goto L0cb37;
    case 0x0cb50: goto L0cb50;
    case 0x0cb55: goto L0cb55;
    case 0x0cb58: goto L0cb58;
    case 0x0cb76: goto L0cb76;
    case 0x0cbba: goto L0cbba;
    case 0x0cbd6: goto L0cbd6;
    case 0x0cc56: goto L0cc56;
    case 0x0cc60: goto L0cc60;
    case 0x0cc66: goto L0cc66;
    case 0x0cccf: goto L0cccf;
    case 0x0ccd0: goto L0ccd0;
    case 0x0cce9: goto L0cce9;
    case 0x0cd19: goto L0cd19;
    case 0x0cd2d: goto L0cd2d;
    case 0x0cd38: goto L0cd38;
    case 0x0cd3b: goto L0cd3b;
    case 0x0cde5: goto L0cde5;
    case 0x0ce89: goto L0ce89;
    case 0x0ce93: goto L0ce93;
    case 0x0cea3: goto L0cea3;
    case 0x0cea9: goto L0cea9;
    case 0x0ceb2: goto L0ceb2;
    case 0x0cf00: goto L0cf00;
    case 0x0cf06: goto L0cf06;
    case 0x0cf54: goto L0cf54;
    case 0x0cf5a: goto L0cf5a;
    case 0x0cf73: goto L0cf73;
    case 0x0cf78: goto L0cf78;
    case 0x0cf7b: goto L0cf7b;
    case 0x0d010: goto L0d010;
    case 0x0d052: goto L0d052;
    case 0x0d09f: goto L0d09f;
    case 0x0d0cc: goto L0d0cc;
    case 0x0d0d6: goto L0d0d6;
    case 0x0d0e6: goto L0d0e6;
    case 0x0d0ec: goto L0d0ec;
    case 0x0d0ed: goto L0d0ed;
    case 0x0d106: goto L0d106;
    case 0x0d140: goto L0d140;
    case 0x0d14b: goto L0d14b;
    case 0x0d14e: goto L0d14e;
    case 0x0d1ba: goto L0d1ba;
    case 0x0d1fb: goto L0d1fb;
    case 0x0d25b: goto L0d25b;
    case 0x0d265: goto L0d265;
    case 0x0d275: goto L0d275;
    case 0x0d27b: goto L0d27b;
    case 0x0d284: goto L0d284;
    case 0x0d2ad: goto L0d2ad;
    case 0x0d2b6: goto L0d2b6;
    case 0x0d2b7: goto L0d2b7;
    case 0x0d305: goto L0d305;
    case 0x0d30b: goto L0d30b;
    case 0x0d31e: goto L0d31e;
    case 0x0d341: goto L0d341;
    case 0x0d37d: goto L0d37d;
    case 0x0d38b: goto L0d38b;
    case 0x0d3f6: goto L0d3f6;
    case 0x0d400: goto L0d400;
    case 0x0d47a: goto L0d47a;
    case 0x0d492: goto L0d492;
    case 0x0d49d: goto L0d49d;
    case 0x0d4a3: goto L0d4a3;
    case 0x0d4a6: goto L0d4a6;
    case 0x0d4ee: goto L0d4ee;
    case 0x0d4f4: goto L0d4f4;
    case 0x0d540: goto L0d540;
    case 0x0d546: goto L0d546;
    case 0x0d55f: goto L0d55f;
    case 0x0d564: goto L0d564;
    case 0x0d567: goto L0d567;
    case 0x0d5b5: goto L0d5b5;
    case 0x0d5db: goto L0d5db;
    case 0x0d63b: goto L0d63b;
    case 0x0d645: goto L0d645;
    case 0x0d655: goto L0d655;
    case 0x0d658: goto L0d658;
    case 0x0d6c7: goto L0d6c7;
    case 0x0d6c8: goto L0d6c8;
    case 0x0d701: goto L0d701;
    }
    if (jkey == KEY(PSPSEG, 0)) return;          /* retf 로 PSP:0000 (int 20h) */
    jkey = or_unknown(jkey);
    goto dispatch;
}
