# Introduction

A simple web service to test what I can do on C++ to integrate a relational database and serve an HTTP REST service.

The concept of this application is to investigate the state of the art on coding SQL relational database directly on C++.

This project relies on the Object Relational Mapping supplied by the open source project ODB.

## Download and Build

```
git clone https://github.com/arthurafarias-study/cpp-odb-sqlite-http-json-rest-service
cd cpp-odb-sqlite-http-json-rest-service
mkdir build
cd build
make -j4
```

## Run

```
cpp-odb-sqlite-http-json-rest-service
```

## Todo

- [ ] Analyse performance of the solution compared to another implementations based on other languages and compare the results.
- [ ] Analyse the time to finish a response based on a loopback interface this can serve as a comparison between Node.Js/Express/SQLITE, Node.Js/Restify/SQLITE, PHP/NGINX/SQLITE, PHP/APACHE2/SQLITE...
- [ ] Test the ODB itself and how it can manage relations and queries like one to many...
- [ ] Create a skeleton of project to handle any type of object introspection with authentication using JWT


