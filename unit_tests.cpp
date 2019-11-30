////
//// Created by Patrick on 2019-11-29.
////
//
//#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() put this in one cpp file
//#include "catch.hpp"
//#include "cities.hpp"
//#include "population.hpp"
//
//using namespace std;
//
//TEST_CASE("Check if the cities class is reading the correct number of cities", "cities")
//{
//    cities k{"cities.txt", CITIES_IN_TOUR};
//    REQUIRE(k.getList().size() == CITIES_IN_TOUR);
//}
//
//TEST_CASE("Check if the cities class is reading 10 cities from the file", "cities")
//{
//    int TEN_CITIES = 10;
//
//    cities k{"cities.txt", TEN_CITIES};
//    REQUIRE(k.getList().size() == TEN_CITIES);
//}
//
//TEST_CASE("Record Beijing as the 10th city from the cities.txt file", "cities")
//{
//    int TEN_CITIES = 10;
//
//    cities k{"cities.txt", TEN_CITIES};
//    REQUIRE(k.getList()[9]->getName() == "Beijing");
//    REQUIRE(k.getList()[9]->getX() == 967);
//    REQUIRE(k.getList()[9]->getY() == 456);
//}
//
//TEST_CASE("Record Seoul as the 32nd city from the cities.txt file", "cities")
//{
//    cities k{"cities.txt", CITIES_IN_TOUR};
//    REQUIRE(k.getList()[31]->getName() == "Seoul");
//    REQUIRE(k.getList()[31]->getX() == 502);
//    REQUIRE(k.getList()[31]->getY() == 355);
//}
//
//TEST_CASE("Record Toronto as the 1st city from the cities.txt file", "cities")
//{
//    cities k{"cities.txt", CITIES_IN_TOUR};
//    REQUIRE(k.getList()[0]->getName() == "Toronto");
//    REQUIRE(k.getList()[0]->getX() == 723);
//    REQUIRE(k.getList()[0]->getY() == 748);
//}
//
//TEST_CASE("Default constructor", "tour")
//{
//    tour t;
//    REQUIRE(t.getTheTotalDistance() == 0);
//}
//
//TEST_CASE("Check if all entries in the tour are from the cities class", "tour")
//{
//    cities k{"cities.txt", CITIES_IN_TOUR};
//    tour t(k);
//    bool final_result = false;
//
//    for (int i = 0; i < CITIES_IN_TOUR; i++) {
//        bool result = false;
//
//        for (int j = 0; j < CITIES_IN_TOUR; j++) {
//            city a = *t.getCity(i);
//            city b = *k.getList()[j];
//
//            if (a == b) {
//                result = true;
//                break;
//            }
//        }
//
//        if (result) {
//            final_result = true;
//        } else {
//            final_result = false;
//            break;
//        }
//    }
//
//    REQUIRE(final_result);
//}
//
//TEST_CASE("Fitness and total distance of a tour are not 0 for multiple cities", "tour")
//{
//    cities k{"cities.txt", CITIES_IN_TOUR};
//    tour t(k);
//
//    REQUIRE(t.getTotalDistance() != 0);
//    REQUIRE(t.getFitness() != 0);
//}
//
//TEST_CASE("Fitness and total distance are 0 for a tour of 0 cities" , "tour")
//{
//    tour t{};
//
//    REQUIRE(t.getTheTotalDistance() == 0);
//    REQUIRE(t.getFitness() == 0);
//}
//
//TEST_CASE("Fitness and total distance are 0 for a tour of 1 city", "tour")
//{
//    tour t{};
//    city a = city{"Mexico City", 200, 600};
//    city* k = &a;
//    t.addCity(k);
//
//    REQUIRE(t.getCity(0)->getName() == "Mexico City");
//    REQUIRE(t.getCity(0)->getX() == 200);
//    REQUIRE(t.getCity(0)->getY() == 600);
//    REQUIRE(t.getTheTotalDistance() == 0);
//    REQUIRE(t.getFitness() == 0);
//}
//
//TEST_CASE("Checks if the fitness ratio is 1 for its initialization", "population")
//{
//    cities k{"cities.txt", CITIES_IN_TOUR};
//    population pop{k, POPULATION_SIZE};
//
//    REQUIRE(pop.getFitnessRatio() == 1);
//}
//
//TEST_CASE("Checks if the base tour is the elite tour for its initialization", "population")
//{
//    cities k{"cities.txt", CITIES_IN_TOUR};
//    population pop{k, POPULATION_SIZE};
//
//    REQUIRE(pop.getBaseTour() == pop.getEliteTour());
//}