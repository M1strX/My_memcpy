errno_t my_memcpy(void *dest, const void *src, rsize_t count) {
	rsize_t count_dword = count / 32;
	rsize_t count_word = (count - count_dword * 32) / 16;
	rsize_t count_bytes = count - (count_dword + count_word);
	__asm {
		mov edi, dest
		mov esi, src
		mov ecx, count_dword
		rep movsd
		mov ecx, count_word
		rep movsw
		mov ecx, count_bytes
		rep movsb
	}
	return 0;
}
