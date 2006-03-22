/**
 * \file    example2.cpp
 * \brief   SBML Layout example
 * \author  Ralph Gauges
 *
 * $Id$
 * $Source$
 */
/* Copyright 2004 European Media Laboratories Research gGmbH
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
 * European Media Laboratories Research gGmbH have no obligations to
 * provide maintenance, support, updates, enhancements or modifications.
 * In no event shall the European Media Laboratories Research gGmbH be
 * liable to any party for direct, indirect, special, incidental or
 * consequential damages, including lost profits, arising out of the use of
 * this software and its documentation, even if the European Media
 * Laboratories Research gGmbH have been advised of the possibility of such
 * damage.  See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
 *
 * The original code contained here was initially developed by:
 *
 *     Ralph Gaugess
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


#include "common/common.h"

#include "sbml/SBMLDocument.h"
#include "sbml/Model.h"
#include "sbml/Compartment.h"
#include "sbml/Species.h"
#include "sbml/SpeciesReference.h"
#include "sbml/Reaction.h"
#include "sbml/layout/Layout.h"
#include "sbml/layout/CompartmentGlyph.h"
#include "sbml/layout/SpeciesGlyph.h"
#include "sbml/layout/ReactionGlyph.h"
#include "sbml/layout/SpeciesReferenceGlyph.h"
#include "sbml/layout/Curve.h"
#include "sbml/layout/Dimensions.h"
#include "sbml/layout/BoundingBox.h"
#include "sbml/layout/Point.h"
#include "sbml/layout/LineSegment.h"
#include "sbml/layout/CubicBezier.h"
#include "sbml/SBMLWriter.h"



Species* createSpecies(const char* id, const char* name, const char* compartmentId,Model* model){
	Species* species=&model->createSpecies();
	species->setId(id);
	species->setName(name);
	species->setCompartment(compartmentId);
	return species;
}

SpeciesReference* createSpeciesReference(const Species* species,const char* id){
	SpeciesReference* speciesReference=new SpeciesReference();
	speciesReference->setId(id);
	speciesReference->setSpecies(species->getId());
	return speciesReference;
}

int main(int argc,char** argv){

// create the document

SBMLDocument *document=new SBMLDocument();
// create the Model

Model* model=new Model();
model->setId("Glycolysis");
document->setModel(model);
document->setLevel(2);
document->setVersion(1);


// create the Compartment

Compartment* compartment=&model->createCompartment();
compartment->setId("Yeast");

// create the Species

Species* species_Gluc=createSpecies("Glucose","Glucose",compartment->getId().c_str(),model);
Species* species_G6P=createSpecies("Glucose-6-phosphate","Glucose-6-phosphate",compartment->getId().c_str(),model);
Species* species_F6P=createSpecies("Fructose-6-phosphate","Fructose-6-phosphate",compartment->getId().c_str(),model);
Species* species_F16BP=createSpecies("Fructose-1_6-bisphosphate","Fructose-1,6-bisphosphate",compartment->getId().c_str(),model);
Species* species_DHAP=createSpecies("Dihydroxyacetonephosphate","Dihydroxyacetonephosphate",compartment->getId().c_str(),model);
Species* species_GAP=createSpecies("Glyceraldehyd-3-phosphate","Glyceraldehyd-3-phosphate",compartment->getId().c_str(),model);
Species* species_BPG=createSpecies("1_3-Bisphosphoglycerate","1,3-Bisphosphoglycerate",compartment->getId().c_str(),model);
Species* species_3PG=createSpecies("3-Phosphoglycerate","3-Phosphoglycerate",compartment->getId().c_str(),model);
Species* species_2PG=createSpecies("2-Phosphoglycerate","2-Phosphoglycerate",compartment->getId().c_str(),model);
Species* species_PEP=createSpecies("Phosphoenolpyruvate","Phosphoenolpyruvate",compartment->getId().c_str(),model);
Species* species_Pyr=createSpecies("Pyruvate","Pyruvate",compartment->getId().c_str(),model);
Species* species_ATP=createSpecies("ATP","ATP",compartment->getId().c_str(),model);
Species* species_ADP=createSpecies("ADP","ADP",compartment->getId().c_str(),model);
Species* species_H=createSpecies("H+","H+",compartment->getId().c_str(),model);
Species* species_NAD=createSpecies("NAD+","NAD+",compartment->getId().c_str(),model);
Species* species_NADH=createSpecies("NADH","NADH",compartment->getId().c_str(),model);
Species* species_H2O=createSpecies("H2O","H2O",compartment->getId().c_str(),model);
Species* species_PI=createSpecies("Pi","Pi",compartment->getId().c_str(),model);

// create the Reactions
///////////////////////////////////////////////////////////////////////////////

// Hexokinase Reaction
Reaction* reaction_Hexokinase=&model->createReaction();
reaction_Hexokinase->setId("Hexokinase");
reaction_Hexokinase->setReversible(false);

SpeciesReference* reference_Gluc=createSpeciesReference(species_Gluc,"ref_Gluc");
SpeciesReference* reference_G6P_1=createSpeciesReference(species_G6P,"ref_G6P_1");
SpeciesReference* reference_ATP_1=createSpeciesReference(species_ATP,"ref_ATP_1");
SpeciesReference* reference_ADP_1=createSpeciesReference(species_ADP,"ref_ADP_1");
SpeciesReference* reference_H_1=createSpeciesReference(species_H,"ref_H_1");

reaction_Hexokinase->addReactant(*reference_Gluc);
reaction_Hexokinase->addReactant(*reference_ATP_1);
reaction_Hexokinase->addProduct(*reference_G6P_1);
reaction_Hexokinase->addProduct(*reference_ADP_1);
reaction_Hexokinase->addProduct(*reference_H_1);

// Phosphoglucoseisomerase Reaction

Reaction* reaction_PGIsomerase=&model->createReaction();
reaction_PGIsomerase->setId("Phosphoglucoseisomerase");

SpeciesReference* reference_G6P_2=createSpeciesReference(species_G6P,"ref_G6P_2");

SpeciesReference* reference_F6P_1=createSpeciesReference(species_F6P,"ref_F6P_1");

reaction_PGIsomerase->addReactant(*reference_G6P_2);
reaction_PGIsomerase->addProduct(*reference_F6P_1);

// Phosphofructokinase Reaction

Reaction* reaction_PFK=&model->createReaction();
reaction_PFK->setId("Phosphofructokinase");
reaction_PFK->setReversible(false);

SpeciesReference* reference_F6P_2=createSpeciesReference(species_F6P,"ref_F6P_2");
SpeciesReference* reference_F16BP_1=createSpeciesReference(species_F16BP,"ref_F16BP_1");
SpeciesReference* reference_ATP_2=createSpeciesReference(species_ATP,"ref_ATP_2");
SpeciesReference* reference_ADP_2=createSpeciesReference(species_ADP,"ref_ADP_2");
SpeciesReference* reference_H_2=createSpeciesReference(species_H,"ref_H_2");


reaction_PFK->addReactant(*reference_F6P_2);
reaction_PFK->addReactant(*reference_ATP_2);
reaction_PFK->addProduct(*reference_F16BP_1);
reaction_PFK->addProduct(*reference_ADP_2);
reaction_PFK->addProduct(*reference_H_2);

// Aldolase Reaction

Reaction* reaction_Aldolase=&model->createReaction();
reaction_Aldolase->setId("Aldolase");

SpeciesReference* reference_F16BP_2=createSpeciesReference(species_F16BP,"ref_F16BP_2");
SpeciesReference* reference_DHAP_1=createSpeciesReference(species_DHAP,"ref_DHAP_1");
SpeciesReference* reference_GAP_1=createSpeciesReference(species_GAP,"ref_GAP_1");

reaction_Aldolase->addReactant(*reference_F16BP_2);
reaction_Aldolase->addProduct(*reference_DHAP_1);
reaction_Aldolase->addProduct(*reference_GAP_1);

// Triose phosphate isomerase Reaction

Reaction* reaction_TPI=&model->createReaction();
reaction_TPI->setId("triose_phosphate_isomerase");

SpeciesReference* reference_DHAP_2=createSpeciesReference(species_DHAP,"ref_DHAP_2");
SpeciesReference* reference_GAP_2=createSpeciesReference(species_GAP,"ref_GAP_2");

reaction_TPI->addReactant(*reference_DHAP_2);
reaction_TPI->addProduct(*reference_GAP_2);

// Glyceraldehyde-3-phosphatedehydrogenase Reaction

Reaction* reaction_GAPDeh=&model->createReaction();
reaction_GAPDeh->setId("GAP_Dehydrogenase");
reaction_GAPDeh->setReversible(false);
        
SpeciesReference* reference_GAP_3=createSpeciesReference(species_GAP,"ref_GAP_3");
SpeciesReference* reference_BPG_1=createSpeciesReference(species_BPG,"ref_BPG_1");
SpeciesReference* reference_NAD_1=createSpeciesReference(species_NAD,"ref_NAD_1");
SpeciesReference* reference_NADH_1=createSpeciesReference(species_NADH,"ref_NADH_1");
SpeciesReference* reference_H_5=createSpeciesReference(species_H,"ref_H_5");
SpeciesReference* reference_PI_1=createSpeciesReference(species_PI,"ref_PI_1");

reaction_GAPDeh->addReactant(*reference_GAP_3);
reaction_GAPDeh->addReactant(*reference_NAD_1);
reaction_GAPDeh->addReactant(*reference_PI_1);
reaction_GAPDeh->addProduct(*reference_BPG_1);
reaction_GAPDeh->addProduct(*reference_NADH_1);
reaction_GAPDeh->addProduct(*reference_H_5);

// Phosphoglyceratekinase Reaction

Reaction* reaction_PGK=&model->createReaction();
reaction_PGK->setId("Phosphoglyceratekinase");
reaction_PGK->setReversible(false);

SpeciesReference* reference_BPG_2=createSpeciesReference(species_BPG,"ref_BPG_2");
SpeciesReference* reference_3PG_1=createSpeciesReference(species_3PG,"ref_3PG_1");
SpeciesReference* reference_ATP_3=createSpeciesReference(species_ATP,"ref_ATP_3");
SpeciesReference* reference_ADP_3=createSpeciesReference(species_ADP,"ref_ADP_3");
SpeciesReference* reference_H_3=createSpeciesReference(species_H,"ref_H_3");

reaction_PGK->addReactant(*reference_BPG_2);
reaction_PGK->addReactant(*reference_ADP_3);
reaction_PGK->addReactant(*reference_H_3);
reaction_PGK->addProduct(*reference_3PG_1);
reaction_PGK->addProduct(*reference_ATP_3);

// Phosphoglyceratemutase Reaction

Reaction* reaction_PGM=&model->createReaction();
reaction_PGM->setId("Phosphoglyceratemutase");

SpeciesReference* reference_3PG_2=createSpeciesReference(species_3PG,"ref_3PG_2");
SpeciesReference* reference_2PG_1=createSpeciesReference(species_2PG,"ref_2PG_1");

reaction_PGM->addReactant(*reference_3PG_2);
reaction_PGM->addProduct(*reference_2PG_1);

// Enolase Reaction

Reaction* reaction_Enolase=&model->createReaction();
reaction_Enolase->setId("Enolase");

SpeciesReference* reference_2PG_2=createSpeciesReference(species_3PG,"ref_2PG_2");
SpeciesReference* reference_PEP_1=createSpeciesReference(species_2PG,"ref_PEP_1");
SpeciesReference* reference_H2O_1=createSpeciesReference(species_H2O,"ref_H2O_1");

reaction_Enolase->addReactant(*reference_2PG_2);
reaction_Enolase->addProduct(*reference_PEP_1);
reaction_Enolase->addProduct(*reference_H2O_1);

// Pyruvatekinase Reaction

Reaction* reaction_PK=&model->createReaction();
reaction_PK->setId("Pyruvatekinase");
reaction_PK->setReversible(false);


SpeciesReference* reference_PEP_2=createSpeciesReference(species_3PG,"ref_PEP_2");
SpeciesReference* reference_Pyr_1=createSpeciesReference(species_2PG,"ref_Pyr_1");
SpeciesReference* reference_ATP_4=createSpeciesReference(species_ATP,"ref_ATP_4");
SpeciesReference* reference_ADP_4=createSpeciesReference(species_ADP,"ref_ADP_4");
SpeciesReference* reference_H_4=createSpeciesReference(species_H,"ref_H_4");

reaction_PK->addReactant(*reference_PEP_2);
reaction_PK->addReactant(*reference_ADP_4);
reaction_PK->addReactant(*reference_H_4);
reaction_PK->addProduct(*reference_Pyr_1);
reaction_PK->addProduct(*reference_ATP_4);


// create the Layout
////////////////////////////////////////////////////////////////////////////////////////

Layout* layout=&model->createLayout();

layout->setId("Glycolysis_Layout");
layout->setDimensions(Dimensions(800.0,1600.0));


// create the CompartmentGlyph

//CompartmentGlyph* compartmentGlyph=layout->createCompartmentGlyph();
//compartmentGlyph->setId("CompartmentGlyph_1");
//compartmentGlyph->setCompartmentId(compartment->getId());
//compartmentGlyph->setBoundingBox(BoundingBox("bb_00",5,5,20,20));

// create the SpeciesGlyphs

SpeciesGlyph* glyph_Gluc=layout->createSpeciesGlyph();
glyph_Gluc->setId("glyph_Gluc");
glyph_Gluc->setSpeciesId(species_Gluc->getId());
glyph_Gluc->setBoundingBox(BoundingBox("bb_01",105,20,130,20));

TextGlyph* tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_01");
tGlyph->setBoundingBox(BoundingBox("bbT_01",115,20,110,20));
tGlyph->setOriginOfTextId(species_Gluc->getId());
tGlyph->setGraphicalObjectId(glyph_Gluc->getId());

SpeciesGlyph* glyph_ATP_1=layout->createSpeciesGlyph();
glyph_ATP_1->setId("glyph_ATP_1");
glyph_ATP_1->setSpeciesId(species_ATP->getId());
glyph_ATP_1->setBoundingBox(BoundingBox("bb_02",270,70,80,20));

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_02");
tGlyph->setBoundingBox(BoundingBox("bbT_02",280,70,60,20));
tGlyph->setOriginOfTextId(species_ATP->getId());
tGlyph->setGraphicalObjectId(glyph_ATP_1->getId());



SpeciesGlyph* glyph_ADP_1=layout->createSpeciesGlyph();
glyph_ADP_1->setId("glyph_ADP_1");
glyph_ADP_1->setSpeciesId(species_ADP->getId());
glyph_ADP_1->setBoundingBox(BoundingBox("bb_03",270,140,80,20));

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_03");
tGlyph->setBoundingBox(BoundingBox("bbT_03",280,140,60,20));
tGlyph->setOriginOfTextId(species_ADP->getId());
tGlyph->setGraphicalObjectId(glyph_ADP_1->getId());


tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph+_01");
tGlyph->setBoundingBox(BoundingBox("bb+_01",350,140,20,20));
tGlyph->setText("+");



SpeciesGlyph* glyph_H_1=layout->createSpeciesGlyph();
glyph_H_1->setId("glyph_H_1");
glyph_H_1->setSpeciesId(species_H->getId());
glyph_H_1->setBoundingBox(BoundingBox("bb_04",380,140,60,20));

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_04");
tGlyph->setBoundingBox(BoundingBox("bbT_04",390,140,40,20));
tGlyph->setOriginOfTextId(species_H->getId());
tGlyph->setGraphicalObjectId(glyph_H_1->getId());



SpeciesGlyph* glyph_G6P=layout->createSpeciesGlyph();
glyph_G6P->setId("glyph_G6P");
glyph_G6P->setSpeciesId(species_G6P->getId());
glyph_G6P->setBoundingBox(BoundingBox("bb_05",50,190,270,20));

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_05");
tGlyph->setBoundingBox(BoundingBox("bbT_05",60,190,250,20));
tGlyph->setOriginOfTextId(species_G6P->getId());
tGlyph->setGraphicalObjectId(glyph_G6P->getId());



SpeciesGlyph* glyph_F6P=layout->createSpeciesGlyph();
glyph_F6P->setId("glyph_F6P");
glyph_F6P->setSpeciesId(species_F6P->getId());
glyph_F6P->setBoundingBox(BoundingBox("bb_06",50,360,270,20));

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_06");
tGlyph->setBoundingBox(BoundingBox("bbT_06",60,360,250,20));
tGlyph->setOriginOfTextId(species_F6P->getId());
tGlyph->setGraphicalObjectId(glyph_F6P->getId());



SpeciesGlyph* glyph_ATP_2=layout->createSpeciesGlyph();
glyph_ATP_2->setId("glyph_ATP_2");
glyph_ATP_2->setSpeciesId(species_ATP->getId());
glyph_ATP_2->setBoundingBox(BoundingBox("bb_07",270,410,80,20));

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_07");
tGlyph->setBoundingBox(BoundingBox("bbT_07",280,410,60,20));
tGlyph->setOriginOfTextId(species_ATP->getId());
tGlyph->setGraphicalObjectId(glyph_ATP_2->getId());



SpeciesGlyph* glyph_ADP_2=layout->createSpeciesGlyph();
glyph_ADP_2->setId("glyph_ADP_2");
glyph_ADP_2->setSpeciesId(species_ADP->getId());
glyph_ADP_2->setBoundingBox(BoundingBox("bb_08",270,480,80,20));

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_08");
tGlyph->setBoundingBox(BoundingBox("bbT_08",280,480,60,20));
tGlyph->setOriginOfTextId(species_ADP->getId());
tGlyph->setGraphicalObjectId(glyph_ADP_2->getId());

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph+_02");
tGlyph->setBoundingBox(BoundingBox("bb+_02",350,480,20,20));
tGlyph->setText("+");



SpeciesGlyph* glyph_H_2=layout->createSpeciesGlyph();
glyph_H_2->setId("glyph_H_2");
glyph_H_2->setSpeciesId(species_H->getId());
glyph_H_2->setBoundingBox(BoundingBox("bb_09",380,480,60,20));

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_09");
tGlyph->setBoundingBox(BoundingBox("bbT_09",390,480,40,20));
tGlyph->setOriginOfTextId(species_H->getId());
tGlyph->setGraphicalObjectId(glyph_H_2->getId());



SpeciesGlyph* glyph_F16BP=layout->createSpeciesGlyph();
glyph_F16BP->setId("glyph_F16BP");
glyph_F16BP->setSpeciesId(species_F16BP->getId());
glyph_F16BP->setBoundingBox(BoundingBox("bb_10",20,530,340,20));

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_10");
tGlyph->setBoundingBox(BoundingBox("bbT_10",30,530,320,20));
tGlyph->setOriginOfTextId(species_F16BP->getId());
tGlyph->setGraphicalObjectId(glyph_F16BP->getId());



SpeciesGlyph* glyph_DHAP=layout->createSpeciesGlyph();
glyph_DHAP->setId("glyph_DHAP");
glyph_DHAP->setSpeciesId(species_DHAP->getId());
glyph_DHAP->setBoundingBox(BoundingBox("bb_11",380,595,340,20));

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_11");
tGlyph->setBoundingBox(BoundingBox("bbT_11",390,595,320,20));
tGlyph->setOriginOfTextId(species_DHAP->getId());
tGlyph->setGraphicalObjectId(glyph_DHAP->getId());



SpeciesGlyph* glyph_GAP=layout->createSpeciesGlyph();
glyph_GAP->setId("glyph_GAP");
glyph_GAP->setSpeciesId(species_GAP->getId());
glyph_GAP->setBoundingBox(BoundingBox("bb_12",20,700,340,20));

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_12");
tGlyph->setBoundingBox(BoundingBox("bbT_12",30,700,320,20));
tGlyph->setOriginOfTextId(species_GAP->getId());
tGlyph->setGraphicalObjectId(glyph_GAP->getId());


SpeciesGlyph* glyph_NAD_1=layout->createSpeciesGlyph();
glyph_NAD_1->setId("glyph_NAD_1");
glyph_NAD_1->setSpeciesId(species_NAD->getId());
glyph_NAD_1->setBoundingBox(BoundingBox("bb_13",270,750,80,20));

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_13");
tGlyph->setBoundingBox(BoundingBox("bbT_13",280,750,60,20));
tGlyph->setOriginOfTextId(species_NAD->getId());
tGlyph->setGraphicalObjectId(glyph_NAD_1->getId());

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph+_06");
tGlyph->setBoundingBox(BoundingBox("bb+_06",350,750,20,20));
tGlyph->setText("+");


SpeciesGlyph* glyph_PI_1=layout->createSpeciesGlyph();
glyph_PI_1->setId("glyph_PI_1");
glyph_PI_1->setSpeciesId(species_PI->getId());
glyph_PI_1->setBoundingBox(BoundingBox("bb_14",380,750,60,20));

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_14");
tGlyph->setBoundingBox(BoundingBox("bbT_14",390,750,40,20));
tGlyph->setOriginOfTextId(species_PI->getId());
tGlyph->setGraphicalObjectId(glyph_PI_1->getId());


SpeciesGlyph* glyph_NADH_1=layout->createSpeciesGlyph();
glyph_NADH_1->setId("glyph_NADH_1");
glyph_NADH_1->setSpeciesId(species_NADH->getId());
glyph_NADH_1->setBoundingBox(BoundingBox("bb_15",270,820,100,20));

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_15");
tGlyph->setBoundingBox(BoundingBox("bbT_15",280,820,80,20));
tGlyph->setOriginOfTextId(species_NADH->getId());
tGlyph->setGraphicalObjectId(glyph_NADH_1->getId());


tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph+_06");
tGlyph->setBoundingBox(BoundingBox("bb+_06",365,820,20,20));
tGlyph->setText("+");


SpeciesGlyph* glyph_H_5=layout->createSpeciesGlyph();
glyph_H_5->setId("glyph_H_5");
glyph_H_5->setSpeciesId(species_H->getId());
glyph_H_5->setBoundingBox(BoundingBox("bb_16",390,820,60,20));

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_16");
tGlyph->setBoundingBox(BoundingBox("bbT_16",400,820,40,20));
tGlyph->setOriginOfTextId(species_H->getId());
tGlyph->setGraphicalObjectId(glyph_H_5->getId());


SpeciesGlyph* glyph_BPG=layout->createSpeciesGlyph();
glyph_BPG->setId("glyph_BPG");
glyph_BPG->setSpeciesId(species_BPG->getId());
glyph_BPG->setBoundingBox(BoundingBox("bb_17",30,870,310,20));

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_17");
tGlyph->setBoundingBox(BoundingBox("bbT_17",40,870,290,20));
tGlyph->setOriginOfTextId(species_BPG->getId());
tGlyph->setGraphicalObjectId(glyph_BPG->getId());



SpeciesGlyph* glyph_ADP_3=layout->createSpeciesGlyph();
glyph_ADP_3->setId("glyph_ADP_3");
glyph_ADP_3->setSpeciesId(species_ADP->getId());
glyph_ADP_3->setBoundingBox(BoundingBox("bb_18",270,920,80,20));

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_18");
tGlyph->setBoundingBox(BoundingBox("bbT_18",280,920,60,20));
tGlyph->setOriginOfTextId(species_ADP->getId());
tGlyph->setGraphicalObjectId(glyph_ADP_3->getId());

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph+_03");
tGlyph->setBoundingBox(BoundingBox("bb+_03",350,920,20,20));
tGlyph->setText("+");


SpeciesGlyph* glyph_H_3=layout->createSpeciesGlyph();
glyph_H_3->setId("glyph_H_3");
glyph_H_3->setSpeciesId(species_H->getId());
glyph_H_3->setBoundingBox(BoundingBox("bb_19",380,920,60,20));

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_19");
tGlyph->setBoundingBox(BoundingBox("bbT_19",390,920,40,20));
tGlyph->setOriginOfTextId(species_H->getId());
tGlyph->setGraphicalObjectId(glyph_H_3->getId());


SpeciesGlyph* glyph_ATP_3=layout->createSpeciesGlyph();
glyph_ATP_3->setId("glyph_ATP_3");
glyph_ATP_3->setSpeciesId(species_ATP->getId());
glyph_ATP_3->setBoundingBox(BoundingBox("bb_20",270,990,80,20));

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_20");
tGlyph->setBoundingBox(BoundingBox("bbT_20",280,990,60,20));
tGlyph->setOriginOfTextId(species_ATP->getId());
tGlyph->setGraphicalObjectId(glyph_ATP_3->getId());


SpeciesGlyph* glyph_3PG=layout->createSpeciesGlyph();
glyph_3PG->setId("glyph_3PG");
glyph_3PG->setSpeciesId(species_3PG->getId());
glyph_3PG->setBoundingBox(BoundingBox("bb_21",50,1040,250,20));

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_21");
tGlyph->setBoundingBox(BoundingBox("bbT_21",60,1040,230,20));
tGlyph->setOriginOfTextId(species_3PG->getId());
tGlyph->setGraphicalObjectId(glyph_3PG->getId());



SpeciesGlyph* glyph_2PG=layout->createSpeciesGlyph();
glyph_2PG->setId("glyph_2PG");
glyph_2PG->setSpeciesId(species_2PG->getId());
glyph_2PG->setBoundingBox(BoundingBox("bb_22",50,1210,250,20));

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_22");
tGlyph->setBoundingBox(BoundingBox("bbT_22",60,1210,230,20));
tGlyph->setOriginOfTextId(species_2PG->getId());
tGlyph->setGraphicalObjectId(glyph_2PG->getId());



SpeciesGlyph* glyph_H2O_1=layout->createSpeciesGlyph();
glyph_H2O_1->setId("glyph_H2O_1");
glyph_H2O_1->setSpeciesId(species_H2O->getId());
glyph_H2O_1->setBoundingBox(BoundingBox("bb_23",270,1350,80,20));

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_23");
tGlyph->setBoundingBox(BoundingBox("bbT_23",280,1350,60,20));
tGlyph->setOriginOfTextId(species_H2O->getId());
tGlyph->setGraphicalObjectId(glyph_H2O_1->getId());


SpeciesGlyph* glyph_PEP=layout->createSpeciesGlyph();
glyph_PEP->setId("glyph_PEP");
glyph_PEP->setSpeciesId(species_PEP->getId());
glyph_PEP->setBoundingBox(BoundingBox("bb_24",40,1380,265,20));

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_24");
tGlyph->setBoundingBox(BoundingBox("bbT_24",50,1380,245,20));
tGlyph->setOriginOfTextId(species_PEP->getId());
tGlyph->setGraphicalObjectId(glyph_PEP->getId());



SpeciesGlyph* glyph_ADP_4=layout->createSpeciesGlyph();
glyph_ADP_4->setId("glyph_ADP_4");
glyph_ADP_4->setSpeciesId(species_ADP->getId());
glyph_ADP_4->setBoundingBox(BoundingBox("bb_25",270,1430,80,20));

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_25");
tGlyph->setBoundingBox(BoundingBox("bbT_25",280,1430,60,20));
tGlyph->setOriginOfTextId(species_ADP->getId());
tGlyph->setGraphicalObjectId(glyph_ADP_4->getId());

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph+_04");
tGlyph->setBoundingBox(BoundingBox("bb+_04",345,1430,20,20));
tGlyph->setText("+");


SpeciesGlyph* glyph_H_4=layout->createSpeciesGlyph();
glyph_H_4->setId("glyph_H_4");
glyph_H_4->setSpeciesId(species_H->getId());
glyph_H_4->setBoundingBox(BoundingBox("bb_26",370,1430,60,20));

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_26");
tGlyph->setBoundingBox(BoundingBox("bbT_26",380,1430,40,20));
tGlyph->setOriginOfTextId(species_H->getId());
tGlyph->setGraphicalObjectId(glyph_H_4->getId());


SpeciesGlyph* glyph_ATP_4=layout->createSpeciesGlyph();
glyph_ATP_4->setId("glyph_ATP_4");
glyph_ATP_4->setSpeciesId(species_ATP->getId());
glyph_ATP_4->setBoundingBox(BoundingBox("bb_27",270,1520,80,20));

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_27");
tGlyph->setBoundingBox(BoundingBox("bbT_27",280,1520,60,20));
tGlyph->setOriginOfTextId(species_ATP->getId());
tGlyph->setGraphicalObjectId(glyph_ATP_4->getId());


SpeciesGlyph* glyph_Pyr=layout->createSpeciesGlyph();
glyph_Pyr->setId("glyph_Pyr");
glyph_Pyr->setSpeciesId(species_Pyr->getId());
glyph_Pyr->setBoundingBox(BoundingBox("bb_28",100,1550,140,20));

tGlyph=layout->createTextGlyph();
tGlyph->setId("TextGlyph_28");
tGlyph->setBoundingBox(BoundingBox("bbT_28",110,1550,120,20));
tGlyph->setOriginOfTextId(species_Pyr->getId());
tGlyph->setGraphicalObjectId(glyph_Pyr->getId());


// create the ReactionGlyphs

ReactionGlyph* glyph_Hexokinase=layout->createReactionGlyph();
glyph_Hexokinase->setId("glyph_Hexokinase");
glyph_Hexokinase->setReactionId(reaction_Hexokinase->getId());

Curve* curve_Hexokinase=glyph_Hexokinase->getCurve();
LineSegment* ls=&curve_Hexokinase->createLineSegment();
ls->setStart(Point(170,100));
ls->setEnd(Point(170,130));

ReactionGlyph* glyph_PGIsomerase=layout->createReactionGlyph();
glyph_PGIsomerase->setId("glyph_PGIsomerase");
glyph_PGIsomerase->setReactionId(reaction_PGIsomerase->getId());

Curve* curve_PGIsomerase=glyph_PGIsomerase->getCurve();
ls=&curve_PGIsomerase->createLineSegment();
ls->setStart(Point(170,270));
ls->setEnd(Point(170,300));


ReactionGlyph* glyph_PFK=layout->createReactionGlyph();
glyph_PFK->setId("glyph_PFK");
glyph_PFK->setReactionId(reaction_PFK->getId());

Curve* curve_PFK=glyph_PFK->getCurve();
ls=&curve_PFK->createLineSegment();
ls->setStart(Point(170,440));
ls->setEnd(Point(170,470));


ReactionGlyph* glyph_Aldolase=layout->createReactionGlyph();
glyph_Aldolase->setId("glyph_Aldolase");
glyph_Aldolase->setReactionId(reaction_Aldolase->getId());

Curve* curve_Aldolase=glyph_Aldolase->getCurve();
ls=&curve_Aldolase->createLineSegment();
ls->setStart(Point(170,610));
ls->setEnd(Point(170,640));

ReactionGlyph* glyph_TPI=layout->createReactionGlyph();
glyph_TPI->setId("glyph_TPI");
glyph_TPI->setReactionId(reaction_TPI->getId());


Curve* curve_TPI=glyph_TPI->getCurve();
ls=&curve_TPI->createLineSegment();
ls->setStart(Point(515,700));
ls->setEnd(Point(515,700));


ReactionGlyph* glyph_GAPDeh=layout->createReactionGlyph();
glyph_GAPDeh->setId("glyph_GAPDeh");
glyph_GAPDeh->setReactionId(reaction_GAPDeh->getId());

Curve* curve_GAPDeh=glyph_GAPDeh->getCurve();
ls=&curve_GAPDeh->createLineSegment();
ls->setStart(Point(170,780));
ls->setEnd(Point(170,810));


ReactionGlyph* glyph_PGK=layout->createReactionGlyph();
glyph_PGK->setId("glyph_PGK");
glyph_PGK->setReactionId(reaction_PGK->getId());

Curve* curve_PGK=glyph_PGK->getCurve();
ls=&curve_PGK->createLineSegment();
ls->setStart(Point(170,950));
ls->setEnd(Point(170,980));


ReactionGlyph* glyph_PGM=layout->createReactionGlyph();
glyph_PGM->setId("glyph_PGM");
glyph_PGM->setReactionId(reaction_PGM->getId());

Curve* curve_PGM=glyph_PGM->getCurve();
ls=&curve_PGM->createLineSegment();
ls->setStart(Point(170,1120));
ls->setEnd(Point(170,1150));


ReactionGlyph* glyph_Enolase=layout->createReactionGlyph();
glyph_Enolase->setId("glyph_Enolase");
glyph_Enolase->setReactionId(reaction_Enolase->getId());

Curve* curve_Enolase=glyph_Enolase->getCurve();
ls=&curve_Enolase->createLineSegment();
ls->setStart(Point(170,1290));
ls->setEnd(Point(170,1320));


ReactionGlyph* glyph_PK=layout->createReactionGlyph();
glyph_PK->setId("glyph_PK");
glyph_PK->setReactionId(reaction_PK->getId());

Curve* curve_PK=glyph_PK->getCurve();
ls=&curve_PK->createLineSegment();
ls->setStart(Point(170,1460));
ls->setEnd(Point(170,1490));


// add the SpeciesReferenceGlyphs


// the main substrates
SpeciesReferenceGlyph* speciesReferenceGlyph1=&glyph_Hexokinase->createSpeciesReferenceGlyph();
speciesReferenceGlyph1->setId("SpeciesReferenceGlyph_01");
speciesReferenceGlyph1->setSpeciesGlyphId(glyph_Gluc->getId());
speciesReferenceGlyph1->setSpeciesReferenceId(reference_Gluc->getId());
speciesReferenceGlyph1->setRole(SPECIES_ROLE_SUBSTRATE);

ls=&speciesReferenceGlyph1->createLineSegment();
ls->setStart(Point(170,100));
ls->setEnd(Point(170,50));

SpeciesReferenceGlyph* speciesReferenceGlyph=&glyph_PGIsomerase->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_02");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_G6P->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_G6P_2->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_SUBSTRATE);

ls=&speciesReferenceGlyph->createLineSegment();
ls->setStart(Point(170,270));
ls->setEnd(Point(170,220));

speciesReferenceGlyph=&glyph_PFK->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_03");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_F6P->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_F6P_2->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_SUBSTRATE);

ls=&speciesReferenceGlyph->createLineSegment();
ls->setStart(Point(170,440));
ls->setEnd(Point(170,390));

speciesReferenceGlyph=&glyph_Aldolase->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_04");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_F16BP->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_F16BP_2->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_SUBSTRATE);

ls=&speciesReferenceGlyph->createLineSegment();
ls->setStart(Point(170,610));
ls->setEnd(Point(170,560));

speciesReferenceGlyph=&glyph_GAPDeh->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_05");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_GAP->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_GAP_3->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_SUBSTRATE);

ls=&speciesReferenceGlyph->createLineSegment();
ls->setStart(Point(170,780));
ls->setEnd(Point(170,730));

speciesReferenceGlyph=&glyph_PGK->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_06");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_BPG->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_BPG_2->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_SUBSTRATE);

ls=&speciesReferenceGlyph->createLineSegment();
ls->setStart(Point(170,950));
ls->setEnd(Point(170,900));

speciesReferenceGlyph=&glyph_PGM->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_07");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_3PG->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_3PG_2->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_SUBSTRATE);

ls=&speciesReferenceGlyph->createLineSegment();
ls->setStart(Point(170,1120));
ls->setEnd(Point(170,1070));

speciesReferenceGlyph=&glyph_Enolase->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_08");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_2PG->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_2PG_2->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_SUBSTRATE);

ls=&speciesReferenceGlyph->createLineSegment();
ls->setStart(Point(170,1290));
ls->setEnd(Point(170,1240));

speciesReferenceGlyph=&glyph_PK->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_09");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_PEP->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_PEP_2->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_SUBSTRATE);

ls=&speciesReferenceGlyph->createLineSegment();
ls->setStart(Point(170,1460));
ls->setEnd(Point(170,1410));

speciesReferenceGlyph=&glyph_TPI->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_10");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_DHAP->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_DHAP_1->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_SUBSTRATE);

CubicBezier* cb=&speciesReferenceGlyph->createCubicBezier();
cb->setStart(Point(515,700));
cb->setBasePoint1(Point(535,680));
cb->setBasePoint2(Point(535,680));
cb->setEnd(Point(535,625));

// the main products
speciesReferenceGlyph=&glyph_Hexokinase->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_11");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_G6P->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_G6P_1->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_PRODUCT);

ls=&speciesReferenceGlyph->createLineSegment();
ls->setStart(Point(170,130));
ls->setEnd(Point(170,180));

speciesReferenceGlyph=&glyph_PGIsomerase->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_12");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_F6P->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_F6P_1->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_PRODUCT);

ls=&speciesReferenceGlyph->createLineSegment();
ls->setStart(Point(170,300));
ls->setEnd(Point(170,350));

speciesReferenceGlyph=&glyph_PFK->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_13");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_F16BP->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_F16BP_1->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_PRODUCT);

ls=&speciesReferenceGlyph->createLineSegment();
ls->setStart(Point(170,470));
ls->setEnd(Point(170,520));

speciesReferenceGlyph=&glyph_Aldolase->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_14");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_GAP->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_GAP_1->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_PRODUCT);

ls=&speciesReferenceGlyph->createLineSegment();
ls->setStart(Point(170,640));
ls->setEnd(Point(170,690));

speciesReferenceGlyph=&glyph_Aldolase->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_15");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_DHAP->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_DHAP_2->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_PRODUCT);

cb=&speciesReferenceGlyph->createCubicBezier();
cb->setStart(Point(170,640));
cb->setBasePoint1(Point(270,700));
cb->setBasePoint2(Point(270,605));
cb->setEnd(Point(370,605));

speciesReferenceGlyph=&glyph_GAPDeh->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_16");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_BPG->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_BPG_1->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_PRODUCT);

ls=&speciesReferenceGlyph->createLineSegment();
ls->setStart(Point(170,810));
ls->setEnd(Point(170,860));

speciesReferenceGlyph=&glyph_PGK->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_17");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_3PG->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_3PG_1->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_PRODUCT);

ls=&speciesReferenceGlyph->createLineSegment();
ls->setStart(Point(170,980));
ls->setEnd(Point(170,1030));

speciesReferenceGlyph=&glyph_PGM->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_18");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_2PG->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_2PG_1->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_PRODUCT);

ls=&speciesReferenceGlyph->createLineSegment();
ls->setStart(Point(170,1150));
ls->setEnd(Point(170,1200));

speciesReferenceGlyph=&glyph_Enolase->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_19");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_PEP->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_PEP_1->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_PRODUCT);

ls=&speciesReferenceGlyph->createLineSegment();
ls->setStart(Point(170,1320));
ls->setEnd(Point(170,1370));

speciesReferenceGlyph=&glyph_PK->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_20");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_Pyr->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_Pyr_1->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_PRODUCT);

ls=&speciesReferenceGlyph->createLineSegment();
ls->setStart(Point(170,1490));
ls->setEnd(Point(170,1540));

speciesReferenceGlyph=&glyph_TPI->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_21");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_GAP->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_GAP_2->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_PRODUCT);

cb=&speciesReferenceGlyph->createCubicBezier();
cb->setStart(Point(515,700));
cb->setBasePoint1(Point(505,710));
cb->setBasePoint2(Point(505,710));
cb->setEnd(Point(370,710));


// sidesubstrates and products

// hexokinase
speciesReferenceGlyph=&glyph_Hexokinase->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_22");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_ATP_1->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_ATP_1->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_SIDESUBSTRATE);

cb=&speciesReferenceGlyph->createCubicBezier();
cb->setStart(Point(170,100));
cb->setBasePoint1(Point(170,80));
cb->setBasePoint2(Point(170,80));
cb->setEnd(Point(260,80));

speciesReferenceGlyph=&glyph_Hexokinase->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_23");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_ADP_1->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_ADP_1->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_SIDEPRODUCT);

cb=&speciesReferenceGlyph->createCubicBezier();
cb->setStart(Point(170,130));
cb->setBasePoint1(Point(170,150));
cb->setBasePoint2(Point(170,150));
cb->setEnd(Point(260,150));

// PFK
speciesReferenceGlyph=&glyph_PFK->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_24");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_ATP_2->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_ATP_2->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_SIDESUBSTRATE);

cb=&speciesReferenceGlyph->createCubicBezier();
cb->setStart(Point(170,440));
cb->setBasePoint1(Point(170,420));
cb->setBasePoint2(Point(170,420));
cb->setEnd(Point(260,420));

speciesReferenceGlyph=&glyph_PFK->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_24");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_ADP_2->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_ADP_2->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_SIDEPRODUCT);

cb=&speciesReferenceGlyph->createCubicBezier();
cb->setStart(Point(170,470));
cb->setBasePoint1(Point(170,490));
cb->setBasePoint2(Point(170,490));
cb->setEnd(Point(260,490));

// GAP Dehydrogenase
speciesReferenceGlyph=&glyph_GAPDeh->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_25");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_NAD_1->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_NAD_1->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_SIDESUBSTRATE);

cb=&speciesReferenceGlyph->createCubicBezier();
cb->setStart(Point(170,780));
cb->setBasePoint1(Point(170,760));
cb->setBasePoint2(Point(170,760));
cb->setEnd(Point(260,760));

speciesReferenceGlyph=&glyph_GAPDeh->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_26");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_NADH_1->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_NADH_1->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_SIDEPRODUCT);

cb=&speciesReferenceGlyph->createCubicBezier();
cb->setStart(Point(170,810));
cb->setBasePoint1(Point(170,830));
cb->setBasePoint2(Point(170,830));
cb->setEnd(Point(260,830));

// PGK
speciesReferenceGlyph=&glyph_PGK->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_27");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_ADP_3->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_ADP_3->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_SIDESUBSTRATE);

cb=&speciesReferenceGlyph->createCubicBezier();
cb->setStart(Point(170,950));
cb->setBasePoint1(Point(170,930));
cb->setBasePoint2(Point(170,930));
cb->setEnd(Point(260,930));

speciesReferenceGlyph=&glyph_PGK->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_28");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_ATP_3->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_ATP_3->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_SIDEPRODUCT);

cb=&speciesReferenceGlyph->createCubicBezier();
cb->setStart(Point(170,980));
cb->setBasePoint1(Point(170,1000));
cb->setBasePoint2(Point(170,1000));
cb->setEnd(Point(260,1000));

//Enolase
speciesReferenceGlyph=&glyph_Enolase->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_29");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_H2O_1->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_H2O_1->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_SIDEPRODUCT);

cb=&speciesReferenceGlyph->createCubicBezier();
cb->setStart(Point(170,1320));
cb->setBasePoint1(Point(170,1360));
cb->setBasePoint2(Point(170,1360));
cb->setEnd(Point(260,1360));

// PK
speciesReferenceGlyph=&glyph_PK->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_30");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_ADP_4->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_ADP_4->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_SIDESUBSTRATE);

cb=&speciesReferenceGlyph->createCubicBezier();
cb->setStart(Point(170,1460));
cb->setBasePoint1(Point(170,1440));
cb->setBasePoint2(Point(170,1440));
cb->setEnd(Point(260,1440));

speciesReferenceGlyph=&glyph_PK->createSpeciesReferenceGlyph();
speciesReferenceGlyph->setId("SpeciesReferenceGlyph_31");
speciesReferenceGlyph->setSpeciesGlyphId(glyph_ATP_4->getId());
speciesReferenceGlyph->setSpeciesReferenceId(reference_ATP_4->getId());
speciesReferenceGlyph->setRole(SPECIES_ROLE_SIDEPRODUCT);

cb=&speciesReferenceGlyph->createCubicBezier();
cb->setStart(Point(170,1490));
cb->setBasePoint1(Point(170,1530));
cb->setBasePoint2(Point(170,1530));
cb->setEnd(Point(260,1530));


writeSBML(document,"GlycolysisModel-g++.xml");
delete document;

}
