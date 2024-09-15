#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

int main(){
    PGconn *conn;
    PGresult *res;

    conn = PQconnectdb("dbname=postgres user=postgres password=postgres host=localhost");

    if (PQstatus(conn) == CONNECTION_BAD){
        fprintf(stderr, "Connection to database failed: %s\n", PQerrorMessage(conn));
        PQfinish(conn);
        exit(1);
    }

    printf("Connection to database successful\n");

    res = PQexec(conn, "SELECT * FROM users LIMIT 1");

    if (PQresultStatus(res) != PGRES_TUPLES_OK){
        fprintf(stderr, "SELECT failed: %s\n", PQerrorMessage(conn));
        PQclear(res);
        PQfinish(conn);
        exit(1);
    }

    if (PQntuples(res) == 1) {
        printf("User: %s\n", PQgetvalue(res, 0, 1));
    } else {
        printf("No data retrieved\n");
    }

    PQclear(res);
    PQfinish(conn);

    return 0;
}
