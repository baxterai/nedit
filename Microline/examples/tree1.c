/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 *
 * ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 * 
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 * 
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 * 
 * The Original Code is the Microline Widget Library, originally made available
 * under the NPL by Neuron Data <http://www.neurondata.com>.
 * 
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 1998
 * the Initial Developer. All Rights Reserved.
 * 
 * Contributor(s):
 * 
 * Alternatively, the contents of this file may be used under the terms of
 * either of the GNU General Public License Version 2 or later (the "GPL"),
 * or the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 * 
 * ***** END LICENSE BLOCK ***** */


#include <Xm/Xm.h>
#include <XmL/Tree.h>

main(argc, argv)
int argc;
char *argv[];
{
	XtAppContext app;
	Widget shell, tree;
	Pixmap pixmap, pixmask;
	XmString str;

	shell =  XtAppInitialize(&app, "Tree1", NULL, 0,
		&argc, argv, NULL, NULL, 0);

	tree = XtVaCreateManagedWidget("tree",
		xmlTreeWidgetClass, shell,
		XmNvisibleRows, 10,
		XmNwidth, 250,
		NULL);

	XtVaSetValues(tree,
		XmNlayoutFrozen, True,
		NULL);

	pixmap = XmUNSPECIFIED_PIXMAP;
	pixmask = XmUNSPECIFIED_PIXMAP;

	str = XmStringCreateSimple("Root");
	XmLTreeAddRow(tree, 0, True, True, -1, pixmap, pixmask, str);
	XmStringFree(str);
	str = XmStringCreateSimple("Level 1 Parent");
	XmLTreeAddRow(tree, 1, True, True, -1, pixmap, pixmask, str);
	XmStringFree(str);
	str = XmStringCreateSimple("1st Child of Level 1 Parent");
	XmLTreeAddRow(tree, 2, False, False, -1, pixmap, pixmask, str);
	XmStringFree(str);
	str = XmStringCreateSimple("2nd Child of Level 1 Parent");
	XmLTreeAddRow(tree, 2, False, False, -1, pixmap, pixmask, str);
	XmStringFree(str);
	str = XmStringCreateSimple("Level 2 Parent");
	XmLTreeAddRow(tree, 2, True, True, -1, pixmap, pixmask, str);
	XmStringFree(str);
	str = XmStringCreateSimple("Child of Level 2 Parent");
	XmLTreeAddRow(tree, 3, False, False, -1, pixmap, pixmask, str);
	XmStringFree(str);
	str = XmStringCreateSimple("Level 1 Parent");
	XmLTreeAddRow(tree, 1, True, True, -1, pixmap, pixmask, str);
	XmStringFree(str);
	str = XmStringCreateSimple("Child of Level 1 Parent");
	XmLTreeAddRow(tree, 2, False, False, -1, pixmap, pixmask, str);
	XmStringFree(str);

	XtVaSetValues(tree,
		XmNlayoutFrozen, False,
		NULL);

	XtRealizeWidget(shell);
	XtAppMainLoop(app);
}