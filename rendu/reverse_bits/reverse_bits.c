unsigned char reverse_bits(unsigned char octet)
{
	unsigned char r;
	int	len;

	r = 0;
	len = 8;
	while (len)
	{
		r = (r << 1) | (octet & 1);
		octet >>= 1;
		len--;
	}
	return (r);
}
