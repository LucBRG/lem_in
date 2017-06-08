/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:35:58 by lbrugero          #+#    #+#             */
/*   Updated: 2017/06/06 11:54:31 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 20
# define GNL_ERROR -1
# define GNL_END 0
# define GNL_OK 1
# include <string.h>
# include <wchar.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					get_next_line(const int fd, char **line);

/*
** WCHAR_T
*/
void				ft_putwstr(wchar_t *str);
void				ft_putwchar(wchar_t c);
size_t				ft_strwoctet(const wchar_t *s);
size_t				ft_strwlen(const wchar_t *s);
wchar_t				*ft_strwdup(const wchar_t *src);
wchar_t				*ft_strwjoin(wchar_t const *s1, wchar_t const *s2);
wchar_t				*ft_itowchar(long long n, int force_sign);
wchar_t				*ft_strwrev(wchar_t *str);
char				*ft_wtoc(wchar_t *w);
int					ft_strlenchar(char *str, char l);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(long long int n);
void				ft_putnbr_fd(long long int n, int fd);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_swap(int *a, int *b);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_memcmp(const void *ptr1, const void *ptr2, size_t len);
void				*ft_memchr(const void *str, int c, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strclen(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strdup(char *src);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(char *str);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_strdigit(char *str);
int					ft_isalnum(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_strsplit_free(char **str);
int					ft_strsplit_len(char **str);

int					ft_atoi(const char *nptr);
char				*ft_itoa(long long n, int force_sign);
char				*ft_utoa(unsigned long long n);
char				*ft_base(unsigned long long nb, int base, char *base_str);

long long int		ft_greater(long long int *a, long long int b);
long long int		ft_max(long long int a, long long int b);
void				ft_showletter(size_t n, char l);
int					ft_nbrlen(long long int n, int count_sign);
int					ft_nbrulen(unsigned long long int n);

/*
** LIST
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddafter(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *));
size_t				ft_lstlen(t_list *lst);
t_list				*ft_lstsort(t_list *list, int (*sort)(t_list *, t_list *));
t_list				*ft_lstjump(t_list **lst, size_t n);
t_list				*ft_lstdefile(t_list **alst, void (*del)(void *, size_t));

#endif
