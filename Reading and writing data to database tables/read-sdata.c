#include <stdio.h>
#include <mysql.h>

/*#define DB_HOST "ubuntuserv"
#define DB_USER "daniil1"
#define DP_PASS "D170895"
#define DB_NAME "DATANDO"
#define DB_TABLE "MCU"*/

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
      fprintf(stderr, "mysql_init() failed\n");
  }


//подключение к базе данных DATANDO
  if (mysql_real_connect(con, "ubuntuserv", "daniil1", "d170895", "DATANDO", 0, NULL, 0) == NULL) 
  {
      finish_with_error(con);
  }


//Отправить запрос на вывод на экран всех записей из таблицы SDATA
  if (mysql_query(con, "SELECT * FROM SDATA")) 
  {
      finish_with_error(con);
  } 


  MYSQL_RES *result = mysql_store_result(con);


//Если результат равен значению NULL, то вывести на экран ошибку
  if (result == NULL) 
  {
     finish_with_error(con);
  }
  
  
  int num_fields = mysql_num_fields(result);

  MYSQL_ROW row;


//Вывод на экран записей из таблицы SDATA
  while ((row = mysql_fetch_row(result))) 
  {

      for(int i = 0; i < num_fields; i++) 
      {
          printf("%s ", row[i] ? row[i] : "NULL");
      }
          printf("\n");
  }


  mysql_free_result(result);
  mysql_close(con);
  
  exit(0);
}
