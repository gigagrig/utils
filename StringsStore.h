class StringsStore
{
	const int kSize = 32*1024;
	vector<char> store_;
	char* next_pos_;
public:
	void Init()
	{
		store_.resize(kSize);
		next_pos_ = store_.data();
		for (int i = 0; i < kSize; i++)
			store_[i] = 0;
	}

	const char* AddString(const char* str, int size)
	{
		char* begin = store_.data();
		char* res = (char*)memmem(begin, next_pos_ - begin, str, size);
		if (!res)
		{
			if (next_pos_ + size > begin + kSize)
				return 0;
			memcpy(next_pos_, str, size);
			char *pos = next_pos_;
			next_pos_ = next_pos_ + (size+1);
			return pos;
		}

		return res;
	}

	const char* GetString(const char* str, int size)
	{
		char* begin = store_.data();
		return (char*)memmem(begin, next_pos_ - begin, str, size);
	}
};
