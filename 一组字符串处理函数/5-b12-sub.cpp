/* 信16 2151299 苏家铭 */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return 0只是一个示例，可改变 */

/* 不允许定义任何形式的外部全局、静态全局、宏定义、只读变量 */

/***************************************************************************
  函数名称：
  功    能：求字符串长度
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i;
    for (i = 0; ; i++){
        if (str[i] == '\0')
            break;
    }
    return i; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：把字符串s2追加到s1后面（含尾0）
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcat(char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int s,j;
    s = tj_strlen(s1);
    j=tj_strlen(s2);
    int i;
    for (i = 0;i<=j; i++) {
        s1[s + i] = s2[i];
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：将字符串s2的前len个字符追加到s1后面，并添加\0
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncat(char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int s, j;
    s = tj_strlen(s1);
    j = tj_strlen(s2);
    int i;
    if (len <= j) {
        for (i = 0; i <= len - 1; i++) {
            s1[s + i] = s2[i];
        }
        s1[s+i] = '\0';
    }
    else if (len > j) {
        for (i = 0; i <= j - 1; i++) {
            s1[s + i] = s2[i];
        }
        s1[s+i] = '\0';
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：将字符串s2复制到s1中，覆盖s1原内容，复制时包含\0
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcpy(char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int s, j;
    s = tj_strlen(s1);
    j = tj_strlen(s2);
    int i;
    for (i = 0; i <= j; i++) {
        s1[i] = s2[i];
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：将字符串s2的前len个字符复制到s1中，覆盖s1原内容，复制时不包含\0
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncpy(char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int s, j;
    s = tj_strlen(s1);
    j = tj_strlen(s2);
    int i;
    if (len <= j) {
        for (i = 0; i <= len - 1; i++) {
            s1[i] = s2[i];
        }
    }
    else if (len > j) {
        for (i = 0; i <= j - 1; i++) {
            s1[i] = s2[i];
        }
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：比较字符串s1和s2的大小
  输入参数：
  返 回 值：
  说    明：英文字母要区分大小写，相等为0，不相等则为第一个不相等字符的ASCII差值
***************************************************************************/
int tj_strcmp(const char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int s, j;
    s = tj_strlen(s1);
    j = tj_strlen(s2);
    int i,m,chazhi;
    m=s > j ? s : j;
    for (i = 0; i < m; i++) {
        chazhi = int(s1[i]) - int(s2[i]);
        if (chazhi == 0)
            continue;
        else if (chazhi != 0)
            return chazhi;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：比较字符串s1和s2的大小
  输入参数：
  返 回 值：
  说    明：英文字母不区分大小写，相等为0，不相等则为第一个不相等字符的ASCII差值，
            大写英文字母按小写来判断
***************************************************************************/
int tj_strcasecmp(const char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int s, j;
    s = tj_strlen(s1);
    j = tj_strlen(s2);
    int i, m, chazhi;
    m = s > j ? s : j;
    int a, b;

    for (i = 0; i < m; i++) {
        a = int(s1[i]);
        b = int(s2[i]);
        if (a >= 65 && a <= 90)
            a = a + 32;
        if (b >= 65 && b <= 90)
            b = b + 32;
        chazhi = a - b;
        if (chazhi == 0)
            continue;
        else if (chazhi != 0)
            return chazhi;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：比较字符串s1和s2前len个字符的大小
  输入参数：
  返 回 值：
  说    明：英文字母要区分大小写，相等为0，不相等则为第一个不相等字符的ASCII差值
***************************************************************************/
int tj_strncmp(const char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int s, j;
    s = tj_strlen(s1);
    j = tj_strlen(s2);
    int i, min, chazhi;
    min = s < j ? s : j;
    if (len <= min) {
        for (i = 0; i < len; i++) {
            chazhi = int(s1[i]) - int(s2[i]);
            if (chazhi == 0)
                continue;
            else if (chazhi != 0)
                return chazhi;
        }
    }
    else if (len > min) {
        for (i = 0; i < min+1; i++) {
            chazhi = int(s1[i]) - int(s2[i]);
            if (chazhi == 0)
                continue;
            else if (chazhi != 0)
                return chazhi;
        }
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：比较字符串s1和s2前len个字符的大小
  输入参数：
  返 回 值：
  说    明：英文字母不区分大小写，相等为0，不相等则为第一个不相等字符的ASCII差值，
            大写英文字母按小写来判断
***************************************************************************/
int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int s, j;
    s = tj_strlen(s1);
    j = tj_strlen(s2);
    int i, min, chazhi;
    min = s < j ? s : j;
    int a, b;
    if (len > min) {
        for (i = 0; i < min+1; i++) {
            a = int(s1[i]);
            b = int(s2[i]);
            if (a >= 65 && a <= 90)
                a = a + 32;
            if (b >= 65 && b <= 90)
                b = b + 32;
            chazhi = a - b;
            if (chazhi == 0)
                continue;
            else if (chazhi != 0)
                return chazhi;
        }
    }
    else if (min >= len) {
        for (i = 0; i < len; i++) {
            a = int(s1[i]);
            b = int(s2[i]);
            if (a >= 65 && a <= 90)
                a = a + 32;
            if (b >= 65 && b <= 90)
                b = b + 32;
            chazhi = a - b;
            if (chazhi == 0)
                continue;
            else if (chazhi != 0)
                return chazhi;
        }
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：将字符串str的小写字母转换为大写字母，其他字符不变，转换后放在原串中
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strupr(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int s;
    s = tj_strlen(str);
    int i,a;
    for (i = 0; i <= s; i++) {
        a = str[i];
        if (a >= 97 && a <= 122) {
            a = a - 32;
            str[i] = a;
        }
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：将字符串str的大写字母转换为小写字母，其他字符不变，转换后放在原串中
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlwr(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int s;
    s = tj_strlen(str);
    int i, a;
    for (i = 0; i <= s; i++) {
        a = str[i];
        if (a >= 65 && a <= 90) {
            a = a + 32;
            str[i] = a;
        }
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：在字符串中寻找字符ch第一次出现的位置，顺序从左到右
  输入参数：
  返 回 值：
  说    明：找到：返回1-n，未找到：返回0
***************************************************************************/
int tj_strchr(const char str[], char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int s;
    s = tj_strlen(str);
    int i;
    for (i = 0; i <= s; i++) {
        if (str[i] == ch)
            return ++i;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：在字符串中寻找字符串substr第一次出现的位置，顺序从左到右
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char str[], const char substr[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int s,j;
    s = tj_strlen(str);
    j = tj_strlen(substr);
    int i;

    for (i = 0; i <= s; i++) {
        if (str[i] == substr[0]) {//找到第一个substr字符
            int k;
            for (k = 0; k < j; k++) {//判断是不是所要找的substr
                if (str[i + k] == substr[k]) {
                    continue;
                }
                else {
                    break;
                }
            }
            if(k==j)
                return ++i;
        }          
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：在字符串中寻找字符ch第一次出现的位置，顺序从右到左
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char str[], const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int s;
    s = tj_strlen(str);
    int i;
    for (i = s-1; i >=0; i--) {
        if (str[i] == ch)
            return ++i;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：在字符串中寻找字符串substr第一次出现的位置，顺序从右到左
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char str[], const char substr[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int s, j;
    s = tj_strlen(str);
    j = tj_strlen(substr);
    int i;

    for (i = s - 1; i >= 0; i--) {
        if (str[i] == substr[0]) {//找到第一个substr字符
            int k;
            for (k = 0; k < j; k++) {//判断是不是所要找的substr
                if (str[i + k] == substr[k]) {
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
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：字符串反转，放入原串中
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrev(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int s;
    s = tj_strlen(str);
    int i,k=0;
    char temp;

    for (i = 0; i < s / 2; i++){
        temp = str[i];
        str[i] = str[s - 1 - i];
        str[s - 1 - i] = temp;
    }

    return 0; //return值可根据需要修改
}