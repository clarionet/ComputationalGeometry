//
// Created by Xiaoqian Mu on 3/31/17.
//

#ifndef PROJECT_POINT_LOCATION_H
#define PROJECT_POINT_LOCATION_H

#include <math.h>
#include <vector>
#include <list>
#include "geo_dcel.hpp"
#include "geo_rbtree.hpp"
#include "point_location_edge.h"
#include "point_location_vertex.h"
#include "geo_dcel_halfedge.hpp"
#include "point_location_rbtree.h"
#include "geo_persistent_rbtree.h"

namespace geo{

class PointLocation{
public:
    std::vector<PointLocationEdge*> edges;
    std::vector<PointLocationVertex*> vertices;

    PLRbTree pl_tree;
    //PLPersistentRbTree pl_persistent_rbtree;
    PerRBTree<PointLocationEdge*, PointLocationVertex*, PlCompare>* persistent_rbtree;


    PointLocation(){}
    PointLocation(DoubleEdgeList* dcel);

    void Create_edgeslist(DoubleEdgeList* dcel);
    void Create_verticeslist(DoubleEdgeList* dcel);

    void Create_PLTree();

    bool Find_point_location(Vector2 &p, geo::Triangle &triangle);

    struct sort_x{
        bool operator()(const DoubleEdgeListVertex* v1,const DoubleEdgeListVertex* v2){
        return v1->point.x<v2->point.x;
    }
    };
};
}
#endif //PROJECT_POINT_LOCATION_H
