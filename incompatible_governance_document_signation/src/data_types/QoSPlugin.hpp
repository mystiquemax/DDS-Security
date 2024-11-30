

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from QoS.idl
using RTI Code Generator (rtiddsgen) version 4.2.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef QoSPlugin_2129333519_h
#define QoSPlugin_2129333519_h

#include "QoS.hpp"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

namespace Types {

    #define InformationPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define InformationPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define InformationPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define InformationPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define InformationPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern Information*
    InformationPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern Information*
    InformationPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Information*
    InformationPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    InformationPluginSupport_copy_data(
        Information *out,
        const Information *in);

    NDDSUSERDllExport extern void 
    InformationPluginSupport_destroy_data_w_params(
        Information *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    InformationPluginSupport_destroy_data_ex(
        Information *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    InformationPluginSupport_destroy_data(
        Information *sample);

    NDDSUSERDllExport extern void 
    InformationPluginSupport_print_data(
        const Information *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    InformationPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    InformationPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    InformationPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    InformationPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    InformationPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        Information *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    InformationPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        Information *out,
        const Information *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    InformationPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Information *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    InformationPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        Information **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    InformationPlugin_deserialize_from_cdr_buffer(
        Information *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    InformationPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    InformationPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    InformationPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    InformationPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    InformationPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Information ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    InformationPlugin_new(void);

    NDDSUSERDllExport extern void
    InformationPlugin_delete(struct PRESTypePlugin *);

} /* namespace Types  */
namespace Smth {

    #define Not_SecretPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define Not_SecretPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define Not_SecretPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define Not_SecretPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define Not_SecretPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern Not_Secret*
    Not_SecretPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern Not_Secret*
    Not_SecretPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Not_Secret*
    Not_SecretPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    Not_SecretPluginSupport_copy_data(
        Not_Secret *out,
        const Not_Secret *in);

    NDDSUSERDllExport extern void 
    Not_SecretPluginSupport_destroy_data_w_params(
        Not_Secret *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    Not_SecretPluginSupport_destroy_data_ex(
        Not_Secret *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    Not_SecretPluginSupport_destroy_data(
        Not_Secret *sample);

    NDDSUSERDllExport extern void 
    Not_SecretPluginSupport_print_data(
        const Not_Secret *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    Not_SecretPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    Not_SecretPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    Not_SecretPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    Not_SecretPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    Not_SecretPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        Not_Secret *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    Not_SecretPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        Not_Secret *out,
        const Not_Secret *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    Not_SecretPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Not_Secret *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    Not_SecretPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        Not_Secret **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Not_SecretPlugin_deserialize_from_cdr_buffer(
        Not_Secret *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    Not_SecretPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Not_SecretPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Not_SecretPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Not_SecretPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Not_SecretPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Not_Secret ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    Not_SecretPlugin_new(void);

    NDDSUSERDllExport extern void
    Not_SecretPlugin_delete(struct PRESTypePlugin *);

} /* namespace Smth  */

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* QoSPlugin_2129333519_h */

