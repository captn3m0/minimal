#include <sqlite3.h>
#include <string.h>

#define sqlcall(expr) \
    do { \
        int _value = (expr); \
        if (_value == 0 || (_value >= 100 && _value < 200)) \
            break; \
        fprintf(stderr, "%s(%u): sqlcall(%u:%s): %s\n", __FILE__, __LINE__, _value, #expr, sqlite3_errmsg(database_)); \
        exit(1); \
    } while (false)

int sqlite3_bind_string(sqlite3_stmt *stmt, int n, const char *value) {
    if (value == NULL)
        return sqlite3_bind_null(stmt, n);
    else
        return sqlite3_bind_text(stmt, n, strdup(value), -1, &free);
}

int sqlite3_bind_boolean(sqlite3_stmt *stmt, int n, bool value) {
    return sqlite3_bind_int(stmt, n, value ? 1 : 0);
}

char *sqlite3_column_string(sqlite3_stmt *stmt, int n) {
    const unsigned char *value = sqlite3_column_text(stmt, n);
    return value == NULL ? NULL : strdup((const char *) value);
}

bool sqlite3_column_boolean(sqlite3_stmt *stmt, int n) {
    return sqlite3_column_int(stmt, n) != 0;
}
