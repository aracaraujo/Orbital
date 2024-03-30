//
// Created by Wade Withers on 3/29/24.
//

#include "fragment.h"

void Fragment::display(ogstream *gout) const {
    gout->drawFragment(this->position, this->angle.getRadians());
}
