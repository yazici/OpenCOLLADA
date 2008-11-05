/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAFramework.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_POLY_BASE_H__
#define __COLLADAFW_POLY_BASE_H__

#include "COLLADAFWInputShared.h"


namespace COLLADAFW
{

    /**
    * The Polylist element provides the information needed to bind vertex attributes
    * together and  then organize those vertices into individual polygons. The
    * polygons described in Polylist can  contain arbitrary numbers of vertices.
    * Unlike the polygons element, the Polylist element cannot  contain polygons
    * with holes.
    */
    class PolyBase 
    {

    public:

        /** The array of primitives. */
        typedef unsigned int* PArray;

    private:

        /**
        * The name attribute is the text string name of this element. 
        * Optional attribute.
        */
        String mName;

        /**
        * The count attribute indicates the number of polygon primitives. 
        * Required attribute. 
        */
        size_t mCount;

        /**
        * The material attribute declares a symbol for a material. This symbol 
        * is bound to a material at  the time of instantiation. If the material 
        * attribute is not specified then the lighting and  shading results are 
        * application defined. Optional attribute. 
        */
        String mMaterial;

        /**
        * Contains a array of integers that specify the vertex attributes
        * (indices) for an individual Polylist. (�p� stands for �primitive�.)
        * The p element may occur once. 
        */
        PArray mPArray;

        /** 
         * Contains the number of primitives in the @mPArray array. 
         */
        size_t mPArraySize;

        /**
        * The input element may occur any number of times. This input is a local
        * input with the  offset and set attributes. 
        */
        InputSharedArray mInputArray;

        /**
         * Contains the number of input elements in the @mInputArray array.
         */
        size_t mInputArraySize;

    public:	

        /**
        * Constructor
        */
        PolyBase () 
            : mName ()
            , mCount ()
            , mMaterial ()
            , mPArray ( 0 )
            , mPArraySize ( 0 )
            , mInputArray ( 0 )
            , mInputArraySize ( 0 ) 
        {}

        /**
        * Destructor
        */
        virtual ~PolyBase() 
        {
            delete[] mPArray;
            delete[] mInputArray;
        }

        /**
        * Gets the name attribute.
        * @return Returns a xsNCName of the name attribute.
        */
        const String& getName () const { return mName; }

        /**
        * Sets the name attribute.
        * @param atName The new value for the name attribute.
        */
        void setName ( const String& name ) { mName = name; }

        /**
        * Gets the count attribute.
        * @return Returns a domUint of the count attribute.
        */
        size_t getCount () const { return mCount; }

        /**
        * Sets the count attribute.
        * @param atCount The new value for the count attribute.
        */
        void setCount ( size_t count ) { mCount = count; }

        /**
        * Gets the material attribute.
        * @return Returns a xsNCName of the material attribute.
        */
        String getMaterial () const { return mMaterial; }

        /**
        * Sets the material attribute.
        * @param atMaterial The new value for the material attribute.
        */
        void setMaterial ( const String& material ) { mMaterial = material; }

        /**
         * The input element may occur any number of times. This input is a 
         * local input with the  offset and set attributes.
         * @param inputArraySize Parameter to get the size of the array.
         * @return const InputArray The array with the input elements.
         */
        const InputSharedArray& getInputArray ( size_t& inputArraySize ) const 
        {
            inputArraySize = mInputArraySize;
            return mInputArray; 
        }

        /**
         * The input element may occur any number of times. This input is a 
         * local input with the  offset and set attributes.
         * @param inputArray The array with the input elements.
         * @param inputArraySize The size of the input array.
         */
        void setInputArray ( const InputSharedArray& inputArray, const size_t inputArraySize ) 
        { 
            mInputArraySize = inputArraySize;
            mInputArray = inputArray; 
        }

        /**
        * Gets the p array array. The pArray contains a array of integers that  
        * specify the vertex attributes (indices) for an individual Polylist. 
        * ("p" stands for "primitive".)
        * @param pArraySize Parameter to get the number of primitives in the array.
        * @return A Pointer to the p array array. See @mPArray
        */
        const PArray& getPArray ( size_t& pArraySize ) const 
        {
            pArraySize = mPArraySize;
            return mPArray; 
        }

        /**
         * Sets the p array. The pArray contains a array of integers that specify 
         * the vertex attributes (indices) for an individual Polylist. 
         * ("p" stands for "primitive".)
         * @param pArray A Pointer to the p array array. See @mPArray.
         * @param pArraySize The number of primitives in the @mPArray array.
         */
        void setPArray ( const PArray& pArray, size_t pArraySize ) 
        { 
            mPArray = pArray; 
            mPArraySize = pArraySize;
        }

    };

}

#endif // __COLLADAFW_POLY_BASE_H__
