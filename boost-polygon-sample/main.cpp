#include <iostream>
#include <boost/polygon/polygon.hpp>
#include <list>
#include <vector>

//using namespace std;
using namespace boost::polygon;
using namespace boost::polygon::operators;

using std::cout;
using std::endl;
using std::list;
using std::vector;


int main()
{

    typedef polygon_45_with_holes_data<int> Polygon45WithHole;

    Polygon45WithHole p1;
    list<point_data<int > > vpts;
    vpts.push_back(point_data<int>(0,0));
    vpts.push_back(point_data<int>(100,0));
    vpts.push_back(point_data<int>(100,20));
    vpts.push_back(point_data<int>(20,20));
    vpts.push_back(point_data<int>(20,100));
    vpts.push_back(point_data<int>(0,100));
    p1.set(vpts.begin(),vpts.end());

    Polygon45WithHole p2;
    std::list<point_data<int > > vpts2;
    vpts2.push_back(point_data<int>(10,80));
    vpts2.push_back(point_data<int>(80,80));
    vpts2.push_back(point_data<int>(80,10));
    vpts2.push_back(point_data<int>(90,10));
    vpts2.push_back(point_data<int>(90,90));
    vpts2.push_back(point_data<int>(10,90));
    p2.set(vpts2.begin(),vpts2.end());

    vector<Polygon45WithHole> polygonset3;
    vector<Polygon45WithHole> polygonset1;
    vector<Polygon45WithHole> polygonset2;
    polygonset1.push_back(p1);
    polygonset2.push_back(p2);
    /// start
    assign(polygonset3,polygonset1+polygonset2);
    /// end

    for(vector<Polygon45WithHole>::iterator it=polygonset3.begin(); it!=polygonset3.end(); ++it)
    {
        cout<<"Polygon45 with hole :"<<endl;
        cout<<"outline: "<<endl;
        for(polygon_45_with_holes_data<int>::iterator_type it_pt1=it->begin(); it_pt1!=it->end(); ++it_pt1)
        {
            cout<<it_pt1->x()<<","<<it_pt1->y()<<endl;
        }

        for(polygon_45_with_holes_data<int>::iterator_holes_type it_hole=it->begin_holes(); it_hole!=it->end_holes(); ++it_hole)
        {
            cout<<"hole:"<<endl;
            for(polygon_45_data<int>::iterator_type it_pt=it_hole->begin(); it_pt!=it_hole->end(); ++it_pt)
            {
                cout<<it_pt->x()<<","<<it_pt->y()<<endl;
            }

        }
    }


    return 0;
}
