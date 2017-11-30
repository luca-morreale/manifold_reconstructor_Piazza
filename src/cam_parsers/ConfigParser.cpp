/*
 * ConfigParser.cpp
 *
 *  Created on: 18 May 2016
 *      Author: enrico
 */

#include <manifoldReconstructor/ConfigParser.h>
#include <manifoldReconstructor/Exceptions.hpp>
#include <stdexcept>
#include <rapidjson/reader.h>

ConfigParser::ConfigParser() {
	// TODO Auto-generated constructor stub

}

ConfigParser::~ConfigParser() {
	// TODO Auto-generated destructor stub
}

ManifoldReconstructionConfig ConfigParser::parse(std::string path) {

	rapidjson::Document document;
	std::ifstream fileStream;
	ManifoldReconstructionConfig c;

	fileStream.open(path.c_str());
	std::string str((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());
	document.Parse(str.c_str());

	try {

		if (!document.HasMember("inverseConicEnabled")) throw JsonAccessException("inverseConicEnabled");
		if (!document["inverseConicEnabled"].IsBool()) throw JsonAccessException("inverseConicEnabled");
		c.enableInverseConic = document["inverseConicEnabled"].GetBool();

		if (!document.HasMember("maxDistanceCamFeature")) throw JsonAccessException("maxDistanceCamFeature");
		if (!document["maxDistanceCamFeature"].IsDouble()) throw JsonAccessException("maxDistanceCamFeature");
		c.maxDistanceCameraPoints = document["maxDistanceCamFeature"].GetDouble();

		if (!document.HasMember("freeVoteThreshold")) throw JsonAccessException("freeVoteThreshold");
		if (!document["freeVoteThreshold"].IsDouble()) throw JsonAccessException("freeVoteThreshold");
		c.freeVoteThreshold = document["freeVoteThreshold"].GetDouble();

		if (!document.HasMember("rayRemovalThreshold")) throw JsonAccessException("rayRemovalThreshold");
		if (!document["rayRemovalThreshold"].IsDouble()) throw JsonAccessException("rayRemovalThreshold");
		c.rayRemovalThreshold = document["rayRemovalThreshold"].GetDouble();

		if (!document.HasMember("vertexRemovalThreshold")) throw JsonAccessException("vertexRemovalThreshold");
		if (!document["vertexRemovalThreshold"].IsDouble()) throw JsonAccessException("vertexRemovalThreshold");
		c.unusedVertexRemovalThreshold = document["vertexRemovalThreshold"].GetDouble();

		if (document.HasMember("outlierFilteringThreshold") && document["outlierFilteringThreshold"].IsDouble())
			c.outlierFilteringThreshold = document["outlierFilteringThreshold"].GetDouble();

		if (!document.HasMember("maxPointsPerCamera")) throw JsonAccessException("maxPointsPerCamera");
		if (!document["maxPointsPerCamera"].IsInt()) throw JsonAccessException("maxPointsPerCamera");
		c.maxPointsPerCamera = document["maxPointsPerCamera"].GetInt();

		if (!document.HasMember("minDistancePointPositionUpdate")) throw JsonAccessException("minDistancePointPositionUpdate");
		if (!document["minDistancePointPositionUpdate"].IsDouble()) throw JsonAccessException("minDistancePointPositionUpdate");
		c.minDistancePointPositionUpdate = document["minDistancePointPositionUpdate"].GetDouble();

//		if (!document.HasMember("enableSuboptimalPolicy")) throw JsonAccessException("enableSuboptimalPolicy");
//		if (!document["enableSuboptimalPolicy"].IsBool()) throw JsonAccessException("enableSuboptimalPolicy");
//		c.enableSuboptimalPolicy = document["enableSuboptimalPolicy"].GetBool();

		if (!document.HasMember("enableRayMistrust")) throw JsonAccessException("enableRayMistrust");
		if (!document["enableRayMistrust"].IsBool()) throw JsonAccessException("enableRayMistrust");
		c.enableRayMistrust = document["enableRayMistrust"].GetBool();

//		if (!document.HasMember("suboptimalMethod")) throw JsonAccessException("suboptimalMethod");
//		if (!document["suboptimalMethod"].IsInt()) throw JsonAccessException("suboptimalMethod");
//		c.suboptimalMethod = document["suboptimalMethod"].GetInt();

		if (document.HasMember("maxSteinerVerticesPerTriangle")) {
			if (!document["maxSteinerVerticesPerTriangle"].IsInt()) throw JsonAccessException("maxSteinerVerticesPerTriangle");
			c.maxSteinerVerticesPerTriangle = document["maxSteinerVerticesPerTriangle"].GetInt();
		}
		
		if (!document.HasMember("w_1")) throw JsonAccessException("w_1");
		if (!document["w_1"].IsDouble()) throw JsonAccessException("w_1");
		c.w_1 = document["w_1"].GetDouble();

		if (!document.HasMember("w_2")) throw JsonAccessException("w_2");
		if (!document["w_2"].IsDouble()) throw JsonAccessException("w_2");
		c.w_2 = document["w_2"].GetDouble();

		if (!document.HasMember("w_3")) throw JsonAccessException("w_3");
		if (!document["w_3"].IsDouble()) throw JsonAccessException("w_3");
		c.w_3 = document["w_3"].GetDouble();

		if (!document.HasMember("w_m")) throw JsonAccessException("w_m");
		if (!document["w_m"].IsDouble()) throw JsonAccessException("w_m");
		c.w_m = document["w_m"].GetDouble();

		if (!document.HasMember("steinerGridStepLength")) throw JsonAccessException("");
		if (!document["steinerGridStepLength"].IsDouble()) throw JsonAccessException("");
		c.steinerGridStepLength = document["steinerGridStepLength"].GetDouble();

//		if (!document.HasMember("steinerGridSideLength")) throw JsonAccessException("");
//		if (!document["steinerGridSideLength"].IsDouble()) throw JsonAccessException("");
//		c.steinerGridSideLength = document["steinerGridSideLength"].GetDouble();

		if (!document.HasMember("manifold_update_every")) throw JsonAccessException("manifold_update_every");
		if (!document["manifold_update_every"].IsInt()) throw JsonAccessException("manifold_update_every");
		c.triangulationUpdateEvery = document["manifold_update_every"].GetInt();

		if (!document.HasMember("initial_manifold_update_skip")) throw JsonAccessException("initial_manifold_update_skip");
		if (!document["initial_manifold_update_skip"].IsInt()) throw JsonAccessException("initial_manifold_update_skip");
		c.initialTriangulationUpdateSkip = document["initial_manifold_update_skip"].GetInt();

		if (!document.HasMember("save_manifold_every")) throw JsonAccessException("save_manifold_every");
		if (!document["save_manifold_every"].IsInt()) throw JsonAccessException("save_manifold_every");
		c.saveMeshEvery = document["save_manifold_every"].GetInt();

		if (!document.HasMember("primary_points_visibility_threshold")) throw JsonAccessException("primary_points_visibility_threshold");
		if (!document["primary_points_visibility_threshold"].IsInt()) throw JsonAccessException("primary_points_visibility_threshold");
		c.primaryPointsVisibilityThreshold = document["primary_points_visibility_threshold"].GetInt();

		if (!document.HasMember("all_sort_of_output")) throw JsonAccessException("all_sort_of_output");
		if (!document["all_sort_of_output"].IsBool()) throw JsonAccessException("all_sort_of_output");
		c.debugOutput = document["all_sort_of_output"].GetBool();

		if (!document.HasMember("time_stats_output")) throw JsonAccessException("time_stats_output");
		if (!document["time_stats_output"].IsBool()) throw JsonAccessException("time_stats_output");
		c.timeStatsOutput = document["time_stats_output"].GetBool();

		if (document.HasMember("fake_points_multiplier")) {
			if (!document["fake_points_multiplier"].IsInt()) throw JsonAccessException("fake_points_multiplier");
			c.fakePointsMultiplier = document["fake_points_multiplier"].GetInt();
		} else c.fakePointsMultiplier = 0;

		if (!document.HasMember("update_points_position")) throw JsonAccessException("update_points_position");
		if (!document["update_points_position"].IsBool()) throw JsonAccessException("update_points_position");
		c.enablePointsPositionUpdate = document["update_points_position"].GetBool();

		if (document.HasMember("output_folder"))
			if(document["output_folder"].IsString()) c.outputFolder = document["output_folder"].GetString();
			else throw JsonAccessException("output_folder not String");

		if (document.HasMember("time_stats_folder"))
			if(document["time_stats_folder"].IsString()) c.timeStatsFolder = document["time_stats_folder"].GetString();
			else throw JsonAccessException("time_stats_folder not String");

		if (document.HasMember("statsId"))
			if(document["statsId"].IsString()) c.statsId = document["statsId"].GetString();
			else throw JsonAccessException("statsId not String");

	} catch (JsonAccessException& e) {
		std::cerr << e.what() << std::endl;
		std::cout << e.what() << std::endl;

	}

	return c;
}
