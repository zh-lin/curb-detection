/******************************************************************************
 * Copyright (C) 2011 by Jerome Maye                                          *
 * jerome.maye@gmail.com                                                      *
 *                                                                            *
 * This program is free software; you can redistribute it and/or modify       *
 * it under the terms of the Lesser GNU General Public License as published by*
 * the Free Software Foundation; either version 3 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * Lesser GNU General Public License for more details.                        *
 *                                                                            *
 * You should have received a copy of the Lesser GNU General Public License   *
 * along with this program. If not, see <http://www.gnu.org/licenses/>.       *
 ******************************************************************************/

#include "data-structures/Cell.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

Cell::Cell() :
  mHeightHist(-10, 10, 0.01) {
}

Cell::Cell(const Cell& other) :
  mHeightHist(other.mHeightHist) {
}

Cell& Cell::operator = (const Cell& other) {
  if (this != &other) {
    mHeightHist = other.mHeightHist;
  }
  return *this;
}

Cell::~Cell() {
}

/******************************************************************************/
/* Stream operations                                                          */
/******************************************************************************/

void Cell::read(std::istream& stream) {
}

void Cell::write(std::ostream& stream) const {
  stream << "height histogram: " << std::endl << mHeightHist;
}

void Cell::read(std::ifstream& stream) {
}

void Cell::write(std::ofstream& stream) const {
}

/******************************************************************************/
/* Accessors                                                                  */
/******************************************************************************/

void Cell::addPoint(double point) {
  mHeightHist.addSample(point);
}

const Histogram<double, 1>& Cell::getHeightHist() const {
  return mHeightHist;
}