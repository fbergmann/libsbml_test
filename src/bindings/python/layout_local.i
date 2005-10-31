/**
 * Filename    : layout_local.i
 * Description : SBML Layout include file for bindings.
 * Organization: European Media Laboratories Research gGmbH
 * Created     : 2005-04-17
 *
 * Copyright 2005 European Media Laboratories Research gGmbH
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2.1 of the License, or
 * any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY, WITHOUT EVEN THE IMPLIED WARRANTY OF
 * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.  The software and
 * documentation provided hereunder is on an "as is" basis, and the
 * European Media Laboratories gGmbH have no obligations to provide maintenance, support,
 * updates, enhancements or modifications.  In no event shall the
 * European Media Laboratory gGmbH be liable to any party for direct, indirect, special,
 * incidental or consequential damages, including lost profits, arising
 * out of the use of this software and its documentation, even if the
 * European Media Laboratories gGmbH have been advised of the possibility of such damage.  See
 * the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
 *
 * The original code contained here was initially developed by:
 *
 *     Ralph Gauges
 *     Bioinformatics Group
 *     European Media Laboratories Research gGmbH
 *     Schloss-Wolfsbrunnenweg 31c
 *     69118 Heidelberg
 *     Germany
 *
 *     http://www.eml-research.de/english/Research/BCB/
 *     mailto:ralph.gauges@eml-r.villa-bosch.de
 *
 * Contributor(s):
 */

/**
 * Convert LineSegment objects into the most specific type possible.
 */
%typemap(out) LineSegment*
{
  $result = SWIG_NewPointerObj($1, GetDowncastSwigType($1), 0);
}

/**
 * Convert GraphicalObject objects into the most specific type possible.
 */
%typemap(out) GraphicalObject*
{
  $result = SWIG_NewPointerObj($1, GetDowncastSwigType($1), 0);
}


%feature("shadow") Layout::addCompartmentGlyph(CompartmentGlyph&)
%{
  def addCompartmentGlyph(*args):
    if args[1] is not None: args[1].thisown = 0
    return _libsbml.Layout_addCompartmentGlyph(*args)
%}

%feature("shadow") Layout::addSpeciesGlyph(SpeciesGlyph&)
%{
  def addSpeciesGlyph(*args):
    if args[1] is not None: args[1].thisown = 0
    return _libsbml.Layout_addSpeciesGlyph(*args)
%}


%feature("shadow") Layout::addReactionGlyph(ReactionGlyph&)
%{
  def addReactionGlyph(*args):
    if args[1] is not None: args[1].thisown = 0
    return _libsbml.Layout_addReactionGlyph(*args)
%}


%feature("shadow") Layout::addTextGlyph(TextGlyph&)
%{
  def addTextGlyph(*args):
    if args[1] is not None: args[1].thisown = 0
    return _libsbml.Layout_addTextGlyph(*args)
%}


%feature("shadow") Layout::addAdditionalGraphicalObject(GraphicalObject&)
%{
  def addAdditionalGraphicalObject(*args):
    if args[1] is not None: args[1].thisown = 0
    return _libsbml.Layout_addAdditionalGraphicalObject(*args)
%}


%feature("shadow") SpeciesReferenceGlyph::setCurve(Curve*)
%{
  def setCurve(*args):
    if args[1] is not None: args[1].thisown = 0
    return _libsbml.Layout_setCurve(*args)
%}


%feature("shadow") ReactionGlyph::addSpeciesReferenceGlyph(SpeciesReferenceGlyph&)
%{
  def addSpeciesReferenceGlyph(*args):
    if args[1] is not None: args[1].thisown = 0
    return _libsbml.ReactionGlyph_addSpeciesReferenceGlyph(*args)
%}


%feature("shadow") ReactionGlyph::setCurve(Curve*)
%{
  def setCurve(*args):
    if args[1] is not None: args[1].thisown = 0
    return _libsbml.ReactionGlyph_setCurve(*args)
%}


%feature("shadow") Curve::addCurveSegment(LineSegment&)
%{
  def addCurveSegment(*args):
    if args[1] is not None: args[1].thisown = 0
    return _libsbml.Curve_addCurveSegment(*args)
%}



