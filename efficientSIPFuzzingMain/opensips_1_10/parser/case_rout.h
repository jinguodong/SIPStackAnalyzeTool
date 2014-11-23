/* 
 * $Id$ 
 *
 * Route Header Field Name Parsing Macros
 *
 * Copyright (C) 2001-2003 FhG Fokus
 *
 * This file is part of opensips, a free SIP server.
 *
 * opensips is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * opensips is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software 
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */


#ifndef CASE_ROUT_H
#define CASE_ROUT_H


#define rout_CASE                    \
	p += 4;                          \
	switch(LOWER_BYTE(*p)) {         \
		case 'e':                    \
			hdr->type = HDR_ROUTE_T; \
			hdr->name.len = 5;       \
			p++;                     \
			goto dc_cont;            \
		default:                     \
			goto other;              \
	}


#endif /* CASE_ROUT_H */
