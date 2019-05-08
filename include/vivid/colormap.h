#pragma once

//  colormaps from [1], great job guys!

/*
    [1] https://github.com/BIDS/colormap

    mpl-colormaps by Nathaniel Smith & Stefan van der Walt

    To the extent possible under law, the persons who associated CC0 with
    mpl-colormaps have waived all copyright and related or neighboring rights
    to mpl-colormaps.

    You should have received a copy of the CC0 legalcode along with this
    work. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
*/

#include <glm/vec3.hpp>
#include <vector>

namespace tq {


class ColorMap
{
    public:

        enum Interpolation {
            Nearest,
            Linear,
            HSV,
            CIELCh
        };

        ColorMap() = default;

        bool load( const std::string& file );

        bool empty() const { return stops_.empty(); }
        size_t numStops() const { return stops_.size(); }
        glm::vec3 at( const float t );

        Interpolation interpolation = Linear;

    private:

        std::vector<glm::vec3> stops_;
};


}   //  ::tq