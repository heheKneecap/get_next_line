#include "get_next_line.h"

static char *do_stuff(int fd, char *buff, char *text)
{
    ssize_t eh;
    char *more_text;

    eh = 1;
    while (eh > 0)
    {
        eh = read(fd, buff, BUFFER_SIZE);
        if (eh < 0)
            return (0);
        else if (eh == 0)
            break;
        buff[eh] = '\0';
        if(!text)
            text = ft_strdup("");
        more_text = text;
        text = ft_strjoin(more_text, buff);
        free(more_text);
        more_text = 0;
        if(ft_strchr(buff, '\n'))
            break;
    }
    return (text);
}

static char *read_bitch(char *read)
{
    char    *this;
    size_t  that;

    that = 0;
    while(read[that] != '\0' && read[that] != '\n')
        that++;
    if (read[that] != '\n' || read[that + 1] == '\0')
        return(0);
    this = ft_substr(read, that + 1, ft_strlen(read) - that);
    if (*this == '\0')
    {
        free(this);
        this = 0;
        return(0);
    }
    read[that + 1] = '\0';
    return(this);
}

char *get_next_line(int fd)
{
    static char *s;
    char        *buffer;
    char        *text;

    if (BUFFER_SIZE <= 0 || fd < 0)
        return (0);
    else if (read(fd, 0, 0) < 0)
    {
        free(s);
        s = 0;
        return(0);
    }
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return(0);
    text = do_stuff(fd, buffer, s);
    free(buffer);
    buffer = 0;
    if (!text)
        return(0);
    s = read_bitch(text);
    return(text);
}
