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

/** \file Cell.h
    \brief This file defines the Cell class, which represents a cell of a
           Digital Elevation Map (DEM).
  */

#ifndef CELL_H
#define CELL_H

#include "statistics/EstimatorBayesImproper.h"
#include "base/Serializable.h"

/** The class Cell represents a cell of a Digital Elevation Map (DEM).
    \brief A cell of Digital Elevation Map (DEM)
  */
class Cell :
  public virtual Serializable {
public:
  /** \name Constructors/destructor
    @{
    */
  /// Default constructor
  inline Cell();
  /// Copy constructor
  inline Cell(const Cell& other);
  /// Assignment operator
  inline Cell& operator = (const Cell& other);
  /// Destructor
  inline virtual ~Cell();
  /** @}
    */

  /** \name Accessors
      @{
    */
  /// Adds a point into the cell
  inline void addPoint(double point);
  /// Returns the improper height estimator
  inline const EstimatorBayesImproper<NormalDistribution<1> >&
    getHeightEstimator() const;
  /** @}
    */

protected:
  /** \name Stream methods
    @{
    */
  /// Reads from standard input
  inline virtual void read(std::istream& stream);
  /// Writes to standard output
  inline virtual void write(std::ostream& stream) const;
  /// Reads from a file
  inline virtual void read(std::ifstream& stream);
  /// Writes to a file
  inline virtual void write(std::ofstream& stream) const;
  /** @}
    */

  /** \name Protected members
    @{
    */
  /// Improper Bayesian estimator for the height values
  EstimatorBayesImproper<NormalDistribution<1> > mHeightEstimator;
  /** @}
    */

};

#include "data-structures/Cell.tpp"

#endif // CELL_H
