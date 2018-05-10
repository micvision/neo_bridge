//
// Created by huang on 18-5-3.
//

#ifndef NEO_BRIDGE_TYPE_MAP_HPP
#define NEO_BRIDGE_TYPE_MAP_HPP

#define MAPDATAS_SIZE 512

namespace Neo_Packet{

    typedef struct {
        unsigned int package_sum;// map package total sum.
        unsigned int package_num;// map package num.
    }MAPDATAS_PACKET_REQUEST;

    typedef struct {
        unsigned int package_sum;// map package total sum.
        unsigned int package_num;// map package num.
        float resolution;
        float x;
        float y;
        float z;
        float Quaternion[4];
        unsigned int size;
        unsigned int width;
        unsigned int hight;
        char data[MAPDATAS_SIZE];
    }MAPDATAS_PACKET_RESPONSE;

}


#endif //NEO_BRIDGE_TYPE_MAP_HPP
