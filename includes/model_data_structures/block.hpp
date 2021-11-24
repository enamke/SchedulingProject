
class Block
{
    //Index location
    int i;
    int j;
    int k;

    //Spacial location
    float northing;
    float easting;
    float elevation;

    //Properties of the block
    float value;

    //Getters
    int const get_i() { return this->i; }
    int const get_j() { return this->j; }
    int const get_k() { return this->k; }

    float const get_northing() { return this->northing; }
    float const get_easting() { return this->easting; }
    float const get_elevation() { return this->elevation; }

    float const get_value() { return this->value; }
};