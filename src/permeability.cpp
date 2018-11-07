/*
 *   Copyright (C) 2018 João Netto <joaonetto901@gmail.com>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU Library General Public License as
 *   published by the Free Software Foundation; either version 2, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details
 *
 *   You should have received a copy of the GNU Library General Public
 *   License along with this program; if not, write to the
 *   Free Software Foundation, Inc.,
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */


#include "permeability_p.h"
#include "unit_p.h"

#include <KI18n/klocalizedstring.h>

namespace KUnitConversion
{

Permeability::Permeability() : CustomCategory(PermeabilityCategory, i18n("Permeability"), i18n("Permeability"))
{
    KLocalizedString symbolString = ki18nc("%1 value, %2 unit symbol (permeability)", "%1 %2");

    addDefaultUnit(CustomUnit(PermeabilityCategory, Darcy, 1,
                             i18nc("volume unit symbol", "Darcy"),
                             i18nc("unit description in lists", "Darcy"),
                             i18nc("unit synonyms for matching user input",
                                   "Darcy;Darcys;Dar;Darc"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 Darcy"),
                             ki18ncp("amount in units (integer)", "%1 Darcy", "%1 Darcys")));

    addCommonUnit(CustomUnit(PermeabilityCategory, MiliDarcy, 0.001,
                             i18nc("volume unit symbol", "mDarcy"),
                             i18nc("unit description in lists", "Milli-Darcy"),
                             i18nc("unit synonyms for matching user input",
                                   "Milli-Darcy;MilliDarcy;MilliDar;mDarcy;mDar;mDarc"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 Milli-Darcy"),
                             ki18ncp("amount in units (integer)", "%1 Milli-Darcy", "%1 Milli-Darcys")));

    addCommonUnit(CustomUnit(PermeabilityCategory, PermeabilitySquareMicrometer, 0.9869233,
                             i18nc("volume unit symbol", "µm²"),
                             i18nc("unit description in lists", "squaremicrometers"),
                             i18nc("unit synonyms for matching user input",
                                   "Permeability;Pµm²;PSquare µm;squaremicrometers;Pµm^2"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 micrometers²"),
                             ki18ncp("amount in units (integer)", "%1 micrometer²", "%1 micrometers²")));


}

} // KUnitConversion namespace