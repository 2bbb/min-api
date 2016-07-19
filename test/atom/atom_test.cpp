// Copyright (c) 2016, Cycling '74
// Timothy Place
// Usage of this file and its contents is governed by the MIT License

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "c74_min.h"


TEST_CASE( "Atom Class", "[atoms]" ) {

	
	SECTION("to_atoms() function -- simple values") {
		int					a = 4;
		float				b = 6.28;
		c74::min::symbol	c = "foo";
		c74::max::t_object*	d = (c74::max::t_object*)1974;
		
		c74::min::atoms		aa = c74::min::to_atoms(a);
		c74::min::atoms		bb = c74::min::to_atoms(b);
		c74::min::atoms		cc = c74::min::to_atoms(c);
		c74::min::atoms		dd = c74::min::to_atoms(d);
		
		REQUIRE(( aa.size() == 1 ));
		REQUIRE(( aa[0] == 4 ));
		
		REQUIRE(( bb.size() == 1 ));
		REQUIRE(( bb[0] == Approx(6.28) ));
		
		REQUIRE(( cc.size() == 1 ));
		REQUIRE(( cc[0] == "foo" ));
		
		REQUIRE(( dd.size() == 1 ));
		REQUIRE(( dd[0] == (c74::max::t_object*)1974 ));
	}

	
    SECTION("to_atoms() function -- std::vector<double>") {
		std::vector<double>	dv = { 1, 2.0, -3.14, 4.5};
		c74::min::atoms		as = c74::min::to_atoms(dv);
				
		REQUIRE(( as.size() == 4 ));
		REQUIRE(( as[0] == 1.0 ));
		REQUIRE(( as[1] == 2.0 ));
		REQUIRE(( as[2] == Approx(-3.14) ));
		REQUIRE(( as[3] == 4.5 ));
	}

	SECTION("to_atoms() function -- std::list<double>") {
		std::list<double>	dv = { 1, 2.0, -3.14, 4.5};
		c74::min::atoms		as = c74::min::to_atoms(dv);
		
		REQUIRE(( as.size() == 4 ));
		REQUIRE(( as[0] == 1.0 ));
		REQUIRE(( as[1] == 2.0 ));
		REQUIRE(( as[2] == Approx(-3.14) ));
		REQUIRE(( as[3] == 4.5 ));
	}

	SECTION("to_atoms() function -- std::deque<double>") {
		std::deque<double>	dv = { 1, 2.0, -3.14, 4.5};
		c74::min::atoms		as = c74::min::to_atoms(dv);
		
		REQUIRE(( as.size() == 4 ));
		REQUIRE(( as[0] == 1.0 ));
		REQUIRE(( as[1] == 2.0 ));
		REQUIRE(( as[2] == Approx(-3.14) ));
		REQUIRE(( as[3] == 4.5 ));
	}
	
	SECTION("to_atoms() function -- std::array<double>") {
		std::array<double,4>	dv = {{ 1, 2.0, -3.14, 4.5 }};
		c74::min::atoms			as = c74::min::to_atoms(dv);
		
		REQUIRE(( as.size() == 4 ));
		REQUIRE(( as[0] == 1.0 ));
		REQUIRE(( as[1] == 2.0 ));
		REQUIRE(( as[2] == Approx(-3.14) ));
		REQUIRE(( as[3] == 4.5 ));
	}

	
	
	
    SECTION("from_atoms() function") {
		c74::min::atoms		as = { 1, 2.0, -3.14, 4.5};
		std::vector<double>	dv = c74::min::from_atoms<std::vector<double>>(as);
				
		REQUIRE( dv.size() == 4 );
		REQUIRE( dv[0] == 1.0 );
		REQUIRE( dv[1] == 2.0 );
		REQUIRE( dv[2] == Approx(-3.14) );
		REQUIRE( dv[3] == 4.5 );
	}

}