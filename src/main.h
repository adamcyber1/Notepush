/*
 * This file is part of Notepush.
 * 
 * See the COPYRIGHT file at the top-level directory of this distribution
 * for details of code ownership.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef PROJECT_MAIN_H
#define PROJECT_MAIN_H

static const char *const HEADER = "\nnotepush - Adam F.\n\n";
static const char *const USAGE = "Usage:\n"
                                 "\tpsh -r #reset the config\n"
                                 "\tpsh Some notes I want committed to a local repo @topic1 @topic2\n"
                                 "\tpsh -o Some notes I want committed and pushed to a remote @topic1 @topic2\n"
                                 "\n\n"
                                 "Description:\n"
                                 "\tA note taking utility that leverages git source control to organize notes."
                                 "\n\n"
                                 "Options:\n"
                                 "\t-r      Reset the config.\n"
                                 "\t-o      Run in online mode.\n"
                                 ;

#endif //PROJECT_MAIN_H