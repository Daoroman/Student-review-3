bool IsConnected(string_view db_name, int db_connection_timeout, DBHandler db, DBConnector connector) {
    if (db_name.starts_with("tmp."s)) {
        db = connector.ConnectTmp(db_name, db_connection_timeout);
    }
    else {
        db = connector.Connect(db_name, db_connection_timeout);
    }
    return !(!db_allow_exceptions && !db.IsOK());
}

DBQuery BuildQuery(int min_age, int max_age, string_view name_filter, DBHandler db) {
    ostringstream query_str;
    query_str << "from Persons "s
        << "select Name, Age "s
        << "where Age between "s << min_age << " and "s << max_age << " "s
        << "and Name like '%"s << db.Quote(name_filter) << "%'"s;
   return DBQuery query(query_str.str());

}

//Добавить комментраии к аргументам функции. 
vector<Person> LoadPersons(string_view db_name, int db_connection_timeout, bool db_allow_exceptions,
    DBLogLevel db_log_level, int min_age, int max_age, string_view name_filter) {
    // Добавить комментарии к DBConnector и DBHandler
    DBConnector connector(db_allow_exceptions, db_log_level);
    DBHandler db;

     if (!IsConnected(db_name, db_connection_timeout, db_log_level, connector, db) && !db_allow_exceptions) {
        return {};
    }
    // Добавить комментарии к DBQuery
    DBQuery query = BuildQuery(min_age, max_age, name_filter, db);

    vector<Person> persons;
    for (auto [name, age] : db.LoadRows<string, int>(query)) {
        persons.push_back({ move(name), age });
    }
    return persons;
}
