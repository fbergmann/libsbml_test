%
% These are the functions to import and export an SBML model into a MATLAB 
% structure and back to an SBML file.
%
% FUNCTIONS include:
%
% TranslateSBML(varargin)
%
% - translates a sbml file into a matlab structure
%    NOTE: this executable must be built in most environments
%    (see README.txt)
%
% OutputSBML(varargin)
%
% - translates a appropriate matlab structure back into sbml and writes
%   out the file
%    NOTE: this executable must be built in most environments
%    (see README.txt)
%
% CheckAndConvert.m
%
% - a script used by TranslateSBML to change some mathematical function names
%   to those used by MATLAB
%
% ConvertFormulaToMathML.m
%
% - a script used by OutputSBML to change some mathematical function names
%   to those used by MathML
%
% isSBML_Model.m
%
% - a script used by OutputSBML to check that a structure is an appropriate
%   MATLAB-SBML structure for conversion to SBML
%
% isoctave.m
%
% - a script to determine if octave or matlab is being used
%
% buildWin 
%
% - builds the TranslateSBML/OutputSBML executables in the Windows environment
%
% install_Win32
% install_Win64
% uninstall_Win32
% uninstall_Win64
%
% - installs/uninstalls the appropriate libraries in the Windows environment
%

%  Description : This is the binding to translate 
%				 sbml models into a MATLAB structure 
%  Author(s)   : SBML Team <sbml-team@caltech.edu>
%  Organization: University of Hertfordshire STRC
%  Created     : 2003-09-15
%  Revision    : $Id$
%  $HeadURL$
%
%  Copyright 2003 California Institute of Technology, the Japan Science
%  and Technology Corporation, and the University of Hertfordshire
%
%  This library is free software; you can redistribute it and/or modify it
%  under the terms of the GNU Lesser General Public License as published
%  by the Free Software Foundation; either version 2.1 of the License, or
%  any later version.
%
%  This library is distributed in the hope that it will be useful, but
%  WITHOUT ANY WARRANTY, WITHOUT EVEN THE IMPLIED WARRANTY OF
%  MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.  The software and
%  documentation provided hereunder is on an "as is" basis, and the
%  California Institute of Technology, the Japan Science and Technology
%  Corporation, and the University of Hertfordshire have no obligations to
%  provide maintenance, support, updates, enhancements or modifications.  In
%  no event shall the California Institute of Technology, the Japan Science
%  and Technology Corporation or the University of Hertfordshire be liable
%  to any party for direct, indirect, special, incidental or consequential
%  damages, including lost profits, arising out of the use of this software
%  and its documentation, even if the California Institute of Technology
%  and/or Japan Science and Technology Corporation and/or University of
%  Hertfordshire have been advised of the possibility of such damage.  See
%  the GNU Lesser General Public License for more details.
%
%  You should have received a copy of the GNU Lesser General Public License
%  along with this library; if not, write to the Free Software Foundation,
%  Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
%
%  The original code contained here was initially developed by:
%
%      Sarah Keating
%      Science and Technology Research Centre
%      University of Hertfordshire
%      Hatfield, AL10 9AB
%      United Kingdom
%
%      http://www.sbml.org
%      mailto:sbml-team@caltech.edu
%
%  Contributor(s):
%
%
%
