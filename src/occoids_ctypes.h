/*
 *	occoids_ctypes.h -- C/CUDA types for occoids (GPU version)
 *	Copyright (C) 2013,2017 Fred Barnes <F.R.M.Barnes@gmail.com>
 *
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __OCCOIDS_CTYPES_H
#define __OCCOIDS_CTYPES_H

/*
 * XXX: these must match up with the various structures in gpuboids_params.inc
 */

struct TAG_vector {
	float x;
	float y;
	float z;
	float dummy;
} __attribute__ ((packed, aligned(4)));

typedef struct TAG_vector vector_t;

struct TAG_agent_info {
	int type_id;
	int locn;
	vector_t pos;
	vector_t vel;
	float radius;
	int colour;
} __attribute__ ((packed, aligned(4)));

typedef struct TAG_agent_info agent_info_t;

struct TAG_genparms {
	float cmfrac;			/* centre-of-mass fraction */
	float rdist, rdist_sq;		/* repulsion distance */
	float rfrac;			/* repulsion fraction */
	float mvfrac;			/* mean-velocity fraction */
	float vrad, vrad_sq;		/* vision radius */
	float vmaxdiff;			/* vision max angular difference */
	float epsilon;			/* threshold for not moving */
	float sthres;			/* soft threshold for obstacles */
	float ofrac;			/* obstacle fraction */
	float slimit, slimit_sq;	/* speed limit */
	float saccel;			/* smooth acceleration */

	int width;			/* grid width */
	int height;			/* grid height */
	int maxagents;			/* maximum number of agents */
	int viewsize;			/* size of shared viewable array in elements */
	int vperboid;			/* view-size per boid (num-locations * vperboid = viewsize) */
	int nloc;			/* number of locations */
	int ndir;			/* number of directions */
	int depth;			/* grid depth (3D version) */
} __attribute__ ((packed, aligned(4)));

typedef struct TAG_genparms genparms_t;



#endif	/* !__OCCOIDS_CTYPES_H */

