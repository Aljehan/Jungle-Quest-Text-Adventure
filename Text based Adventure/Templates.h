#ifndef TEMPLATES_H
#define TEMPLATES_H

template <typename T>
T max(const T& a, const T& b, const T& c)
{
	T maximum = a;

	if (maximum < b)
	{
		maximum = b;
	}
	if (maximum < c)
	{
		maximum = c;
	}

	return maximum;
}

template <typename T>
T median(const T& a, const T& b, const T& c)
{
	T medium = a; 

	if (medium > b && medium > c)
	{
		if (b < c)
		{
			medium = c;
		}
		else
		{
			medium = b;
		}
	}
	else if (medium < b && medium < c)
	{
		if (b > c)
		{
			medium = c;
		}
		else
		{
			medium = b;
		}
	}
	else
	{
		return medium;
	}

	return medium;
}

template <typename T>
T sum(const T& a, const T& b, const T& c)
{
	T Sum = a + b + c;
	return Sum;
}

template <typename T>
T max(const T array[], unsigned int count)
{
	T maximum = array[0];
	for (unsigned int i = 1; i < count; i++)
	{
		if (maximum < array[i])
		{
			maximum = array[i];
		}
	}

	return maximum;
}

template <typename T>
T sum(const T array[], unsigned int count)
{
	T Sum = array[0];
	for (unsigned int i = 1; i < count; i++)
	{
		Sum += array[i];
	}

	return Sum;
}



#endif
