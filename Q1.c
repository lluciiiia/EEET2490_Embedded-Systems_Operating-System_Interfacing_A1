unsigned int X, r, tmp1, tmp2;

r = X;

// Store bits 13-9 (5) to tmp1
tmp1 = (r >> 9) & 0b11111;

// Store bits 31-14 (18)
tmp2 = (r >> 14) & 0b111111111111111111;

// Clear bits 31-9 (23)
r &= ~(0b11111111111111111111111 < 9);

// Set tmp1 to bits 31-27 (5)
r |= tmp1 << 27;

// Set tmp2 to bits 26-9 (18)
r |= tmp2 << 9;

X = r;




