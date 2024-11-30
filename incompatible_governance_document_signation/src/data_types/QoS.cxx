

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from QoS.idl
using RTI Code Generator (rtiddsgen) version 4.2.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#include <iosfwd>
#include <iomanip>

#ifndef NDDS_STANDALONE_TYPE
#include "rti/topic/cdr/Serialization.hpp"
#include "QoSPlugin.hpp"
#else
#include "rti/topic/cdr/SerializationHelpers.hpp"
#endif

#include "QoS.hpp"

#include <rti/util/ostream_operators.hpp>

namespace Types {

    // ---- Information: 

    Information::Information() :
        m_Data_ (0)  {

    }   

    Information::Information (int16_t Data_):
        m_Data_(Data_) {
    }

    void Information::swap(Information& other_)  noexcept 
    {
        using std::swap;
        swap(m_Data_, other_.m_Data_);
    }  

    bool Information::operator == (const Information& other_) const {
        if (m_Data_ != other_.m_Data_) {
            return false;
        }
        return true;
    }

    bool Information::operator != (const Information& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const Information& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "Data: " << sample.Data ();
        o <<"]";
        return o;
    }

} // namespace Types  

namespace Smth {

    // ---- Not_Secret: 

    Not_Secret::Not_Secret() :
        m_Data_ (0)  {

    }   

    Not_Secret::Not_Secret (int16_t Data_):
        m_Data_(Data_) {
    }

    void Not_Secret::swap(Not_Secret& other_)  noexcept 
    {
        using std::swap;
        swap(m_Data_, other_.m_Data_);
    }  

    bool Not_Secret::operator == (const Not_Secret& other_) const {
        if (m_Data_ != other_.m_Data_) {
            return false;
        }
        return true;
    }

    bool Not_Secret::operator != (const Not_Secret& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const Not_Secret& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "Data: " << sample.Data ();
        o <<"]";
        return o;
    }

} // namespace Smth  

#ifdef NDDS_STANDALONE_TYPE
namespace rti {
    namespace topic {
    }
}

#else
// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        template<>
        struct native_type_code< ::Types::Information > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member Information_g_tc_members[1]=
                {

                    {
                        (char *)"Data",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode Information_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Types::Information", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        Information_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for Information*/

                if (is_initialized) {
                    return &Information_g_tc;
                }

                is_initialized = RTI_TRUE;

                Information_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                Information_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

                /* Initialize the values for member annotations. */
                Information_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_SHORT;
                Information_g_tc_members[0]._annotations._defaultValue._u.short_value = 0;
                Information_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_SHORT;
                Information_g_tc_members[0]._annotations._minValue._u.short_value = RTIXCdrShort_MIN;
                Information_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_SHORT;
                Information_g_tc_members[0]._annotations._maxValue._u.short_value = RTIXCdrShort_MAX;

                Information_g_tc._data._sampleAccessInfo = sample_access_info();
                Information_g_tc._data._typePlugin = type_plugin_info();    

                return &Information_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::Types::Information *sample;

                static RTIXCdrMemberAccessInfo Information_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo Information_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &Information_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::Types::Information);
                if (sample == NULL) {
                    return NULL;
                }

                Information_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Data() - (char *)sample);

                Information_g_sampleAccessInfo.memberAccessInfos = 
                Information_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::Types::Information);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        Information_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        Information_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                Information_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                Information_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::Types::Information >;

                Information_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &Information_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin Information_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &Information_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::Types::Information >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::Types::Information >::get())));
        }

        template<>
        struct native_type_code< ::Smth::Not_Secret > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member Not_Secret_g_tc_members[1]=
                {

                    {
                        (char *)"Data",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode Not_Secret_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Smth::Not_Secret", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        Not_Secret_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for Not_Secret*/

                if (is_initialized) {
                    return &Not_Secret_g_tc;
                }

                is_initialized = RTI_TRUE;

                Not_Secret_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                Not_Secret_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

                /* Initialize the values for member annotations. */
                Not_Secret_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_SHORT;
                Not_Secret_g_tc_members[0]._annotations._defaultValue._u.short_value = 0;
                Not_Secret_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_SHORT;
                Not_Secret_g_tc_members[0]._annotations._minValue._u.short_value = RTIXCdrShort_MIN;
                Not_Secret_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_SHORT;
                Not_Secret_g_tc_members[0]._annotations._maxValue._u.short_value = RTIXCdrShort_MAX;

                Not_Secret_g_tc._data._sampleAccessInfo = sample_access_info();
                Not_Secret_g_tc._data._typePlugin = type_plugin_info();    

                return &Not_Secret_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::Smth::Not_Secret *sample;

                static RTIXCdrMemberAccessInfo Not_Secret_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo Not_Secret_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &Not_Secret_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::Smth::Not_Secret);
                if (sample == NULL) {
                    return NULL;
                }

                Not_Secret_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Data() - (char *)sample);

                Not_Secret_g_sampleAccessInfo.memberAccessInfos = 
                Not_Secret_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::Smth::Not_Secret);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        Not_Secret_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        Not_Secret_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                Not_Secret_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                Not_Secret_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::Smth::Not_Secret >;

                Not_Secret_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &Not_Secret_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin Not_Secret_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &Not_Secret_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::Smth::Not_Secret >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::Smth::Not_Secret >::get())));
        }
    }
}

namespace dds { 
    namespace topic {
        void topic_type_support< ::Types::Information >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::Types::InformationPlugin_new,
                ::Types::InformationPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::Types::Information >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::Types::Information& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = InformationPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = InformationPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::Types::Information >::from_cdr_buffer(::Types::Information& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = InformationPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::Types::Information from cdr buffer");
        }

        void topic_type_support< ::Types::Information >::reset_sample(::Types::Information& sample) 
        {
            sample.Data(0);
        }

        void topic_type_support< ::Types::Information >::allocate_sample(::Types::Information& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }
        void topic_type_support< ::Smth::Not_Secret >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::Smth::Not_SecretPlugin_new,
                ::Smth::Not_SecretPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::Smth::Not_Secret >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::Smth::Not_Secret& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = Not_SecretPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = Not_SecretPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::Smth::Not_Secret >::from_cdr_buffer(::Smth::Not_Secret& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = Not_SecretPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::Smth::Not_Secret from cdr buffer");
        }

        void topic_type_support< ::Smth::Not_Secret >::reset_sample(::Smth::Not_Secret& sample) 
        {
            sample.Data(0);
        }

        void topic_type_support< ::Smth::Not_Secret >::allocate_sample(::Smth::Not_Secret& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }
    }
}  

#endif // NDDS_STANDALONE_TYPE
