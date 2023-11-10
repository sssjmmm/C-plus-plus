/* 2151299 苏家铭 班信16 */

#include <cstdio>   //NULL
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
/***************************************************************************
  函数名称：
  功    能：求字符串长度
  输入参数：
  返 回 值：字符串长度
  说    明：
***************************************************************************/
int tj_strlen(const char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i=0;
    const char* p=str;
    if (p == NULL)
        return 0;
    for (;*p!='\0'; p++) {
        i++;
    }
    return i;
}

/***************************************************************************
  函数名称：
  功    能：把字符串s2追加到s1后面（含尾0）
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strcat(char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int s, j;
    s = tj_strlen(s1);
    j = tj_strlen(s2);
    if (s2==NULL||s1==NULL) {
        return s1;
    }

    char* p = s1;
    p += s;
    
    for (; *s2!='\0'; p++) {
        *p = *s2++;
    }
    *p = '\0';
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：将字符串s2的前len个字符追加到s1后面，并添加\0
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strncat(char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int s, j;
    s = tj_strlen(s1);
    j = tj_strlen(s2);
    if (s2 == NULL || s1 == NULL) {
        return s1;
    }

    char* p = s1;//工作指针
    const char* p2;//定位
    p += s;
    p2 =s2+len-1;
    if (len <= j) {
        for (;s2<=p2; p++) {
            *p = *s2++;
        }
    }
    else if (len > j) {
        for (; *s2 != '\0'; p++) {
            *p = *s2++;
        }
    }

    *p = '\0';

    return s1;
}

/***************************************************************************
  函数名称：
  功    能：将字符串s2复制到s1中，覆盖s1原内容，复制时包含\0
  输入参数：
  返 回 值：新s1
  说    明：
***************************************************************************/
char* tj_strcpy(char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int s, j;
    s = tj_strlen(s1);
    j = tj_strlen(s2);
    if (s1 == NULL) {
        return s1;
    }
    if (s2 == NULL ) {
        *s1 = '\0';
        return s1;
    }

    char* p = s1;

    for (; *s2 != '\0'; p++) {
        *p = *s2++;
    }
    *p = '\0';
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：将字符串s2的前len个字符复制到s1中，覆盖s1原内容，复制时不包含\0
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strncpy(char* s1, const char* s2, const int len)
{
    int s, j;
    s = tj_strlen(s1);
    j = tj_strlen(s2);
    if (s1 == NULL) {
        return s1;
    }
    if (s2 == NULL) {
        return s1;
    }

    char* p = s1;//工作指针
    const char* p2;//定位

    p2 = s2 + len - 1;
    if (len <= j) {
        for (; s2 <= p2; p++) {
            *p = *s2++;
        }
    }
    else if (len > j) {
        for (; *s2 != '\0'; p++) {
            *p = *s2++;
        }
    }


    return s1;
}

/***************************************************************************
  函数名称：
  功    能：比较字符串s1和s2的大小
  输入参数：
  返 回 值：
  说    明：英文字母要区分大小写，相等为0，不相等则为第一个不相等字符的ASCII差值
***************************************************************************/
int tj_strcmp(const char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int s, j;
    s = tj_strlen(s1);
    j = tj_strlen(s2);
    if (s1 == NULL) {
        if (s2 == NULL)
            return 0;
        return -1;
    }
    if (s2 == NULL) {
        return 1;
    }
    int i, m, chazhi;
    const char* p1=s1, * p2=s2;
    m = s > j ? s : j;//max
    for (i = 0; i < m; i++) {
        chazhi = int(*p1) - int(*p2);
        p1++;
        p2++;
        if (chazhi == 0)
            continue;
        else if (chazhi != 0)
            return chazhi;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：比较字符串s1和s2的大小
  输入参数：
  返 回 值：
  说    明：英文字母不区分大小写，相等为0，不相等则为第一个不相等字符的ASCII差值，
            大写英文字母按小写来判断
***************************************************************************/
int tj_strcasecmp(const char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int s, j;
    s = tj_strlen(s1);
    j = tj_strlen(s2);
    if (s1 == NULL) {
        if (s2 == NULL)
            return 0;
        return -1;
    }
    if (s2 == NULL) {
        return 1;
    }
    int i, m, chazhi,add1=0,add2=0;
    m = s > j ? s : j;//max
    const char* p1=s1, *p2=s2;
    
    for (i = 0; i < m; i++) {

        if (*p1 >= 65 && *p1 <= 90)
            add1 = 32;
        if (*p2 >= 65 && *p2 <= 90)
            add2=32;
        chazhi = int(*p1)+add1 - int(*p2)-add2;
        add1 = 0;
        add2 = 0;
        p1++;
        p2++;
        if (chazhi == 0)
            continue;
        else if (chazhi != 0)
            return chazhi;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：比较字符串s1和s2前len个字符的大小
  输入参数：
  返 回 值：
  说    明：英文字母要区分大小写，相等为0，不相等则为第一个不相等字符的ASCII差值
***************************************************************************/
int tj_strncmp(const char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int s, j;
    s = tj_strlen(s1);
    j = tj_strlen(s2);
    if (s1 == NULL) {
        if (s2 == NULL)
            return 0;
        return -1;
    }
    if (s2 == NULL) {
        return 1;
    }
    int i, min, chazhi;
    const char* p1 = s1, * p2 = s2;
    min = s < j ? s : j;//min
    if (len <= min) {
        for (i = 0; i < len; i++) {
            chazhi = int(*p1) - int(*p2);
            p1++;
            p2++;
            if (chazhi == 0)
                continue;
            else if (chazhi != 0)
                return chazhi;
        }
    }
    else if (len > min) {
        for (i = 0; i < min + 1; i++) {
            chazhi = int(*p1) - int(*p2);
            p1++;
            p2++;
            if (chazhi == 0)
                continue;
            else if (chazhi != 0)
                return chazhi;
        }
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：比较字符串s1和s2前len个字符的大小
  输入参数：
  返 回 值：
  说    明：英文字母不区分大小写，相等为0，不相等则为第一个不相等字符的ASCII差值，
            大写英文字母按小写来判断
***************************************************************************/
int tj_strcasencmp(const char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int s, j;
    s = tj_strlen(s1);
    j = tj_strlen(s2);
    if (s1 == NULL) {
        if (s2 == NULL)
            return 0;
        return -1;
    }
    if (s2 == NULL) {
        return 1;
    }
    int i, min, chazhi;
    const char* p1 = s1, * p2 = s2;
    min = s < j ? s : j;
    int add1 = 0, add2 = 0;
    if (len > min) {
        for (i = 0; i < min + 1; i++) {
            if (*p1 >= 65 && *p1 <= 90)
                add1 = 32;
            if (*p2 >= 65 && *p2 <= 90)
                add2 = 32;
            chazhi = int(*p1) + add1 - int(*p2) - add2;
            add1 = 0;
            add2 = 0;
            p1++;
            p2++;
            if (chazhi == 0)
                continue;
            else if (chazhi != 0)
                return chazhi;
        }
    }
    else if (min >= len) {
        for (i = 0; i < len; i++) {
            if (*p1 >= 65 && *p1 <= 90)
                add1 = 32;
            if (*p2 >= 65 && *p2 <= 90)
                add2 = 32;
            chazhi = int(*p1) + add1 - int(*p2) - add2;
            add1 = 0;
            add2 = 0;
            p1++;
            p2++;
            if (chazhi == 0)
                continue;
            else if (chazhi != 0)
                return chazhi;
        }
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：将字符串str的小写字母转换为大写字母，其他字符不变，转换后放在原串中
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strupr(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return str;
    int s;
    s = tj_strlen(str);
    char* p;
    for (p=str; *p!='\0'; p++) {
        if (*p >= 97 && *p <= 122) {
            *p = *p - 32;
        }
    }
    return str;
}

/***************************************************************************
  函数名称：
  功    能：将字符串str的大写字母转换为小写字母，其他字符不变，转换后放在原串中
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strlwr(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return str;
    int s;
    s = tj_strlen(str);
    char* p;
    for (p = str; *p != '\0'; p++) {
        if (*p >= 65 && *p <= 90) {
            *p = *p + 32;
        }
    }
    return str;
}

/***************************************************************************
  函数名称：
  功    能：在字符串中寻找字符ch第一次出现的位置，顺序从左到右
  输入参数：
  返 回 值：
  说    明：找到：返回1-n，未找到：返回0
***************************************************************************/
int tj_strchr(const char* str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return 0;
    int s,i=0;
    s = tj_strlen(str);
    const char* p;
    for (p = str; *p != '\0'; p++,i++) {
        if (*p == ch)
            return ++i;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：在字符串中寻找字符串substr第一次出现的位置，顺序从左到右
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char* str, const char* substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL||substr==NULL)
        return 0;
    int s, j,i=0;
    s = tj_strlen(str);
    j = tj_strlen(substr);
    const char* p,*ps,*pa;
    for (p = str; *p != '\0'; p++, i++) {
        if (*p == *substr) {//找到第一个substr字符
            int k=0;
            for (ps = substr, pa = p; *ps!='\0'; pa++,ps++, k++) {//判断是不是所要找的substr
                if (*pa == *ps) {
                    continue;
                }
                else {
                    break;
                }
            }
            if (k == j)
                return ++i;
        }
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：在字符串中寻找字符ch第一次出现的位置，顺序从右到左
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char* str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return 0;
    int s;
    s = tj_strlen(str);
    int i;
    const char* p=str;
    while (*p != '\0')
        p++;
    p--;//指向最后一个字符

    for (i = s - 1; p>=str; p--,i--) {
        if (*p==ch)
            return ++i;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：在字符串中寻找字符串substr第一次出现的位置，顺序从右到左
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char* str, const char* substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL || substr == NULL)
        return 0;
    int s, j, i = 0;
    s = tj_strlen(str);
    j = tj_strlen(substr);
    const char* p=str, * ps, * pa;
    while (*p != '\0')
        p++;
    p--;//指向最后一个字符
    for (i = s - 1; p >= str; p--, i--) {
        if (*p == *substr) {//找到第一个substr字符
            int k = 0;
            for (ps = substr, pa = p; *ps != '\0'; pa++, ps++, k++) {//判断是不是所要找的substr
                if (*pa == *ps) {
                    continue;
                }
                else {
                    break;
                }
            }
            if (k == j)
                return ++i;
        }
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：字符串反转，放入原串中
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strrev(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return str;
    int s;
    s = tj_strlen(str);
    char* p1 = str,*p2=str,*p0=str;
    char temp;
    while (*p2 != '\0')
        p2++;
    p2--;//指向最后一个字符
    for (; p1 < p0 + s / 2; p1++,p2--) {
        temp = *p1;
        *p1 = *p2;
        *p2 = temp;
    }
    return str;
}