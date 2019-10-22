unsigned long h(int K)
{
	auto s = K*K;
	
	return (s & 0x00FFFF00) >> 8;
}
