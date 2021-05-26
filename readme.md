# libft / 42Seoul youjeon

- 참조할만한 자료들과 내용 출처.

    과제 관련

     - [https://idollee.tistory.com/68](https://idollee.tistory.com/68)

     - [https://bestowing.github.io/libft/2020/11/23/libft.html](https://bestowing.github.io/libft/2020/11/23/libft.html)

     - [https://www.notion.so/Libft-0b2b3601a0714308b5435e076bb0f3e6](https://www.notion.so/Libft-0b2b3601a0714308b5435e076bb0f3e6)

     - [https://kirkim.github.io/42seoul/2021/02/25/libft_makefile.html](https://kirkim.github.io/42seoul/2021/02/25/libft_makefile.html)

    Makefile

     - [https://modoocode.com/311](https://modoocode.com/311)

    relink & .PHONY

     - [https://yunslee-42seoul.tistory.com/3](https://yunslee-42seoul.tistory.com/3)

     - [https://pinocc.tistory.com/131](https://pinocc.tistory.com/131)

    undefined behavior

     - [https://www.secmem.org/blog/2020/01/17/c-c++-and-ub/](https://www.secmem.org/blog/2020/01/17/c-c++-and-ub/) 

- 질문지
    - 보너스문제 메인문 만들어서 구현해보기

        메인문 파서 arr [1,2,3,4,5]의 원소들로 노드들을 만들어 연결리스트 만들고 출력해보고, 각 노드의 value들을 함수 모두 2를 곱한 뒤에 출력하고, 모든 리스트와 원소들 삭제해보기

        - 답지

            ```jsx
            #include "libft.h"

            void	f_del(void *content)
            {
            	free(content);
            	printf("free");
            }

            void	*f_map(void *content)
            {
            	*(int*)content = *(int*)content * 2;
            	return(content);
            }

            int	main()
            {
            	t_list *test = NULL;
            	t_list *new_test = NULL;
            	t_list *tmp = NULL;
            	int idx = 0;
            	int *i = 0;
            	
            	while (idx < 6)
            	{
            		i = malloc(sizeof(int));
            		*i = idx;
            		tmp = ft_lstnew(i);
            		ft_lstadd_back(&test, tmp);
            		idx++;
            	}
            	ft_putendl_fd("test", 1);
            	tmp = test;
            	while (tmp->next)
            	{
            		ft_putnbr_fd(*(int *)(tmp->content), 1);
            		tmp = tmp->next;
            	}
            	ft_putendl_fd("\ntest2", 1);
            	 new_test = ft_lstmap(test, f_map, f_del);
            	tmp = new_test;
            	while (tmp)
            	{
            		ft_putnbr_fd(*(int *)(tmp->content), 1);
            		tmp = tmp->next;
            	}
            	ft_lstclear(&test, f_del);
            }
            ```

    - restrict 한정자?

        컴파일러에게 포인터가 가르키는 값을 다른곳에서 사용하지 않는다고 알려주는 한정어. 컴파일러가 해당 포인터에 대한 값이 변했는지 검사를 하지 않음으로서 좀더 높은 성능을 보이나, 사용할때 주의가 필요함

        memcpy, memccpy, strlcpy, strlcat 에서 사용됨

        만약 이게 뭔지도 모르고 어디에서 사용됐는지도 모르고 없어졌을때 어떤 일이 생기는지도 모른다면 과제를 안읽고 문제를 풀었다고 생각함.

    - memcpy와 memmove의 차이

        [https://m.blog.naver.com/sharonichoya/220510332768](https://m.blog.naver.com/sharonichoya/220510332768)

        좀더 정리해서 써둘것

    - atoi 실제 동작과 동일한지(?)

        ```jsx
        #include <stdio.h>
        int main(void)
        {
            printf("a int max 2147483647 : %d\n", atoi("2147483647"));
            printf("f int max 2147483647 : %d\n", ft_atoi("2147483647"));
            printf("a int min -2147483648 : %d\n", atoi("-2147483648"));
            printf("f int min -2147483648 : %d\n", ft_atoi("-2147483648"));
            printf("a int over 9999999999 : %d\n", atoi("9999999999"));
            printf("f int over 9999999999 : %d\n", ft_atoi("9999999999"));
            printf("a int under -9999999999 : %d\n", atoi("-9999999999"));
            printf("f int under -9999999999 : %d\n", ft_atoi("-9999999999"));
            printf("a long long plus 92233720368547758 : %d\n", atoi("92233720368547758"));
            printf("f long long plus 92233720368547758 : %d\n", ft_atoi("92233720368547758"));
            printf("a long long minus -92233720368547758 : %d\n", atoi("-92233720368547758"));
            printf("f long long minus -92233720368547758 : %d\n", ft_atoi("-92233720368547758"));
            printf("a long long max 9223372036854775807 : %d\n", atoi("9223372036854775807"));
            printf("f long long max 9223372036854775807 : %d\n", ft_atoi("9223372036854775807"));
            printf("a long long min -9223372036854775808 : %d\n", atoi("–9223372036854775808"));
            printf("f long long min -9223372036854775808 : %d\n", ft_atoi("–9223372036854775808"));
            printf("a long long max / 10 922337203685477580 : %d\n", atoi("922337203685477580"));
            printf("f long long max / 10 922337203685477580 : %d\n", ft_atoi("922337203685477580"));
            printf("a long long max / 10 + 1 922337203685477581 : %d\n", atoi("922337203685477581"));
            printf("f long long max / 10 + 1 922337203685477581 : %d\n", ft_atoi("922337203685477581"));
            printf("a long long max / 10 + 4 922337203685477584 : %d\n", atoi("922337203685477584"));
            printf("f long long max / 10 + 4 922337203685477584 : %d\n", ft_atoi("922337203685477584"));
            printf("a long long max / 10 + 5 922337203685477585 : %d\n", atoi("922337203685477585"));
            printf("f long long max / 10 + 5 922337203685477585 : %d\n", ft_atoi("922337203685477585"));
            printf("a long long max - 1 922337203685477586 : %d\n", atoi("922337203685477586"));
            printf("f long long max - 1 922337203685477586 : %d\n", ft_atoi("922337203685477586"));
            printf("a long long max + 1 9223372036854775808 : %d\n", atoi("9223372036854775808"));
            printf("f long long max + 1 9223372036854775808 : %d\n", ft_atoi("9223372036854775808"));
            printf("a long long max + 2 9223372036854775809 : %d\n", atoi("9223372036854775809"));
            printf("f long long max + 2 9223372036854775809 : %d\n", ft_atoi("9223372036854775809"));
            printf("a long long max + 10 9223372036854775817 : %d\n", atoi("9223372036854775817"));
            printf("f long long max + 10 9223372036854775817 : %d\n", ft_atoi("9223372036854775817"));
            printf("a long long min - 1 –9223372036854775809 : %d\n", atoi("–9223372036854775809"));
            printf("f long long min - 1 –9223372036854775809 : %d\n", ft_atoi("–9223372036854775809"));
            printf("a long long min - 2 –9223372036854775810 : %d\n", atoi("–9223372036854775810"));
            printf("f long long min - 2 –9223372036854775810 : %d\n", ft_atoi("–9223372036854775810"));
            printf("a long long min - 10 –9223372036854775818 : %d\n", atoi("–9223372036854775818"));
            printf("f long long min - 10 –9223372036854775818 : %d\n", ft_atoi("–9223372036854775818"));
            printf("a long long over 9223379876854775807 : %d\n", atoi("9223379876854775807"));
            printf("f long long over 9223379876854775807 : %d\n", ft_atoi("9223379876854775807"));
            printf("a long long under -9223379876854775807 : %d\n", atoi("-9223379876854775807"));
            printf("f long long under -9223379876854775807 : %d\n", ft_atoi("-9223379876854775807"));
            printf("a long long half 4611686018427387903 : %d\n", atoi("4611686018427387903"));
            printf("f long long half 4611686018427387903 : %d\n", ft_atoi("4611686018427387903"));
            printf("a zero 0 : %d\n", atoi("0"));
            printf("f zero 0 : %d\n", ft_atoi("0"));
            printf("a empty  : %d\n", atoi(""));
            printf("f empty  : %d\n", ft_atoi(""));
            return (0);
        }
        ```

    - 이  함수에 널가드를 왜 했고 하지않았는지.

        원래 함수가 그렇다 라는 말은 너무 수동적이고 학생관성적인 대답이라고 생각함. 원래 함수를 만든 사람이 왜 널가드를 안했겠냐 라고 물어보면 대답할 말이 궁해짐.

        - strlen 에 널 들어왔을때

            나는 하지않았음. 일단 원래 함수가 그렇긴함

            [https://stdbool.com/index.php/2018/08/01/how-bad-is-strlen-anyway-or-not-c-perspective/](https://stdbool.com/index.php/2018/08/01/how-bad-is-strlen-anyway-or-not-c-perspective/)

            유저가 strlen을 사용할때 null을 확인하여 null을 반환하게 되면 사실상 0을 리턴한것과 다름이 없음.(null은 0을 가르키는 void포인터니까)

            즉 strlen가 제대로 동작하여 0을 반환한것과 잘못된 값을 입력하여 null을 반환한것을 구별할수있는 방법이 사실상 없음. 차라리 함수가 터져서 알게되는 것이 합리적임.

        - strlcpy 에 널 들어왔을때

            나는 하지않았음. 일단 원래 함수가 그렇긴함

            strlcpy의 반환값은 src의 길이임. 그런데 null을 반환하게 되면 사실상 0을 리턴한것과 다름이 없음.(null은 0을 가르키는 void포인터니까)

            src 가 0의 크기를 지닌 string인지 아예 잘못된 값이 들어가있는 지를 구별할 방법이 없기때문에 차라리 세그폴트를 띄워서 터트려야한다고 생각함

        - strmapi 에 빈값 들어왔을때

            나는 했음. 이건 내맘대로 만들면 되니까 고민을 좀 해봤는데,

            처음 고민한 부분은 "문자열 's'의 각 문자에 'f'함수를 연속적으로 적용시킨 새로운 문자열을 만들기" 라는 설명에서 문자열 s가 없다면 당연히 아무 할당도 안하는게 맞는데 f가 비어있으면 s 를 그대로 반환하는게 맞는가 아무것도 안하는게 맞는가...

            결국은 아무것도 안하는게 맞다고 판단함. 차라리 아무것도 없는게 함수를 잘못사용했다는것을 인지하기가 쉬울거라고 생각했기 때문에

    - memset으로 2바이트 이상의 자료형을 초기화하면?(=왜 unsigned char 로 형변환해서 넣었는지)

        2바이트 이상의 자료형으로 초기화한다면 비트연산으로 인해 의도한것과 다른 값으로 초기화 될 위험이 있기 때문이다(0과 -1을 제외한 모든 경우)

    - void 포인터

        자료형이 정해지지 않은 포인터로 형변환을 하지않고 포인터 연산을 하면 세그 폴트가 뜬다. 용량은 4바이트.

        함수의 인자로 많이 사용되는데 해당 함수에 넣을수있는 데이터의 폭을 넓히기 위해 사용한다.

    - const 의 위치에 따른 값의 상수 or 주소값(포인터)의 상수

        const char * → 상수를 가르키고있는 포인터 변수

        char const * → 캐릭터형 변수를 가르키고있는 포인터 상수

        const char const *  → 상수를 가르키고있는 포인터 상수

    - size_t 의 자료형 의미

        32비트에서는 32비트의 크기를 지닌 4바이트 정수(unsigned int)

        64비트에서는 64비트의 크기를 지닌 8바이트 정수(unsigned long)

    - strcpy 와 memcpy 의 차이

        string과 memory라고 하는 이름의 차이처럼 끝이 NULL로 끝나는지를 확인하는 과정이 있냐 없냐

    - strlcat 반환값의 의미와 활용

        할당하기위해 필요한 버퍼의 크기를 알기위한 용도로 길이를 반환한다(strlcpy도 동일함)

    - static 의 의미와 왜 쓰라고했는지

        각 파일 안에서만 사용하는 함수라고 정의함. 여러 파일에 있는 함수에서 같은 이름의 함수가 다른데서 쓰인다면 문제가 생길수도있기 때문에 해당 파일에서만 사용하는 함수는 정적으로 정의함

    - 스플릿에서 free를 해줘야 하는 명확한 이유? 누수가 발생하면 안된다 라고 한다면 왜 안되는가

        프로그램에서 힙 메모리를 잡고 놓아주지않으면 프로그램이 커졌을때 점점 많은 메모리를 사용하게되어 결국 프로그램이 강제로 종료되거나 보안상 문제가 생길수있기때문. 

    - free시 값은 살아있는가 죽어있는가

        값은 살아있음. 해당 메모리를 다 사용했음 알아서 가져가셈 이라고 태그를 달아놓는 느낌. 운영체제가 해당 메모리가 필요하다거나 일정 주기마다 알아서 정리함. 

    - lstadd 함수들에서 lst == null 과 *lst == null의 차이
        - `lst == 0` 은 리스트 자체가 없다는 뜻이다.
        - `*lst == 0` 은 현재 노드가 없다는 뜻이다.

- [테스터기]

    평소엔 git clone [https://github.com/alelievr/libft-unit-test.git](https://github.com/alelievr/libft-unit-test.git) 해서 이것만 사용하다가 파트 하나 끝나면 전체 검사 돌려서 얘가 검사하지않는 버그가 있나 확인함

    - 전체 검사 코드

        출처 : gilee

        수정 : 시작 norm 부분만 살짝 고쳤음. 

        참고로 용량이 부족하면 첫번째 테스트 케이스가 동작하지않음

        ```jsx
        #!/bin/bash
        echo -e "\033[32;1m"NORM"\033[m"
        read $a
        norminette *.c *.h
        echo -e "\033[32;1m"LIBFT TEST"\033[m"
        read $a
        git clone https://github.com/jtoty/Libftest
        cd Libftest/
        ./grademe.sh
        sed -i "" 's/~\/libft/..\//' my_config.sh
        ./grademe.sh
        cd ..
        echo -e "\033[32;1m"WAR MACHINE"\033[m"
        read $a
        git clone https://github.com/ska42/libft-war-machine
        cd libft-war-machine/
        bash grademe.sh
        bash grademe.sh
        cd ..
        echo -e "\033[32;1m"unit-test"\033[m"
        read $a
        git clone https://github.com/alelievr/libft-unit-test.git
        cd libft-unit-test/
        sed -i "" 's/LIBFTDIR	=	..\/libft/LIBFTDIR	=	..\//' Makefile
        make
        cd ..
        echo -e "\033[32;1m"libftTester"\033[m"
        read $a
        git clone https://github.com/Tripouille/libftTester.git
        cd libftTester/
        make a
        cd ..
        echo -e "\033[32;1m"make fclean"\033[m"
        read $a
        make
        make fclean
        ls
        echo -e "\033[32;1m"make clean"\033[m"
        read $a
        make
        make clean
        ls
        echo -e "\033[32;1m"make all"\033[m"
        read $a
        make all
        ls
        echo -e "\033[32;1m"make bonus"\033[m"
        read $a
        make bonus
        ls
        echo -e "\033[32;1m"relink"\033[m"
        read $a
        make
        rm -rf Libftest/ libft-war-machine/ libft-unit-test/ libftTester/
        make fclean
        echo -e "\033[32;1m"DONE"\033[m"
        ```

- [libft.h & Makefile]
    - include

        <stdlib.h> - NULL, size_t 사용

        <unistd.h> - write함수 사용

    - Makefile

        ```
        NAME					= libft.a

        SRCS					= ft_atoi.c \
        					  ft_bzero.c \
        					  ft_calloc.c \
        					  ft_isalnum.c \
        					  ft_isalpha.c \
        					  ft_isascii.c \
        					  ft_isdigit.c \
        					  ft_isprint.c \
        					  ft_itoa.c \
        					  ft_memccpy.c \
        					  ft_memchr.c \
        					  ft_memcmp.c \
        					  ft_memcpy.c \
        					  ft_memmove.c \
        					  ft_memset.c \
        					  ft_putchar_fd.c \
        					  ft_putendl_fd.c \
        					  ft_putnbr_fd.c \
        					  ft_putstr_fd.c \
        					  ft_split.c \
        					  ft_strchr.c \
        					  ft_strdup.c \
        					  ft_strjoin.c \
        					  ft_strlcat.c \
        					  ft_strlcpy.c \
        					  ft_strlen.c \
        					  ft_strmapi.c \
        					  ft_strncmp.c \
        					  ft_strnstr.c \
        					  ft_strrchr.c \
        					  ft_strtrim.c \
        					  ft_substr.c \
        					  ft_tolower.c \
        					  ft_toupper.c

        BNS_SRCS				= ft_lstsize.c \
        					  ft_lstadd_back.c \
        					  ft_lstadd_front.c \
        					  ft_lstclear.c \
        					  ft_lstdelone.c \
        					  ft_lstiter.c \
        					  ft_lstlast.c \
        					  ft_lstmap.c \
        					  ft_lstnew.c

        OBJS					= $(SRCS:%.c=%.o)

        BNS_OBJS				= $(BNS_SRCS:%.c=%.o)

        FLAGS					= -Wall -Wextra -Werror

        ifdef WITH_BONUS
        	OBJ_FILES = $(OBJS) $(BNS_OBJS)
        else
        	OBJ_FILES = $(OBJS)
        endif

        all	:	$(NAME)

        $(NAME)		:	$(OBJ_FILES)
        			ar rcs $(NAME) $(OBJ_FILES)

        %.o			: %.c
        	gcc $(FLAGS) -c $^ -I./ -o $@

        bonus :
        	make WITH_BONUS=1 all

        clean	:
        		rm -f $(OBJS) $(BNS_OBJS)

        fclean	:	clean
        		rm -f $(NAME)

        re	:	fclean all

        .PHONY	:	all clean fclean re bonus
        ```

- [PART 1]
    - ft_memset.c

        void ft_memset(void *dest, int c, size_t n);

        - 함수 설명

            dest에 접근하여 n만큼의 길이의 데이터를 c로 변환한다. 반환은 dest

            - 로직

                dest의 포인터를 만들고 int c를 캐릭터 형으로 변환한 다음 n과 비교할 i 변수를 하나 만든다. 

                i가 n보다 작을동안 새로 만든 포인터를 하나씩 전진시키면서 변환.

            - 디버깅

    - ft_bzero.c

        void *ft_bzero(void *str, size_t n);

        - 함수 설명

            str에 접근하여 n만큼의 길이의 데이터를 0으로 초기화한다. 반환은 str

            - 로직

                str의 포인터를 만들고 인덱스로 사용할 i 변수를 선언한다.

                i가 n보다 작을동안 새로만든 포인터를 하나씩 전진시키면서 0으로 초기화.  

            - 디버깅

    - ft_memcpy.c

        void *ft_memcpy(void *dest, const void *src, size_t n);

        - 함수 설명

            dest에 src의 내용을 n의 크기만큼 복사해서 넣는다. 반환은 dest

            - 로직

                dest와 src의 포인터를 만든다. n과 크기를 비교할 인덱스 i를 선언한다.

                i가 n보다 작을동안 dest 포인터와 src 포인터를 하나씩 전진시키면서 dest에 src를 입력한다.

            - 디버깅

                dest와 src가 NULL 일때 바로 0 반환

    - ft_memccpy.c

        void *ft_memccpy(void *dest, const void *src, int c, size_t n);

        - 함수 설명

            dest에 src의 내용을 n의 크기만큼 복사해서 넣되, c가 복사되면 그 다음 주소를 반환한다. 만약 끝까지 c가 없다면 NULL을 반환한다.

            - 로직

                dest와 src의 포인터를 만든다 n과 크기를 비교할 인덱스 i도 선언한다.

                i가 n보다 작을동안 dest와 src의 포인터를 하나씩 전진시키면서 입력하되, 입력한 다음 입력한 값이 c인지 확인하여 맞다면 dest의 다음 포인터를 return 한다.

                만약 끝까지 c가 안나온다면 NULL을 반환한다.

            - 디버깅

                dest와 src의 포인터를 만들때 (unsigned char*) 로 형변환하지않고 가져옴.

                다음 포인터를 반환할때 ++포인터가 아닌 포인터++로 반환함

    - ft_memmove.c

        void *ft_memmove(void *dest, const void *src, size_t n);

        - 함수 설명

            dest에 src의 내용을 n의 크기만큼 복사해서 넣되, dest와 src의 겹치는 부분이 있는지를 고려하여 만약 src 안에 dest가 있는 경우 src의 끝부터 복사한다. 반환은 dest

            참조 : [https://dailylifeofdeveloper.tistory.com/63](https://dailylifeofdeveloper.tistory.com/63)

            - 로직

                dest와 src의 포인터를 만든다. n과 크기를 비교할 인덱스 i도 선언한다.

                dest와 src의 포인터의 주소값 크기를 비교한다. 만약 dest의 주소값이 더 크다면(=dest가 src보다 뒤에 있다면) n이 i보다 클동안 dest에 src를 복사한다.

                반대로 src의 주소값이 더 크다면(=dest가 src보다 앞에있다면) 복사에 다른 요소를 고려할 필요가 없어 memcpy와 동일하게 i가 n보다 작을동안 dest에 src를 복사한다.

            - 디버깅

                dest와 src의 포인터를 만들어서 가져올때 (unsigned char*) 로 형변환하지않고 가져옴.

                로직 두번째 줄을 반대로 이해하고 풀었음. src가 작을때 src가 오염될 우려가 있어서 뒤부터 입력해야하는데...

    - ft_memchr.c

        void *ft_memchr(const void *arr, int c, size_t n);

        - 함수 설명

            arr을 앞에서부터 n의 길이만큼 전진하면서 c를 만나면 그 위치를 반환하고 만나지 못하면 NULL을 반환한다.

            - 로직

                arr의 포인터를 선언한다. c를 unsigned char로 변환한 변수를 선언한다. n과 크기를 비교할 인덱스 i를 선언한다.

                i가 n보다 작을동안 포인터를 전진하면서 c와 같은지를 비교한다.

                만약 같으면 바로 return하고 함수를 종료한다.

                끝까지 c를 찾지못하면 NULL을 반환한다. 

            - 디버깅

                arr의 포인터를 만들때 (unsigned char*) 로 형변환 하지않고 가져옴.

                int c 를 unsigned char 로 형변환 하지않고 비교했음 

    - ft_memcmp.c

        int ft_memcmp(const void *s1, const void *s2, size_t n);

        - 함수 설명

            s1과 s1를 n의 길이만큼 전진하면서 비교한다. 만약 다른 unsigned char를 발견하면 거기서 s1의 값-s2의 값을 반환한다. n까지 갔을때 전부 같은 값이라면 0을 반환한다.

            - 로직

                s1과 s2의 포인터를 선언한다 n과 크기를 비교한 인덱스 i를 선언한다.

                i가 n보다 작을동안 s1 과 s2의 값을 비교한다. 만약 값이 같다면 두 포인터를 전진시킨다.

                다른 값이 나온다면 s1의 값 - s2의 값을 반환하고 함수를 종료한다.

                반복문이 끝날때까지 다른 값이 없다면 0을 반환한다.

            - 디버깅

                s1과 s2를 의 포인터를 만들때 (unsigned char*)로 형변환 하지않고 가져옴.

    - ft_strlen.c

        size_t ft_strlen(const char *str);

        - 함수 설명

            str문자열의 길이를 구한다. str문자열은 '\0'(NULL)을 만날때 종료되므로 그때까지의 길이를 반환한다.

            - 로직

                size_t 변수를 하나 선언해주고 str이 NULL이 아닐때까지 전진시키면서 해당 변수를 ++시켜준다.

                반복문이 NULL을 만나 종료되면 변수를 반환한다.

            - 디버깅

    - ft_strlcpy.c

        size_t ft_strlcpy(char *dst, const char *src, size_t len);

        - 함수 설명

            dst 문자열에 src 를 n의 크기만큼 복사하되, 마지막에 반드시 '\0'으로 종료시킨다. src 문자열의 길이를 반환한다.

            - 로직

                인덱스로도 사용하고 반환할때도 사용할 size_t 변수를 선언한다. dst와 src를 전진시키면서 복사한다. 복사가 끝난 뒤 dst의 마지막에 \0을 붙여준다. 그 다음 src가 \0이 나올때까지 전진시키면서 size_t 변수를 ++해주고 반환한다.

            - 디버깅

                둘중에 하나가 null일때 널 가드를 원래 해줬으나 고려끝에 안하기로 함. 원본함수를 구현한다는 취지에도 어긋나고 null이 0으로 반환되기 때문에 실제 0과 구분할수없다는 문제점이 있을듯.

                진행되다가 src가 null일때 오버플로우 고려해서 반복문에 *src를 조건으로 넣어줌 

                size 가 아닌 size - 1까지 진행한 다음 끝에 \0 입력

    - ft_strlcat.c

        size_t ft_strlcat(char *dest, const char *src, size_t len);

        - 함수 설명

            dest 문자열 뒤에 src를 붙이는 함수. 마지막에 반드시 \0이 입력된다. 반환은 총 길이.

            다만 dest의 길이가 len 이하라면 작동하지 않는다.

            - 로직

                반환할 size_t 변수 total_len을 하나 선언해주고, dest의 값이 null이 되거나 total_len이 len보다 작을때까지 전진한다.

                src의 값이 null이 되거나 total_len이 len - 1보다 작을동안 전진하면서 dest에 src의 값을 복사한다.

                dest의 끝에 '\0'을 입력한다.

                src가 null이 될때까지 total_len과 src를 전진한다음 total_len을 반환한다.

            - 디버깅

                만약 len 이 dest의 크기보다 작다면 바로 src의 크기에 len을 더해서 반환한다.

    - ft_strchr.c

        char *ft_strchr(const char *str, int c);

        - 함수 설명

            str 안에 c가 있는지 검사하는 함수. 만약 c가 있다면 c의 위치를 반환하고, 찾을수 없다면 NULL을 반환한다.

            - 로직

                str의 포인터를 선언한다. c의 char형을 선언한다.

                포인터를 전진시키면서 c와 비교한뒤 같으면 해당 주소를 반환한다.

                str이 \0일때까지 c를 찾지 못하면 NULL을 반환한다.

            - 디버깅

                str의 포인터를 가져올때 (char*) 로 형변환 하지않고 가져옴.

                c 가 NULL 일때 반복문이 정지되기 때문에 해당 주소 반환

    ---

    - ft_strrchr.c

        char *ft_strrchr(const char *str, int c);

        - 함수 설명

            str 안에 c가 있는지 검사하는 함수. str의 뒤에서 부터 찾아서 c의 위치를 반환한다. 찾을수 없다면 NULL을 반환한다. 

            - 로직

                str의 포인터와 c의 char형을 선언한다. 그리고 인덱스로 사용할 i를 선언한다.

                str이 \0이 나올때까지 포인터를 전진시키고 i를 같이 상승시킨다.

                i 가 0이 될때까지 역순으로 c와 비교한뒤 같으면 해당 주소를 반환한다.

                i가 0이 될때까지 c를 찾지 못하면 NULL을 반환한다.

            - 디버깅

                str을 가져올때 (char*) 로 형변환 하지않고 가져옴.

    - ft_strnstr.c

        char *ft_strnstr(const char *s1, const char *s2, size_t n);

        - 함수 설명

            s1 을 n의 길이만큼 검사해서 그 안에 s2가 있는지를 확인하고 있으면 그 시작 주소를 반환하는 함수. 끝날때까지 없으면 NULL반환. s2가 비어있으면 s1의 시작지점 반환.

            - 로직

                반환하는데 사용할 s1의 포인터와 문자열 배열에 접근할 size_t 변수를 하나 만든다.

                s2가 비어있는지 먼저 확인하고 해당 부분 예외처리한다.

                i가 n보다 작을동안 s1[i]의 i를 증가시키면서 ft_strcmp를 사용하여 s2가 같은지를 확인한다.

                같은게 있다면 해당 s1[i]의 주소를 반환한다.

                끝까지 못찾았다면 NULL을 반환한다

            - 디버깅

                s2가 비어있다는건 ft_strlen(s2) 이 0이라는 뜻임

                s2가 NULL 인걸 '\0' 이 아닌 NULL로 적었음.

                s1이 n보다 작을 경우 n을 s1의 크기+1로 만들어야함.

    - ft_strncmp.c

        int ft_strncmp(const char *s1, const char *s2, size_t n);

        - 함수 설명

            fs1과 s2를 앞에서부터 n의 크기만큼 비교한다. 만약 끝까지 같다면 0을 반환하고, 다른 문자가 나온다면 s1 - s2를 반환한다.

            - 로직

                n을 감소시키면서 반복문을 돌려 s1과 s2를 계속 증가시킨다.

                만약 다른 값이 나오면 s1의 값 - s2의 값을 반환한다.

                반복문이 무사히 종료되면 0을 반환한다.

            - 디버깅

                두개 모두 NULL 일때 문자열이기 때문에 정지해야하지만 두개를 같은지만 비교하면 지나치게됨.

    - ft_atoi.c

        int ft_atoi(const char *str);

        - 함수 설명

            문자열 str을 정수형 int로 변환하여 반환하는 함수. 만약 정상적이지 않은 값이라면 0을 반환한다.

            - 로직

                반환할 int 변수와 양수 음수 처리를 할때 사용할 int 변수를 선언한다.

                str 앞에 공백이 있을때를 먼저 처리해준다.

                그 다음 +나 -가 나오면 음수인지 양수인지 확인한 다음 넘어간다

                그 다음 부터 나오는 숫자들을 하나씩 받아서 반환할 변수에 * 10 하고 해당 숫자를 더하는 식으로 10진수를 늘려나간다.

            - 디버깅

    - ft_isalpha.c

        int ft_isalpha(int c);

        - 함수 설명

            c가 아스키 코드로 알파벳인지를 확인하여 맞으면 0이 아닌 수를, 알파벳이 아니라면 0을 반환하는 함수

            - 로직

                c가 A 보다 크거나 같으면 Z 보다 작거나 같으면 a 보다 크거나 같으면 z 보다 작거나 같으면 1을 반환

                아니면 0을 반환

            - 디버깅

    - ft_isdigit.c

        int ft_isdigit(int c);

        - 함수 설명

            c가 아스키 코드로 10진수 숫자인지를 확인하여 맞으면 0이 아닌 수를, 틀리면 0을 반환하는 함수

            - 로직

                c가 0보다 크거나 같으면 9보다 작거나 같으면 1을 반환

                아니라면 0을 반환

            - 디버깅

    - ft_isalnum.c

        int ft_isalnum(int c);

        - 함수 설명

            c가 아스키 코드로 10진수 숫자거나 알파벳이면 0이 아닌 수를, 둘다 아니라면 0을 반환하는 함수

            - 로직

                isalpha 와 isdigit 불러서 if문 안에 넣고 맞으면 1 아니면 0 반환

            - 디버깅

    - ft_isascii.c

        int ft_isascii(int c);

        - 함수 설명

            c가 아스키 코드로 문자 범위(0~127) 안에 있는지를 확인하여 맞으면 0이 아닌 수를, 아니면 0을 반환하는 함수 

            - 로직

                c가 0보다 크거나 같고 127보다 작거나 같으면 1을 아니라면 0을 반환한다.

            - 디버깅

    - ft_isprint.c

        int ft_isprint(int c);

        - 함수 설명

            c가 아스키 코드 중 출력가능한 문자(32~126)라면 0이 아닌 수를, 아니면 0을 반환한다.

            - 로직

                c가 32보다 크거나 같고 126보다 작거나 같으면 1을 아니라면 0을 반환한다.

            - 디버깅

    - ft_toupper.c

        int ft_toupper(int c);

        - 함수 설명

            c가 소문자 알파벳일때 대문자로 변환해주는 함수.

            - 로직

                c가 a보다 크거나 같고 z보다 작거나 같으면 32를 뺀다.

                c를 반환한다.

            - 디버깅

    - ft_tolower.c

        int ft_tolower(int c);

        - 함수 설명

            c가 대문자 알파벳일때 소문자로 변환해주는 함수.

            - 로직

                c가 A보다 크거나 같고 Z보다 작거나 같으면 32를 더한다.

                c를 반환한다.

            - 디버깅

    - ft_calloc.c

        void *ft_calloc(size_t n, size_t size);

        - 함수 설명

            size의 자료형을 지닌 n만큼의 길이를 가진 메모리 저장소를 만든 다음 0으로 초기화해서 반환한다.

            - 로직

                char 포인터 변수를 하나 선언해준다.

                해당 변수에 malloc 을 n * size 만큼 해주는데 만약 malloc에 실패하면 NULL을 반환한다.

                그다음 ft_memset을 이용해서 0으로 초기화해준다.

                해당 변수를 반환한다.

            - 디버깅

                오버플로우, 0 고려해서 실제와 동일하게 동작하도록 처리

    - ft_strdup.c

        char *ft_strdup(const char *s);

        - 함수 설명

            s1의 복제본을 만드는 함수이다. s1의 크기만큼 메모리를 할당해주고 그 다음 s1의 내용을 복사하여 해당 주소값을 반환한다. 할당하지 못한다면 NULL을 반환한다

            - 로직

                s의 크기를 구한다음 그만큼의 메모리를 할당한다

                할당했는지를 확인하여 할당하지 못했다면 NULL을 return한다

                그다음 s를 하나씩 전진시키면서 메모리를 할당한 곳에 복사한다

                메모리의 주소값을 반환한다.

            - 디버깅

- [PART 2]
    - ft_substr.c

        char *ft_substr(char const *s, unsigned int start, size_t len);

        - 함수 설명

            문자열 s에서 start 부터 len만큼의 길이를 복사해서 새로운 문자열을 만들어서 반환한다.

            - 로직

                len의 크기 + 1만큼 malloc해준다. malloc에 실패하면 null 반환

                새로만든 메모리에 s + start 부터 len만큼 strlcpy해준다.

                새로만든 메모리 반환

            - 디버깅

                문자열 s가 NULL인지 확인하고 그렇다면 NULL을 반환한다

                s의 길이가 start보다 작으면 빈 문자열 반환

                s의 길이가 len보다 작으면 len 을 s의 길이 + 1로 변환

    - ft_strjoin.c

        char *ft_strjoin(char const *s1, char const *s2);

        - 함수 설명

            문자열 s1과 s2를 합쳐서 둘이 연결된 형태의 문자열을 반환한다

            - 로직

                둘의 크기를 합친거 + 1만큼의 메모리를 할당한다

                만약 할당에 실패하면 null을 반환한다.

                그다음 strlcpy를 활용하여 메모리에 s1과 s2를 집어넣는다

                해당 메모리의 주소를 반환한다.

            - 디버깅

                둘다  NULL이면 NULL 반환. 둘중 하나면 NULL이면 다른 한개를 반환.

    - ft_strtrim.c

        char *ft_strtrim(char const *s1, char const *set);

        - 함수 설명

            문자열 s1의 처음과 끝에서 set을 제거한 문자열을 반환한다. 

            - 로직

                start 와 end 변수를 선언해준다.

                앞부분의 문자열을 제거하기위해 *s1이 set안에 있다면 늘려가면서 start를 증가시킨다.

                end 를 s1의 길이로 지정해준다음, s1[end-1]이 set안에 있다면 end를 감소시킨다.

                 - strchr 사용

                ft_substr 을 이용하여 s1의 start부터 end 까지 복사본을 만들어 반환한다.

            - 디버깅

                s1이나 set가 null일때 null반환

                substr할때 start부터 end 까지가 아니라 start부터 end - start까지로 해야함

                s1이 전부 사라지는 경우에 대한 예외처리(ft_strdup(""))

                start 와 end 가져오는 부분에서 end 가 str을 넘지 않도록 주의.

    - ft_split.c

        char **ft_split(char const *s, char c);

        - 함수 설명

            문자열 s 를 c로 구분하여 이차원 배열로 만들어서 반환하는 함수. 배열을 만들지 못한다면 null 반환. s안에 c 가 반복된다면 c가 아닌 단어가 나올때까지 전진한다. 

            - 로직

                s를 c로 나누면 몇개의 단어가 나오는지를 확인한다. 

                - s를 전진시키다가 c 가 나오면 단어의 갯수를 하나 늘린다음 c 가 아닌 단어 혹은 null이 나올때까지 다시 전진한다.

                알아낸 단어의 갯수 + 1만큼 malloc 해준다.

                그 다음 메모리를 할당한 포인터에 구분문자가 아닌 단어들의 크기를 구해서 해당 크기만큼 malloc 하고 해당 메모리에 데이터를 넣는다.

                - 만약 중간에 malloc 할수없는 상황이 나오면 이전의 모든 메모리를 free해준다.

                모든 메모리를 입력한다음 처음 할당한 이차 포인터의 마지막에 null을 넣고 반환한다.

            - 디버깅

                s가 비어있을경우 null 반환

                혹시나 마지막에 "\0"을 넣지않았는지 확인

                error로 인한 free시 str[i]를 반복문에 넣게되면 터질 위험이 있음!

    - ft_itoa.c

        char *ft_itoa(int n);

        - 함수 설명

            int n 을 문자열로 변환하여 해당 문자열을 반환하는 함수. 반드시 음수 처리를 해야한다

            - 로직

                n의 길이를 구한다. 만약 음수라면 +1

                n의 길이 + 1만큼 메모리를 할당받는다

                n이 음수라면 맨 앞에 - 를 넣어주고 다음 포인터로 이동한다.

                숫자를 앞에서부터 채워나간다.

                해당 메모리를 반환한다.

            - 디버깅

    - ft_strmapi.c

        char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

        - 함수 설명

            문자열 s에 함수 f를 적용한 문자열을 만들어서 반환하는 함수

            - 로직

                문자열 s의 길이를 구하고 +1의 크기만큼 메모리를 할당받는다

                새로 할당받은 문자열에 s에 f(인덱스, 해당문자)를 적용한 문자를 입력한다.

                마지막에 널을 넣고 해당 문자열을 반환한다.

            - 디버깅

    - ft_putchar_fd.c

        void ft_putchar_fd(char c, int fd);

        - 함수 설명

            문자 c 를 주어진 파일디스크립터로 출력하는 함수

            - 로직

                write의 인자를 fd, &c, 1 로 사용해서 문자를 출력한다.

            - 디버깅

    - ft_putstr_fd.c

        void ft_putstr_fd(char *s, int fd);

        - 함수 설명

            문자열 s 를 주어진 파일디스크립터로 출력하는 함수

            - 로직

                s가 null이 될때까지 반복문을 돌려서 write의 인자를 fd, s, 1로 사용해서 문자를 출력한다.

            - 디버깅

                s 가 NULL일때 널가드

    - ft_putendl_fd.c

        void ft_putendl_fd(char *s, int fd);

        - 함수 설명

            문자열 s 를 주어진 파일디스크립터로 출력하고 \n 으로 끝내는 함수

            - 로직

                s가 null이 될때까지 반복문을 돌려서 write의 인자를 fd, s, 1로 사용해서 문자를 출력한다.

                그다음 \n을 출력한다.

            - 디버깅

                s 가 NULL일때 널가드

    - ft_putnbr_fd.c

        void ft_putnbr_fd(int n, int fd);

        - 함수 설명

            정수 n 을 주어진 파일디스크립터로 출력하는 함수

            - 로직

                n 이 음수면 -1 곱해줌

                그다음 n 이 10보다 크면 10으로 나눠서 재귀함수 실행

                재귀함수 밑에서 문자에 n % 10을 입력하고 파일디스크립터를 사용해서 문자를 출력한다.

            - 디버깅

                int 최소값 처리시 오버플로우 고려

- [BONUS]

    여기는 서브젝트를 참조해서 헤더파일에 구조체를 선언해줘야한다.

    - ft_lstnew.c

        t_list *ft_lstnew(void *content);

        - 함수 설명

            인자 content를 가지고있는 새로운 리스트를 만들어서 반환하는 함수.

            - 로직

                t_list의 크기만큼 메모리를 할당받은 다음 그 메모리의 content에 인자 content를, next에 NULL을 넣고 반환한다.

            - 디버깅

    - ft_lstadd_front.c

        void ft_lstadd_front(t_list **lst, t_list *new);

        - 함수 설명

            리스트의 맨 처음에 new를 넣어주는 함수

            - 로직

                new의 next를 lst로 지정해준다

                lst를 new로 변경한다.

            - 디버깅

    - ft_lstsize.c

        int ft_lstsize(t_list *lst);

        - 함수 설명

            리스트의 길이를 구하는 함수

            - 로직

                count 변수를 하나 선언한다

                lst가 null이라면 종료

                아니라면 count를 증가시키고 다음 노드로 이동한다

                count를 반환한다

            - 디버깅

    - ft_lstlast.c

        t_list *ft_lstlast(t_list *lst);

        - 함수 설명

            리스트의 마지막 요소를 반환하는 함수

            - 로직

                lst→next가 null일때까지 전진한다.

                null을 만다면 해당 주소를 반환한다.

            - 디버깅

                만약 lst가 null이면 null을 반환한다.

    - ft_lstadd_back.c

        void ft_lstadd_back(t_list **lst, t_list *new);

        - 함수 설명

            lst의 마지막에 new를 추가하는 함수

            - 로직

                lst의 마지막까지 전진한다(lstlast함수를 사용)

                lst→next 를 new로 하고 new의 next 를 NULL로 한다.

            - 디버깅

                lst가 비어있으면 lst에 new를 넣고 반환한다.

    - ft_lstdelone.c

        void ft_lstdelone(t_list *lst, void (*del)(void *));

        - 함수 설명

            lst의 content를 del함수를 사용하여 삭제하고 lst를 free하는 함수

            - 로직

                lst→content에 del을 적용한다

                lst를 free한다.

            - 디버깅

    - ft_lstclear.c

        void ft_lstclear(t_list **lst, void (*del)(void *));

        - 함수 설명

            lst이후의 모든 구조체의 content를 del함수를 이용하여 삭제하고 free하는 함수 

            - 로직

                다음 주소를 저장하고있을 t_list 포인터를 만든다

                반복문을 만들어서

                만든 포인터에 다음 주소를 넣고

                del함수를 사용하여 content를 삭제한다음

                해당 주소를 free한다

                해당 주소에 다음 주소를 넣는다.

            - 디버깅

    - ft_lstiter.c

        void ft_lstiter(t_list *lst, void (*f)(void *));

        - 함수 설명

            lst의 content에 함수 f를 순차적으로 적용하는 함수

            - 로직

                반복문을 만들어서 lst가 null일때까지

                lst의 content에 f를 적용하고

                lst에 lst→next를 대입한다

            - 디버깅

    - ft_lstmap.c

        t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

        - 함수 설명

            lst에 f를 적용한 새로운 리스트를 만들어서 반환하는 함수. 만약 중간에 할당을 실패한다면 전체를 삭제하고 null을 반환하는 함수.

            - 로직

                반환값을 저장할 포인터를 하나,  현재 값을 저장할 포인터를 하나 만든다.

                반복문에 lst를 넣고 

                현재 값을 저장할 포인터에 lst→content에 f 를 적용한 값을 넣는다

                만약 할당에 실패한다면 lstclear를 사용한다

                할당에 성공했다면 lstadd_back를 사용하여 새로 만든 메모리 맨 뒤에 포인터를 입력한다

                lst를 전진시킨다

                처음만든 포인터를 반환한다.

            - 디버깅

                lst가 null이라면 null을 반환한다.

- 평가지

    # **Introduction**

    - Remain polite, courteous, respectful and constructivethroughout the evaluation process. The well-being of the communitydepends on it.Identify with the person (or the group) evaluated the eventualdysfunctions of the work. Take the time to discussand debate the problems you have identified.You must consider that there might be some difference in how yourpeers might have understood the project's instructions and thescope of its functionalities. Always keep an open mind and gradehim/her as honestly as possible. The pedagogy is valid only andonly if peer-evaluation is conducted seriously.

    # **Guidelines**

    - Only grade the work that is in the student or group'sGiT repository.Double-check that the GiT repository belongs to the studentor the group. Ensure that the work is for the relevant projectand also check that "git clone" is used in an empty folder.Check carefully that no malicious aliases was used to fool youand make you evaluate something other than the content of theofficial repository.To avoid any surprises, carefully check that both the evaluatingand the evaluated students have reviewed the possible scripts usedto facilitate the grading.Do not blindly trust any script the tester could be wrong !Check the makefile no wildcard, no relink or the final grade is 0.Use make, then make --trace to be sure.If the evaluating student has not completed that particularproject yet, it is mandatory for this student to read theentire subject prior to starting the defence.Use the flags available on this scale to signal an empty repository,a norm error, cheating etc. In these cases,the grading is over and the final grade is 0 (or -42 in case ofcheating). However, with the exception of cheating, you areencouraged to continue to discuss your work (even if you have notfinished it) in order to identify any issues that may have causedthis failure and avoid repeating the same mistake in the future.You should never have to edit any file except the configuration file if it exists.If you want to edit a file, take the time to explicit the reasons with theevaluated student and make sure both of you are okay with this.You must also verify the absence of memory leaks. Any memory allocated on the heap mustbe properly freed before the end of execution.You are allowed to use any of the different tools available on the computer, such asleaks, valgrind, or e_fence. In case of memory leaks, tick the appropriate flag.

    # **Mandatory part**

    *You must test each of the function of the libft, using your own tests.*

    ### **Libc Functions #1**

    Test every function and make sure they're working properly:- ft_memcpy- ft_memccpy- ft_memset- ft_bzero- ft_memmove- ft_memcmp- ft_memchrIs it working?

    Yes No

    ### **Libc Functions #2**

    Test every function and make sure they're working properly:- ft_strlen- ft_isalpha- ft_isdigit- ft_isalnum- ft_isascii- ft_isprintIs it working?

    Yes No

    ### **LibC functions #3**

    Test every function and make sure they're working properly:- ft_toupper- ft_tolower- ft_strchr- ft_strrchrIs it working?

    Yes No

    ### **LibC functions #4**

    Test every function and make sure they're working properly:- ft_strlcat- ft_strlcpy- ft_atoi- ft_strnstr- ft_strncmp- ft_calloc- ft_strdupIs it working?

    Yes No

    ### **Added functions #1**

    Test every function and make sure they're working properly:- ft_substr- ft_strjoin- ft_putchar_fd- ft_putstr_fd- ft_putendl_fd- ft_putnbr_fdIs it working?

    Yes No

    ### **Added functions #2**

    Test every function and make sure they're working properly:- ft_strmapi- ft_strtrim- ft_split- ft_itoaIs it working?

    Yes No

    ---

    # **Bonus**

    *We will look at your bonuses if and only if your mandatory part is excellent. This means that you must complete the mandatory part, beginning to end, and your error management must be flawless, even in cases of twisted or bad usage. So if you didn't score all the points on the mandatory part during this defence bonuses will be totally ignored.*

    ### **ft_lstnew**

    Is it working?

    Yes No

    ### **ft_lstdelone**

    Is it working?

    Yes No

    ### **ft_lstclear**

    Is it working?

    Yes No

    ### **ft_lstadd_front**

    Is it working?

    Yes No

    ### **ft_lstadd_back**

    Is it working?

    Yes No

    ### **ft_lstsize**

    Is it working?

    Yes No

    ### **ft_lstlast**

    Is it working?

    Yes No

    ### **ft_lstiter**

    Is it working?

    Yes No

    ### **ft_lstmap**

    Is it working?

    Yes No
