#include <stdio.h>
#include <mysql.h>

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}

int main(int argc, char **argv) 
{
  MYSQL *con = mysql_init(NULL);

  if (con == NULL) 
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      exit(1);
  }


//подключение к базе данных DATANDO
  if (mysql_real_connect(con, "ubuntuserv", "daniil2", "d170895", "DATANDO", 0, NULL, 0) == NULL) 
  {
      finish_with_error(con);
  }


//добавление записей в таблицу SDATA для температурных датчиков и датчиков электрического напряжения
  for(int i = 1; i <= 1; i++)
  {
    if(i==1)
    {
      int min=0;
      float temp;
      for(int j=1; j<=100000; j++)
      {
        char str[80];
        temp=20+rand()%(39-20);
        min+=1+rand()%(7-1);
        sprintf(str, "%d:0.000000", min);
        if (mysql_query(con, "INSERT INTO SDATA(id, SMC_P-CROSS-FK, Date&Time, Sensor's Value) VALUES(j, i, (SELECT ADDTIME('2021-12-31 10:54:28:000000', 'str')), temp)"))
        {
            finish_with_error(con);
        }
        j++;
      }
    }
    if(i==2)
    {
      int min=2;
      float volt;
      for(int j=0; j<=100000; j++)
      {
        char str[80];
        volt=207+rand()%(253-207);
        min+=1+rand()%(7-1);
        outmin=sprintf(str, "%min:0.000000", min);
        if (mysql_query(con, "INSERT INTO SDATA VALUES(, i, SELECT ADDTIME('2021-12-31 10:54:28:000000', outmin), temp)"))
        {
            finish_with_error(con);
        }
        j++;
      }
    }
    if(i==3)
    {
      int min=10;
      float temp;
      for(int j=0; j<=100000; j++)
      {
        char str[80];
        temp=20+rand()%(39-20);
        min+=1+rand()%(7-1);
        outmin=sprintf(str, "%min:0.000000", min);
        if (mysql_query(con, "INSERT INTO SDATA VALUES(, i, SELECT ADDTIME('2021-12-31 10:54:28:000000', outmin), temp)"))
        {
            finish_with_error(con);
        }
        j++;
      }
    }
    if(i==4)
    {
      int min=12;
      float volt;
      for(int j=0; j<=100000; j++)
      {
        char str[80];
        volt=207+rand()%(253-207);
        min+=1+rand()%(7-1);
        outmin=sprintf(str, "%min:0.000000", min);
        if (mysql_query(con, "INSERT INTO SDATA VALUES(, i, SELECT ADDTIME('2021-12-31 10:54:28:000000', outmin), temp)"))
        {
            finish_with_error(con);
        }
        j++;
      }
    }
    if(i==5)
    {
      int min=20;
      float temp;
      for(int j=0; j<=100000; j++)
      {
        char str[80];
        temp=20+rand()%(39-20);
        min+=1+rand()%(7-1);
        outmin=sprintf(str, "%min:0.000000", min);
        if (mysql_query(con, "INSERT INTO SDATA VALUES(, i, SELECT ADDTIME('2021-12-31 10:54:28:000000', outmin), temp)"))
        {
            finish_with_error(con);
        }
        j++;
      }
    }
    if(i==6)
    {
      int min=22;
      float volt;
      for(int j=0; j<=100000; j++)
      {
        char str[80];
        volt=207+rand()%(253-207);
        min+=1+rand()%(7-1);
        outmin=sprintf(str, "%min:0.000000", min);
        if (mysql_query(con, "INSERT INTO SDATA VALUES(, i, SELECT ADDTIME('2021-12-31 10:54:28:000000', outmin), temp)"))
        {
            finish_with_error(con);
        }
        j++;
      }
    }
  }


  mysql_close(con);
  exit(0);

}


