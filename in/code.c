int func(int a,int b,int baka)
{
    int sou = 0;
    while(sou < 100)
    {
        if(sou == 50)
        {
            return sou;
        }

        sou = sou + 1;
    }
}

char degozaru(char c,char ebi)
{
    return c + ebi;
}

int main(void)
{
    int result = func(6,5,3);
    if(result > 2)
    {
        return 5;
    }
    return result;
}