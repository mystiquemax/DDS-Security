

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from QoS.idl
using RTI Code Generator (rtiddsgen) version 4.2.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef QoS_2129333531_hpp
#define QoS_2129333531_hpp

#include <iosfwd>

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport __declspec(dllexport)
#endif

#include "dds/core/SafeEnumeration.hpp"
#include "dds/core/String.hpp"
#include "dds/core/array.hpp"
#include "dds/core/vector.hpp"
#include "dds/core/External.hpp"
#include "rti/core/LongDouble.hpp"
#include "rti/core/Pointer.hpp"
#include "rti/core/array.hpp"
#include "rti/topic/TopicTraits.hpp"

#include "omg/types/string_view.hpp"

#include "rti/core/BoundedSequence.hpp"
#include "dds/core/Optional.hpp"

#ifndef NDDS_STANDALONE_TYPE
#include "dds/domain/DomainParticipant.hpp"
#include "dds/topic/TopicTraits.hpp"
#include "dds/core/xtypes/DynamicType.hpp"
#include "dds/core/xtypes/StructType.hpp"
#include "dds/core/xtypes/UnionType.hpp"
#include "dds/core/xtypes/EnumType.hpp"
#include "dds/core/xtypes/AliasType.hpp"
#include "rti/util/StreamFlagSaver.hpp"
#include "rti/domain/PluginSupport.hpp"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

namespace Types {

    class NDDSUSERDllExport Information {
      public:

        Information();

        explicit Information(int16_t Data_);

        int16_t& Data() noexcept {
            return m_Data_;
        }

        const int16_t& Data() const noexcept {
            return m_Data_;
        }

        void Data(int16_t value) {

            m_Data_ = value;
        }

        bool operator == (const Information& other_) const;
        bool operator != (const Information& other_) const;

        void swap(Information& other_) noexcept ;

      private:

        int16_t m_Data_;

    };

    inline void swap(Information& a, Information& b)  noexcept 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Information& sample);

} // namespace Types  
namespace Not_Secret {

    class NDDSUSERDllExport Not_Secret {
      public:

        Not_Secret();

        explicit Not_Secret(int16_t Data_);

        int16_t& Data() noexcept {
            return m_Data_;
        }

        const int16_t& Data() const noexcept {
            return m_Data_;
        }

        void Data(int16_t value) {

            m_Data_ = value;
        }

        bool operator == (const Not_Secret& other_) const;
        bool operator != (const Not_Secret& other_) const;

        void swap(Not_Secret& other_) noexcept ;

      private:

        int16_t m_Data_;

    };

    inline void swap(Not_Secret& a, Not_Secret& b)  noexcept 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Not_Secret& sample);

} // namespace Not_Secret  

#ifdef NDDS_STANDALONE_TYPE
namespace rti { 
    namespace topic {
    }
}
#else

namespace rti {
    namespace flat {
        namespace topic {
        }
    }
}
namespace dds {
    namespace topic {

        template<>
        struct topic_type_name< ::Types::Information > {
            NDDSUSERDllExport static std::string value() {
                return "Types::Information";
            }
        };

        template<>
        struct is_topic_type< ::Types::Information > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::Types::Information > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::Types::Information& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::Types::Information& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::Types::Information& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::Types::Information& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::Not_Secret::Not_Secret > {
            NDDSUSERDllExport static std::string value() {
                return "Not_Secret::Not_Secret";
            }
        };

        template<>
        struct is_topic_type< ::Not_Secret::Not_Secret > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::Not_Secret::Not_Secret > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::Not_Secret::Not_Secret& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::Not_Secret::Not_Secret& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::Not_Secret::Not_Secret& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::Not_Secret::Not_Secret& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
    }
}

namespace rti { 
    namespace topic {

        template<>
        struct dynamic_type< ::Types::Information > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::Types::Information > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::Not_Secret::Not_Secret > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::Not_Secret::Not_Secret > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

    }
}

#endif // NDDS_STANDALONE_TYPE
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // QoS_2129333531_hpp

