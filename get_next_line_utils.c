#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (0);
}

int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*p;
	int		len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	str = malloc(len + 1);
	if (!str)
		return (0);
	p = str;
	while (*s)
	{
		*p++ = *s++;
	}
	*p = '\0';
	return (str);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	if (!n || dest == src)
		return (dest);
	while (n--)
		*str1++ = *str2++;
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*result;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	result = malloc(lens1 + lens2 + 1);
	if (result)
	{
		ft_memcpy(result, s1, lens1);
		ft_memcpy(result + lens1, s2, lens2 + 1);
	}
	return (result);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	if ((size_t)(ft_strlen((char *)(s))) < (size_t)(start))
		len = 0;
	else if ((size_t)(ft_strlen((char *)(s)) + start) < len)
		len = ft_strlen((char *)(s) + start);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	while (i < len && s[i])
	{
		ret[i] = s[start];
		i++;
		start++;
	}
	ret[i] = '\0';
	return (ret);
}