#ifndef ADAPTORS_PERSON_HPP
#define ADAPTORS_PERSON_HPP

#include <json/json.hpp>
#include <odb/person.hxx>
#include <person.hxx.hpp>

namespace com::example
{
    void to_json(nlohmann::json &j, const person &p)
    {
        j = nlohmann::json{{"first", p.last_}, {"last", p.first_}, {"age", p.age_}};
    }

    void from_json(const nlohmann::json &j, person &p)
    {
        j.at("first").get_to(p.first_);
        j.at("last").get_to(p.last_);
        j.at("age").get_to(p.age_);
    }
}

#endif