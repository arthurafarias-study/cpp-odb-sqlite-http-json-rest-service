
// file      : hello/database.hxx
// copyright : not copyrighted - public domain

//
// Create concrete database instance based on the DATABASE_* macros.
//

#ifndef DATABASE_HXX
#define DATABASE_HXX

#include <string>
#include <memory>  // std::auto_ptr
#include <cstdlib> // std::exit
#include <iostream>

#include <odb/database.hxx>

#if defined(DATABASE_MYSQL)
#include <odb/mysql/database.hxx>
#elif defined(DATABASE_SQLITE)
#include <odb/connection.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>
#elif defined(DATABASE_PGSQL)
#include <odb/pgsql/database.hxx>
#elif defined(DATABASE_ORACLE)
#include <odb/oracle/database.hxx>
#elif defined(DATABASE_MSSQL)
#include <odb/mssql/database.hxx>
#else
#error unknown database; did you forget to define the DATABASE_* macros?
#endif

namespace com::example
{
    class database : public odb::sqlite::database
    {
    public:
        database(const std::string &name,
                 bool clear = false,
                 int flags = SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE,
                 bool foreign_keys = true,
                 const std::string &vfs = "",
                 odb::details::transfer_ptr<odb::sqlite::connection_factory> =
                     odb::details::transfer_ptr<odb::sqlite::connection_factory>());
    };
}

#endif // DATABASE_HXX