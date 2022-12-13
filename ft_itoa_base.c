#include <stdlib.h>

int	ft_strlen(char *str)
{
	register int (count) = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

unsigned int	ft_numsize(long long n, char *base)
{
	long long	temp;
	long long	base_len;
	long long	len;

	base_len = ft_strlen(base);
	temp = n;
	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len += 1;
		temp = -temp;
	}
	while (temp)
	{
		temp /= base_len;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(long long n, char *base)
{
	long long (len) = ft_numsize(n, base);
	long long (intbase) = ft_strlen(base);
	long long (num) = n;
	char *(str) = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (num == 0)
		str[0] = '0';
	str[len] = '\0';
	while (num > 0)
	{
		str[len - 1] = base[num % intbase];
		num /= intbase;
		len--;
	}
	return (str);
}

#include <stdio.h>
int	main(void)
{
	int		a = -417;
	printf("org value is : '-417', my value is : %s'", ft_itoa_base(a, "0123456789"));
}
