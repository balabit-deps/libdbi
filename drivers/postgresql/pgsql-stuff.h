/*
 * libdbi - database independent abstraction layer for C.
 * Copyright (C) 2001-2002, David Parker and Mark Tobenkin.
 * http://libdbi.sourceforge.net
 * 
 * dbd_pgsql.c: PostgreSQL database support (using libpq)
 * Copyright (C) 2001-2002, David Parker <david@neongoat.com>.
 * http://libdbi.sourceforge.net
 * 
 * $Id: pgsql-stuff.h,v 1.2 2002/06/14 00:28:53 dap Exp $
 */

/* OID declarations from src/interfaces/odbc/pgtypes.h */

#define PG_TYPE_BOOL			16
#define PG_TYPE_BYTEA			17
#define PG_TYPE_CHAR			18
#define PG_TYPE_NAME			19
#define PG_TYPE_INT8			20
#define PG_TYPE_INT2			21
#define PG_TYPE_INT2VECTOR		22
#define PG_TYPE_INT4			23
#define PG_TYPE_REGPROC			24
#define PG_TYPE_TEXT			25
#define PG_TYPE_OID				26
#define PG_TYPE_TID				27
#define PG_TYPE_XID				28
#define PG_TYPE_CID				29
#define PG_TYPE_OIDVECTOR		30
#define PG_TYPE_SET				32
#define PG_TYPE_CHAR2			409
#define PG_TYPE_CHAR4			410
#define PG_TYPE_CHAR8			411
#define PG_TYPE_POINT			600
#define PG_TYPE_LSEG			601
#define PG_TYPE_PATH			602
#define PG_TYPE_BOX				603
#define PG_TYPE_POLYGON			604
#define PG_TYPE_FILENAME		605
#define PG_TYPE_FLOAT4			700
#define PG_TYPE_FLOAT8			701
#define PG_TYPE_ABSTIME			702
#define PG_TYPE_RELTIME			703
#define PG_TYPE_TINTERVAL		704
#define PG_TYPE_UNKNOWN			705
#define PG_TYPE_MONEY			790
#define PG_TYPE_OIDINT2			810
#define PG_TYPE_OIDINT4			910
#define PG_TYPE_OIDNAME			911
#define PG_TYPE_BPCHAR			1042
#define PG_TYPE_VARCHAR			1043
#define PG_TYPE_DATE			1082
#define PG_TYPE_TIME			1083
#define PG_TYPE_DATETIME		1184
#define PG_TYPE_TIMESTAMP		1296
#define PG_TYPE_NUMERIC			1700

/* list from http://www.postgresql.org/idocs/index.php?sql-keywords-appendix.html */

#define PGSQL_RESERVED_WORDS { \
	"ABORT", \
	"ABS", \
	"ABSOLUTE", \
	"ACCESS", \
	"ACTION", \
	"ADA", \
	"ADD", \
	"ADMIN", \
	"AFTER", \
	"AGGREGATE", \
	"ALIAS", \
	"ALL", \
	"ALLOCATE", \
	"ALTER", \
	"ANALYSE", \
	"ANALYZE", \
	"AND", \
	"ANY", \
	"ARE", \
	"ARRAY", \
	"AS", \
	"ASC", \
	"ASENSITIVE", \
	"ASSERTION", \
	"ASSIGNMENT", \
	"ASYMMETRIC", \
	"AT", \
	"ATOMIC", \
	"AUTHORIZATION", \
	"AVG", \
	"BACKWARD", \
	"BEFORE", \
	"BEGIN", \
	"BETWEEN", \
	"BINARY", \
	"BIT", \
	"BITVAR", \
	"BIT_LENGTH", \
	"BLOB", \
	"BOOLEAN", \
	"BOTH", \
	"BREADTH", \
	"BY", \
	"C", \
	"CACHE", \
	"CALL", \
	"CALLED", \
	"CARDINALITY", \
	"CASCADE", \
	"CASCADED", \
	"CASE", \
	"CAST", \
	"CATALOG", \
	"CATALOG_NAME", \
	"CHAIN", \
	"CHAR", \
	"CHARACTER", \
	"CHARACTERISTICS", \
	"CHARACTER_LENGTH", \
	"CHARACTER_SET_CATALOG", \
	"CHARACTER_SET_NAME", \
	"CHARACTER_SET_SCHEMA", \
	"CHAR_LENGTH", \
	"CHECK", \
	"CHECKED", \
	"CHECKPOINT", \
	"CLASS", \
	"CLASS_ORIGIN", \
	"CLOB", \
	"CLOSE", \
	"CLUSTER", \
	"COALESCE", \
	"COBOL", \
	"COLLATE", \
	"COLLATION", \
	"COLLATION_CATALOG", \
	"COLLATION_NAME", \
	"COLLATION_SCHEMA", \
	"COLUMN", \
	"COLUMN_NAME", \
	"COMMAND_FUNCTION", \
	"COMMAND_FUNCTION_CODE", \
	"COMMENT", \
	"COMMIT", \
	"COMMITTED", \
	"COMPLETION", \
	"CONDITION_NUMBER", \
	"CONNECT", \
	"CONNECTION", \
	"CONNECTION_NAME", \
	"CONSTRAINT", \
	"CONSTRAINTS", \
	"CONSTRAINT_CATALOG", \
	"CONSTRAINT_NAME", \
	"CONSTRAINT_SCHEMA", \
	"CONSTRUCTOR", \
	"CONTAINS", \
	"CONTINUE", \
	"CONVERT", \
	"COPY", \
	"CORRESPONDING", \
	"COUNT", \
	"CREATE", \
	"CREATEDB", \
	"CREATEUSER", \
	"CROSS", \
	"CUBE", \
	"CURRENT", \
	"CURRENT_DATE", \
	"CURRENT_PATH", \
	"CURRENT_ROLE", \
	"CURRENT_TIME", \
	"CURRENT_TIMESTAMP", \
	"CURRENT_USER", \
	"CURSOR", \
	"CURSOR_NAME", \
	"CYCLE", \
	"DATA", \
	"DATABASE", \
	"DATE", \
	"DATETIME_INTERVAL_CODE", \
	"DATETIME_INTERVAL_PRECISION", \
	"DAY", \
	"DEALLOCATE", \
	"DEC", \
	"DECIMAL", \
	"DECLARE", \
	"DEFAULT", \
	"DEFERRABLE", \
	"DEFERRED", \
	"DEFINED", \
	"DEFINER", \
	"DELETE", \
	"DELIMITERS", \
	"DEPTH", \
	"DEREF", \
	"DESC", \
	"DESCRIBE", \
	"DESCRIPTOR", \
	"DESTROY", \
	"DESTRUCTOR", \
	"DETERMINISTIC", \
	"DIAGNOSTICS", \
	"DICTIONARY", \
	"DISCONNECT", \
	"DISPATCH", \
	"DISTINCT", \
	"DO", \
	"DOMAIN", \
	"DOUBLE", \
	"DROP", \
	"DYNAMIC", \
	"DYNAMIC_FUNCTION", \
	"DYNAMIC_FUNCTION_CODE", \
	"EACH", \
	"ELSE", \
	"ENCODING", \
	"END", \
	"EQUALS", \
	"ESCAPE", \
	"EVERY", \
	"EXCEPT", \
	"EXCEPTION", \
	"EXCLUSIVE", \
	"EXEC", \
	"EXECUTE", \
	"EXISTING", \
	"EXISTS", \
	"EXPLAIN", \
	"EXTEND", \
	"EXTERNAL", \
	"EXTRACT", \
	"FALSE", \
	"FETCH", \
	"FINAL", \
	"FIRST", \
	"FLOAT", \
	"FOR", \
	"FORCE", \
	"FOREIGN", \
	"FORTRAN", \
	"FORWARD", \
	"FOUND", \
	"FREE", \
	"FROM", \
	"FULL", \
	"FUNCTION", \
	"G", \
	"GENERAL", \
	"GENERATED", \
	"GET", \
	"GLOBAL", \
	"GO", \
	"GOTO", \
	"GRANT", \
	"GRANTED", \
	"GROUP", \
	"GROUPING", \
	"HANDLER", \
	"HAVING", \
	"HIERARCHY", \
	"HOLD", \
	"HOST", \
	"HOUR", \
	"IDENTITY", \
	"IGNORE", \
	"ILIKE", \
	"IMMEDIATE", \
	"IMPLEMENTATION", \
	"IN", \
	"INCREMENT", \
	"INDEX", \
	"INDICATOR", \
	"INFIX", \
	"INHERITS", \
	"INITIALIZE", \
	"INITIALLY", \
	"INNER", \
	"INOUT", \
	"INPUT", \
	"INSENSITIVE", \
	"INSERT", \
	"INSTANCE", \
	"INSTANTIABLE", \
	"INSTEAD", \
	"INT", \
	"INTEGER", \
	"INTERSECT", \
	"INTERVAL", \
	"INTO", \
	"INVOKER", \
	"IS", \
	"ISNULL", \
	"ISOLATION", \
	"ITERATE", \
	"JOIN", \
	"K", \
	"KEY", \
	"KEY_MEMBER", \
	"KEY_TYPE", \
	"LANCOMPILER", \
	"LANGUAGE", \
	"LARGE", \
	"LAST", \
	"LATERAL", \
	"LEADING", \
	"LEFT", \
	"LENGTH", \
	"LESS", \
	"LEVEL", \
	"LIKE", \
	"LIMIT", \
	"LISTEN", \
	"LOAD", \
	"LOCAL", \
	"LOCALTIME", \
	"LOCALTIMESTAMP", \
	"LOCATION", \
	"LOCATOR", \
	"LOCK", \
	"LOWER", \
	"M", \
	"MAP", \
	"MATCH", \
	"MAX", \
	"MAXVALUE", \
	"MESSAGE_LENGTH", \
	"MESSAGE_OCTET_LENGTH", \
	"MESSAGE_TEXT", \
	"METHOD", \
	"MIN", \
	"MINUTE", \
	"MINVALUE", \
	"MOD", \
	"MODE", \
	"MODIFIES", \
	"MODIFY", \
	"MODULE", \
	"MONTH", \
	"MORE", \
	"MOVE", \
	"MUMPS", \
	"NAME", \
	"NAMES", \
	"NATIONAL", \
	"NATURAL", \
	"NCHAR", \
	"NCLOB", \
	"NEW", \
	"NEXT", \
	"NO", \
	"NOCREATEDB", \
	"NOCREATEUSER", \
	"NONE", \
	"NOT", \
	"NOTHING", \
	"NOTIFY", \
	"NOTNULL", \
	"NULL", \
	"NULLABLE", \
	"NULLIF", \
	"NUMBER", \
	"NUMERIC", \
	"OBJECT", \
	"OCTET_LENGTH", \
	"OF", \
	"OFF", \
	"OFFSET", \
	"OIDS", \
	"OLD", \
	"ON", \
	"ONLY", \
	"OPEN", \
	"OPERATION", \
	"OPERATOR", \
	"OPTION", \
	"OPTIONS", \
	"OR", \
	"ORDER", \
	"ORDINALITY", \
	"OUT", \
	"OUTER", \
	"OUTPUT", \
	"OVERLAPS", \
	"OVERLAY", \
	"OVERRIDING", \
	"OWNER", \
	"PAD", \
	"PARAMETER", \
	"PARAMETERS", \
	"PARAMETER_MODE", \
	"PARAMETER_NAME", \
	"PARAMETER_ORDINAL_POSITION", \
	"PARAMETER_SPECIFIC_CATALOG", \
	"PARAMETER_SPECIFIC_NAME", \
	"PARAMETER_SPECIFIC_SCHEMA", \
	"PARTIAL", \
	"PASCAL", \
	"PASSWORD", \
	"PATH", \
	"PENDANT", \
	"PLI", \
	"POSITION", \
	"POSTFIX", \
	"PRECISION", \
	"PREFIX", \
	"PREORDER", \
	"PREPARE", \
	"PRESERVE", \
	"PRIMARY", \
	"PRIOR", \
	"PRIVILEGES", \
	"PROCEDURAL", \
	"PROCEDURE", \
	"PUBLIC", \
	"READ", \
	"READS", \
	"REAL", \
	"RECURSIVE", \
	"REF", \
	"REFERENCES", \
	"REFERENCING", \
	"REINDEX", \
	"RELATIVE", \
	"RENAME", \
	"REPEATABLE", \
	"RESET", \
	"RESTRICT", \
	"RESULT", \
	"RETURN", \
	"RETURNED_LENGTH", \
	"RETURNED_OCTET_LENGTH", \
	"RETURNED_SQLSTATE", \
	"RETURNS", \
	"REVOKE", \
	"RIGHT", \
	"ROLE", \
	"ROLLBACK", \
	"ROLLUP", \
	"ROUTINE", \
	"ROUTINE_CATALOG", \
	"ROUTINE_NAME", \
	"ROUTINE_SCHEMA", \
	"ROW", \
	"ROWS", \
	"ROW_COUNT", \
	"RULE", \
	"SAVEPOINT", \
	"SCALE", \
	"SCHEMA", \
	"SCHEMA_NAME", \
	"SCOPE", \
	"SCROLL", \
	"SEARCH", \
	"SECOND", \
	"SECTION", \
	"SECURITY", \
	"SELECT", \
	"SELF", \
	"SENSITIVE", \
	"SEQUENCE", \
	"SERIAL", \
	"SERIALIZABLE", \
	"SERVER_NAME", \
	"SESSION", \
	"SESSION_USER", \
	"SET", \
	"SETOF", \
	"SETS", \
	"SHARE", \
	"SHOW", \
	"SIMILAR", \
	"SIMPLE", \
	"SIZE", \
	"SMALLINT", \
	"SOME", \
	"SOURCE", \
	"SPACE", \
	"SPECIFIC", \
	"SPECIFICTYPE", \
	"SPECIFIC_NAME", \
	"SQL", \
	"SQLCODE", \
	"SQLERROR", \
	"SQLEXCEPTION", \
	"SQLSTATE", \
	"SQLWARNING", \
	"START", \
	"STATE", \
	"STATEMENT", \
	"STATIC", \
	"STDIN", \
	"STDOUT", \
	"STRUCTURE", \
	"STYLE", \
	"SUBCLASS_ORIGIN", \
	"SUBLIST", \
	"SUBSTRING", \
	"SUM", \
	"SYMMETRIC", \
	"SYSID", \
	"SYSTEM", \
	"SYSTEM_USER", \
	"TABLE", \
	"TABLE_NAME", \
	"TEMP", \
	"TEMPLATE", \
	"TEMPORARY", \
	"TERMINATE", \
	"THAN", \
	"THEN", \
	"TIME", \
	"TIMESTAMP", \
	"TIMEZONE_HOUR", \
	"TIMEZONE_MINUTE", \
	"TO", \
	"TOAST", \
	"TRAILING", \
	"TRANSACTION", \
	"TRANSACTIONS_COMMITTED", \
	"TRANSACTIONS_ROLLED_BACK", \
	"TRANSACTION_ACTIVE", \
	"TRANSFORM", \
	"TRANSFORMS", \
	"TRANSLATE", \
	"TRANSLATION", \
	"TREAT", \
	"TRIGGER", \
	"TRIGGER_CATALOG", \
	"TRIGGER_NAME", \
	"TRIGGER_SCHEMA", \
	"TRIM", \
	"TRUE", \
	"TRUNCATE", \
	"TRUSTED", \
	"TYPE", \
	"UNCOMMITTED", \
	"UNDER", \
	"UNION", \
	"UNIQUE", \
	"UNKNOWN", \
	"UNLISTEN", \
	"UNNAMED", \
	"UNNEST", \
	"UNTIL", \
	"UPDATE", \
	"UPPER", \
	"USAGE", \
	"USER", \
	"USER_DEFINED_TYPE_CATALOG", \
	"USER_DEFINED_TYPE_NAME", \
	"USER_DEFINED_TYPE_SCHEMA", \
	"USING", \
	"VACUUM", \
	"VALID", \
	"VALUE", \
	"VALUES", \
	"VARCHAR", \
	"VARIABLE", \
	"VARYING", \
	"VERBOSE", \
	"VERSION", \
	"VIEW", \
	"WHEN", \
	"WHENEVER", \
	"WHERE", \
	"WITH", \
	"WITHOUT", \
	"WORK", \
	"WRITE", \
	"YEAR", \
	"ZONE", \
	NULL }
